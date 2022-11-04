// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//

#ifndef _WORM_H
#define _WORM_H

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

#endif  // #define _WORM_H
