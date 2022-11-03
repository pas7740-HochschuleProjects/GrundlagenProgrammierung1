// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The worm model

#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "worm_model.h"

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
    if(isInUseByWorm(theworm_wormpos_y[tailIndex], theworm_wormpos_x[tailIndex])){
      placeItem(theworm_wormpos_y[tailIndex], theworm_wormpos_x[tailIndex], SYMBOL_FREE_CELL, COLP_FREE_CELL);
    }
}

bool isInUseByWorm(int new_headpos_y, int new_headpos_x){
    for(int i = 0; i < WORM_LENGTH; i++){
      if(i != theworm_headindex){
        if(new_headpos_x == theworm_wormpos_x[i] && new_headpos_y == theworm_wormpos_y[i] && new_headpos_x != -1 && new_headpos_y != -1){
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
      }else{
        theworm_headindex++;
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
