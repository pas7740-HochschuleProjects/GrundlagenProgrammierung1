// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The board model

#ifndef _BOARD_MODEL_H
#define _BOARD_MODEL_H

#include <curses.h>
#include "worm.h"

// Codes on the board
enum BoardCodes {
    BC_FREE_CELL,    // Cell is free
    BC_USED_BY_WORM, // Cell occupied by worm
    BC_FOOD_1,       // Food type 1; if hit by worm -> bonus of type 1
    BC_FOOD_2,       // Food type 2; if hit by worm -> bonus of type 2
    BC_FOOD_3,       // Food type 3; if hit by worm -> bonus of type 3
    BC_BARRIER       // A barrier; if hit by worm -> game over
};

// Positions on the board
struct pos {
    int y;   // y-coordinate (row)
    int x;   // x-coordinate (column)
};


// Board
// A board structure
struct board
{
    int last_row; // Last usable row on the board
    int last_col; // Last usable column on the board

    enum BoardCodes** cells;
    // A 2-dimensional array for storing the contents of the board.
    //
    // Since the worm is not permitted to cross over itsself
    // nor other elements (apart from food) we do not need a reference
    // counter for occupied cells.

    int food_items; // Number of food items left in the current level
};

extern enum ResCodes initializeBoard(struct board* aboard);
extern void cleanupBoard(struct board* aboard);
extern void placeItem(struct board* aboard, int y, int x, enum BoardCodes board_code,
               chtype symbol, enum ColorPairs color_pair);
extern enum ResCodes initializeLevel(struct board* aboard);

// Getters
extern int getNumberOfFoodItems(struct board* aboard);
extern enum BoardCodes getContentAt(struct board* aboard, struct pos position);
extern int getLastRowOnBoard(struct board* aboard);
extern int getLastColOnBoard(struct board* aboard);

// Setters
extern void decrementNumberOfFoodItems(struct board* aboard);
extern void setNumberOfFoodItems(struct board* aboard, int n);

#endif  // #define _BOARD_MODEL_H
