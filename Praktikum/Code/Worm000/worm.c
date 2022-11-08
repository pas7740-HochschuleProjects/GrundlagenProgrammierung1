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
#include <string.h>

// ********************************************************************************************
// Constants, data structures
// ********************************************************************************************

// Result codes of functions
#define RES_OK 0
#define RES_FAILED 1

// *********************************************
// Standard curses initialization and cleanup
// *********************************************

// Initialize application with respect to curses settings
void initializeCursesApplication() {
    initscr(); // Initialize the curses screen

    // Note:
    // The call to initscr() defines various global variables of the curses framework.
    // stdscr, LINES, COLS, TRUE, FALSE

    noecho();  // Characters typed are not echoed
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

// ********************************************************************************************
// MAIN
// ********************************************************************************************

int main(void) {
    int res_code;   // Result code from functions
    char* message_template = "Das Fenster hat xxx Zeilen und yyy Spalten";
    int msg_len;
    int min_rows = 3;

    // Here we start
    initializeCursesApplication();    // Init various settings of our application (01)

    msg_len = strlen(message_template);   // Compute length of our template (02)

    // Maximal LINES and COLS are set by curses for the current window size.
    // Check if the window is large enough to display our message
    if (LINES < min_rows || COLS < msg_len) {   // (03)
        // Cleanup special curses settings and restore the normal terminal functionality
        cleanupCursesApp();   // (04)
        // Print a conventional error message via printf.
        // Note: this only work after the call to  cleanupCursesApp();
        printf("Das Fenster ist zu klein: wir brauchen mindestens %dx%d\n", msg_len, min_rows);   // (05)
        // Set the result code to report the error
        res_code = RES_FAILED;
    }
    else{
        // Center output
        int mid_row = LINES/2;
        int start_col = COLS/2-msg_len/2;    // (06)

        // Write letter A to the top left corner of our display
        move(0,0);
        addch('A');   // (07)
        // Write letter B to the top right corner of our display
        mvaddch(0, COLS-1, 'B');    // (08)
        // Write letter C to the bottom right corner of our display
        mvaddch(LINES-1, COLS-1, 'C');    // (09)
        // Write letter D to the bottom left  corner of our display
        mvaddch(LINES-1, 0, 'D');   // (10)
 
        // Write our message centered onto the display
        mvprintw(mid_row, start_col,"Das Fenster hat %3d Zeilen und %3d Spalten", LINES, COLS);   // (11)

        // Refresh the screen in order to show all changes on the screen
        refresh();    // (12)
        
        // Wait for user to press a key
        nodelay(stdscr, FALSE);   // Make getch to be a blocking call (13)
        getch();

        // Set the result code to report success
        res_code = RES_OK;
    }
    
    // Cleanup special curses settings and restore the normal terminal functionality
    cleanupCursesApp();   // (14)
    
    return res_code;
}
