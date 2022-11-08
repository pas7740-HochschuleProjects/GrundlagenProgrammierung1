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

#ifndef _WORM_MODEL_H
#define _WORM_MODEL_H

#include <stdbool.h>
#include "worm.h"
#include "board_model.h"

// Codes for the array of positions
#define UNUSED_POS_ELEM -1  // Unused element in the worm arrays of positions

// Dimensions and bounds
#define WORM_LENGTH (MIN_NUMBER_OF_ROWS * MIN_NUMBER_OF_COLS) // Max length of a worm
#define WORM_INITIAL_LENGTH 4  // Initial length of the user's worm

// Boni for eating food
enum Boni {
    BONUS_1 = 2, // additional length for worm when consuming food of type 1
    BONUS_2 = 4, // additional length for worm when consuming food of type 2
    BONUS_3 = 6, // additional length for worm when consuming food of type 3
};

// A worm structure
struct worm
{
    int cur_lastindex; // The current last index in the array of worm's element positions
    int maxindex;      // Last usable index into the array pointed to by wormpos

    int headindex;     // An index into the array for the head position of the worm
    // 0 <= headindex <= maxindex

    struct pos wormpos[WORM_LENGTH]; // Array of x,y positions of all elements of the worm

    // The current heading of the worm
    // These are offsets from the set {-1,0,+1}
    int dx;
    int dy;

    // Color of the worm
    enum ColorPairs wcolor; 
};

enum WormHeading {
    WORM_UP,
    WORM_DOWN,
    WORM_LEFT,
    WORM_RIGHT
};

extern enum ResCodes initializeWorm(struct worm* aworm, int len_max, int len_cur,
                                    struct pos headpos, enum WormHeading dir, enum ColorPairs color);

extern void growWorm(struct worm* aworm, enum Boni growth);
extern void showWorm(struct board* aboard, struct worm* aworm);
extern void cleanWormTail(struct board* aboard, struct worm* aworm);
extern void moveWorm(struct board* aboard, struct worm* aworm, enum GameStates* agame_state);

// Getters
extern struct pos getWormHeadPos(struct worm* aworm);
extern int getWormLength(struct worm* aworm);

//Setters
extern void setWormHeading(struct worm* aworm, enum WormHeading dir);


#endif  // #define _WORM_MODEL_H
