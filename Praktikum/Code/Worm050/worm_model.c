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

// *****************************************************
// Functions concerning the management of the worm data
// *****************************************************

// START WORM_DETAIL
// The following functions all depend on the model of the worm

// Initialize the worm
enum ResCodes initializeWorm(struct worm* aworm, int len_max, struct pos headpos, enum WormHeading dir, enum ColorPairs color) {
    // Initialize last usable index to len_max -1
    aworm->maxindex = len_max-1;
    aworm->headindex = 0;

    // Mark all elements as unused
    for(int i = 0; i <= aworm->maxindex; i++){
      aworm->wormpos[i].x = UNUSED_POS_ELEM;
      aworm->wormpos[i].y = UNUSED_POS_ELEM;
    }

    // Initialize position of worms head
    aworm->wormpos[aworm->headindex] = headpos;

    // Initialize the heading of the worm
    setWormHeading(aworm, dir);

    // Initialze color of the worm
    aworm->wcolor = color;

    return RES_OK;
}

// Show the worms's elements on the display
// Simple version
void showWorm(struct worm* aworm) {
    struct pos position = aworm->wormpos[aworm->headindex];
    // Due to our encoding we just need to show the head element
    // All other elements are already displayed
    placeItem(
            position.y ,
            position.x ,
            SYMBOL_WORM_INNER_ELEMENT, aworm->wcolor);
}

void cleanWormTail(struct worm* aworm){    
    int tailIndex;
    // Compute TailIndex
    tailIndex = (aworm->headindex + 1) % (aworm->maxindex+1);
    // Check the array of worm elements
    if(isInUseByWorm(aworm, aworm->wormpos[tailIndex])){
      placeItem(aworm->wormpos[tailIndex].y, aworm->wormpos[tailIndex].x, SYMBOL_FREE_CELL, COLP_FREE_CELL);
    }
}

bool isInUseByWorm(struct worm* aworm, struct pos new_headpos){
    for(int i = 0; i <= aworm->maxindex; i++){
      if(i != aworm->headindex){
        if(new_headpos.x == aworm->wormpos[i].x && new_headpos.y == aworm->wormpos[i].y && new_headpos.x != UNUSED_POS_ELEM && new_headpos.y != UNUSED_POS_ELEM){
          return true;
        }
      }
    }
    return false;
}

void moveWorm(struct worm* aworm, enum GameStates* agame_state) {
    struct pos headpos;
  
    // Compute and store new head position according to current heading.
    headpos.y = aworm->wormpos[aworm->headindex].y+aworm->dy;
    headpos.x = aworm->wormpos[aworm->headindex].x+aworm->dx;

    // Check if we would leave the display if we move the worm's head according
    // to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos.x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastCol() ) { 
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.y > getLastRow() ) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else {
        // We will stay within bounds.
        //Check if the worm's head will collide with itself at the new position
        if (isInUseByWorm(aworm, headpos)){
            //That's bad: stop game
            *agame_state = WORM_CROSSING;  
        }
    }

    //Check the status of *agame_state
    //Go on if nothing bad happend
    if (*agame_state == WORM_GAME_ONGOING){
      //Increment the worm_headindex
      //Ring Buffer
      if(aworm->headindex+1 > aworm->maxindex){
        aworm->headindex = 0;
      }else{
        aworm->headindex++;
      }
      //Store new coordinates of head element in worm structure
      aworm->wormpos[aworm->headindex] = headpos;
    }
}

// Setters
void setWormHeading(struct worm* aworm, enum WormHeading dir) {
    switch(dir) {
        case WORM_UP:// User wants up
            aworm->dx=0;
            aworm->dy=-1;
            break;
        case WORM_DOWN:// User wants down
            aworm->dx=0;
            aworm->dy=1;
            break;
        case WORM_LEFT:// User wants left
            aworm->dx=-1;
            aworm->dy=0;
            break;
        case WORM_RIGHT:// User wants right
            aworm->dx=1;
            aworm->dy=0;
            break;
    }
}

// Getters

struct pos getWormHeadPos(struct worm* aworm){
  return aworm->wormpos[aworm->headindex];
}
