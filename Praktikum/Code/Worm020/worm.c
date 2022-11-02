// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// ********************************************************************************************
// Constants, data structures
// ********************************************************************************************

// Result codes of functions
enum ResCodes{
  RES_OK,
  RES_FAILED
};

// Codes for the array of positions
// Unused element in the worm arrays of positions
#define UNUSED_POS_ELEM -1

// Dimensions and bounds
#define NAP_TIME    100   // Time in milliseconds to sleep between updates of display
#define MIN_NUMBER_OF_ROWS  3   // The guaranteed number of rows available for the board
#define MIN_NUMBER_OF_COLS 10   // The guaranteed number of columns available for the board
#define WORM_LENGTH 20    //Maximal length of the worm

// Numbers for color pairs used by curses macro COLOR_PAIR
enum ColorPairs{
  COLP_USER_WORM = 1,
  COLP_FREE_CELL,
};
// Symbols to display
#define SYMBOL_WORM_INNER_ELEMENT '0'
#define SYMBOL_FREE_CELL ' '

// Game state codes
enum GameStates{
  WORM_GAME_ONGOING,
  WORM_OUT_OF_BOUNDS,   //Left screen
  WORM_GAME_QUIT,       //User likes to quit
  WORM_CROSSING,        //Worm head crossed another worm element
};

// Directions for the worm
enum WormHeading{
  WORM_UP,
  WORM_DOWN,
  WORM_LEFT,
  WORM_RIGHT,
};

// ********************************************************************************************
// Global variables
// ********************************************************************************************

// Data defining the worm
// Array of positions for worm elements
int theworm_wormpos_y[WORM_LENGTH];
// Array of x positions for worm elements
int theworm_wormpos_x[WORM_LENGTH];
// Last usable index into the arrays
// theworm_wormpos_y and theworm_wormpos_x
int theworm_maxindex;
// An index intro the array for the worm's head position
// O <= theworm_headindex <= theworm_maxindex
int theworm_headindex;

// The current heading of the worm
// These are offsets from the set {-1,0,+1}
int theworm_dx;
int theworm_dy;

enum ColorPairs theworm_wcolor; 

// ********************************************************************************************
// Forward declarations of functions
// ********************************************************************************************
// This avoids problems with the sequence of function declarations inside the code.
// Note: this kind of problem is solved by header files later on!

// Management of the game
void initializeColors();
void readUserInput(enum GameStates* agame_state );
enum ResCodes doLevel();

// Standard curses initialization and cleanup
void initializeCursesApplication(); 
void cleanupCursesApp(void);

// Placing and removing items from the game board
// Check boundaries of game board
void placeItem(int y, int x, chtype symbol, enum ColorPairs color_pair);
int getLastRow();
int getLastCol();

// Functions concerning the management of the worm data
enum ResCodes initializeWorm(int len_max, int headpos_y, int headpos_x, enum WormHeading dir, enum ColorPairs color);
void showWorm();
void moveWorm(enum GameStates* agame_state);
void setWormHeading(enum WormHeading dir);
void cleanWormTail();
bool isInUseByWorm(int new_headpos_y, int new_headpos_x);

// ********************************************************************************************
// Functions
// ********************************************************************************************

// ************************************
// Management of the game
// ************************************

// Initialize colors of the game
void initializeColors() {
    // Define colors of the game
    start_color();
    init_pair(COLP_USER_WORM,     COLOR_GREEN,    COLOR_BLACK);
    init_pair(COLP_FREE_CELL,     COLOR_BLACK,    COLOR_BLACK);
}

void readUserInput(enum GameStates* agame_state ) {
    int ch; // For storing the key codes

    if ((ch = getch()) > 0) {
        // Is there some user input?
        // Blocking or non-blocking depends of config of getch
        switch(ch) {
            case 'q' :    // User wants to end the show
                *agame_state = WORM_GAME_QUIT;
                break;
            case KEY_UP :// User wants up
                setWormHeading(WORM_UP);
                break;
            case KEY_DOWN :// User wants down
                setWormHeading(WORM_DOWN);
                break;
            case KEY_LEFT :// User wants left
                setWormHeading(WORM_LEFT);
                break;
            case KEY_RIGHT :// User wants right
                setWormHeading(WORM_RIGHT);
                break;
            case 's' : // User wants single step
                nodelay(stdscr, FALSE);  // We simply make getch blocking
                break;
            case ' ' : // Terminate single step; make getch non-blocking again
                nodelay(stdscr, TRUE);   // Make getch non-blocking again
                break;
        }
    }
    return;
}

enum ResCodes doLevel() {
    enum GameStates game_state; // The current game_state

    enum ResCodes res_code; // Result code from functions
    bool end_level_loop;    // Indicates whether we should leave the main loop

    int bottomLeft_y, bottomLeft_x;   // Start positions of the worm

    // At the beginnung of the level, we still have a chance to win
    game_state = WORM_GAME_ONGOING;

    // There is always an initialized user worm.
    // Initialize the userworm with its size, position, heading.
    bottomLeft_y =  getLastRow();
    bottomLeft_x =  0;

    res_code = initializeWorm(WORM_LENGTH, bottomLeft_y, bottomLeft_x , WORM_RIGHT, COLP_USER_WORM);
    if ( res_code != RES_OK) {
        return res_code;
    }

    // Show worm at its initial position
    showWorm();

    // Display all what we have set up until now
    refresh();

    // Start the loop for this level
    end_level_loop = false; // Flag for controlling the main loop
    while(!end_level_loop) {
        // Process optional user input
        readUserInput(&game_state); 
        if ( game_state == WORM_GAME_QUIT ) {
            end_level_loop = true;
            continue; // Go to beginning of the loop's block and check loop condition
        }

        // Process userworm
        // Clean the tail of the worm
        cleanWormTail();
        // Now move the worm for one step
        moveWorm(&game_state);
        // Bail out of the loop if something bad happened
        if ( game_state != WORM_GAME_ONGOING ) {
            end_level_loop = true;
            continue; // Go to beginning of the loop's block and check loop condition
        }
        // Show the worm at its new position
        showWorm();
        // END process userworm

        // Sleep a bit before we show the updated window
        napms(NAP_TIME);

        // Display all the updates
        refresh();

        // Start next iteration
    }

    // Preset res_code for rest of the function
    res_code = RES_OK;

    // For some reason we left the control loop of the current level.
    // However, in this version we do not yet check for the reason.
    // There is no user feedback at the moment!

    // Normal exit point
    return res_code;
}

// *********************************************
// Standard curses initialization and cleanup
// *********************************************

// Initialize application with respect to curses settings
void initializeCursesApplication() {
    initscr(); // Initialize the curses screen

    // Note:
    // The call to initscr() defines various global variables of the curses framework.
    // stdscr, LINES, COLS, TRUE, FALSE

    noecho();  // Characters typed ar not echoed
    cbreak();  // No buffering of stdin
    nonl();    // Do not translate 'return key' on keyboard to newline character
    keypad(stdscr, TRUE); // Enable the keypad
    curs_set(0);          // Make cursor invisible
    // Begin in non-single-step mode (getch will not block)
    nodelay(stdscr, TRUE);  // make getch to be a non-blocking call
}

// Reset display to normale state and terminate curses application
void cleanupCursesApp(void)
{
    standend();   // Turn off all attributes
    refresh();    // Write changes to terminal
    curs_set(1);  // Set cursor state to normal visibility
    endwin();     // Terminate curses application
}

// *************************************************
// Placing and removing items from the game board
// Check boundaries of game board
// *************************************************

// Place an item onto the curses display.
void placeItem(int y, int x, chtype symbol, enum ColorPairs color_pair) {

    //  Store item on the display (symbol code)
    move(y, x);                         // Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));     // Start writing in selected color
    addch(symbol);                      // Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));    // Stop writing in selected color
}

// Getters

// Get the last usable row on the display
int getLastRow() {
    return LINES-1;
}

// Get the last usable column on the display
int getLastCol() {
    return COLS-1;
}

// *****************************************************
// Functions concerning the management of the worm data
// *****************************************************

// START WORM_DETAIL
// The following functions all depend on the model of the worm

// Initialize the worm
enum ResCodes initializeWorm(int len_max, int headpos_y, int headpos_x, enum WormHeading dir, enum ColorPairs color) {
    // Local variables for loops etc.

    // Initialize last usable index to len_max -1
    theworm_maxindex = len_max-1;
    theworm_headindex = 0;

    // Mark all elements as unused
    for(int i = 0; i < len_max; i++){
      theworm_wormpos_x[i] = UNUSED_POS_ELEM;
      theworm_wormpos_y[i] = UNUSED_POS_ELEM;
    }

    // Initialize position of worms head
    theworm_wormpos_x[theworm_headindex] = headpos_x;
    theworm_wormpos_y[theworm_headindex] = headpos_y;

    // Initialize the heading of the worm
    setWormHeading(dir);

    // Initialze color of the worm
    theworm_wcolor = color;

    return RES_OK;
}

// Show the worms's elements on the display
// Simple version
void showWorm() {
    // Due to our encoding we just need to show the head element
    // All other elements are already displayed
    placeItem(
            theworm_wormpos_y[theworm_headindex] ,
            theworm_wormpos_x[theworm_headindex] ,
            SYMBOL_WORM_INNER_ELEMENT, theworm_wcolor);
}

void cleanWormTail(){    
    int tailIndex;
    // Compute TailIndex
    tailIndex = (theworm_headindex + 1) % WORM_LENGTH;
    // Check the array of worm elements
    if(theworm_wormpos_x[tailIndex] == UNUSED_POS_ELEM && theworm_wormpos_y[tailIndex] == UNUSED_POS_ELEM){
      placeItem(theworm_wormpos_y[tailIndex], theworm_wormpos_x[tailIndex], SYMBOL_FREE_CELL, COLP_FREE_CELL);
    }
}

bool isInUseByWorm(int new_headpos_y, int new_headpos_x){
    for(int i = 0; i < WORM_LENGTH; i++){
      if(i != theworm_headindex){
        if(theworm_wormpos_x[i] == new_headpos_x && theworm_wormpos_y[i] == new_headpos_y){
          return true;
        }
      }
    }
    return false;
}

void moveWorm(enum GameStates* agame_state) {
    int headpos_x, headpos_y;
  
    // Compute and store new head position according to current heading.
    headpos_y = theworm_wormpos_y[theworm_headindex]+theworm_dy;
    headpos_x = theworm_wormpos_x[theworm_headindex]+theworm_dx;

    // Check if we would leave the display if we move the worm's head according
    // to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos_x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos_x > getLastCol() ) { 
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos_y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos_y > getLastRow() ) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else {
        // We will stay within bounds.
        //Check if the worm's head will collide with itself at the new position
        if (isInUseByWorm(headpos_y, headpos_x)){
            //That's bad: stop game
            *agame_state = WORM_CROSSING;  
        }
    }

    //Check the status of *agame_state
    //Go on if nothing bad happend
    if (*agame_state == WORM_GAME_ONGOING){
      //Increment the worm_headindex
      //Ring Buffer
      if(theworm_headindex+1 > theworm_maxindex){
        theworm_headindex = 0;
      }
      //Store new coordinates of head element in worm structure
      theworm_wormpos_x[theworm_headindex] = headpos_x;
      theworm_wormpos_y[theworm_headindex] = headpos_y;
    }
}

// Setters
void setWormHeading(enum WormHeading dir) {
    switch(dir) {
        case WORM_UP:// User wants up
            theworm_dx=0;
            theworm_dy=-1;
            break;
        case WORM_DOWN:// User wants down
            theworm_dx=0;
            theworm_dy=1;
            break;
        case WORM_LEFT:// User wants left
            theworm_dx=-1;
            theworm_dy=0;
            break;
        case WORM_RIGHT:// User wants right
            theworm_dx=1;
            theworm_dy=0;
            break;
    }
} 

// END WORM_DETAIL
// ********************************************************************************************

// ********************************************************************************************
// MAIN
// ********************************************************************************************

int main(void) {
    enum ResCodes res_code;         // Result code from functions

    // Here we start
    initializeCursesApplication();  // Init various settings of our application
    initializeColors();             // Init colors used in the game

    // Maximal LINES and COLS are set by curses for the current window size.
    // Note: we do not cope with resizing in this simple examples!

    // Check if the window is large enough to display messages in the message area
    // a has space for at least one line for the worm
    if ( LINES < MIN_NUMBER_OF_ROWS || COLS < MIN_NUMBER_OF_COLS ) {
        // Since we not even have the space for displaying messages
        // we print a conventional error message via printf after
        // the call of cleanupCursesApp()
        cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n",
                MIN_NUMBER_OF_COLS, MIN_NUMBER_OF_ROWS );
        res_code = RES_FAILED;
    } else {
        res_code = doLevel();
        cleanupCursesApp();
    }

    return res_code;
}
