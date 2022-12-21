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

#include <curses.h>
#include <stdlib.h>
#include "worm.h"
#include "board_model.h"
#include "messages.h"

// *************************************************
// Placing and removing items from the game board
// Check boundaries of game board
// *************************************************

// Place an item onto the curses display.
void placeItem(struct board* aboard, int y, int x, enum BoardCodes board_code, chtype symbol, enum ColorPairs color_pair) {

    //  Store item on the display (symbol code)
    move(y, x);                         // Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));     // Start writing in selected color
    addch(symbol);                      // Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));    // Stop writing in selected color

    // Store item on board
    aboard->cells[y][x] = board_code;
}

// Getters
// Get the last usable row on the display
int getLastRowOnBoard(struct board* aboard){
  return aboard->last_row;
}
// Get the last usable column on the display
int getLastColOnBoard(struct board* aboard){
  return aboard->last_col;
}

// Get Number of food in board
int getNumberOfFoodItems(struct board* aboard){
  return aboard->food_items;
}

// Get Content of specific position
enum BoardCodes getContentAt(struct board* aboard, struct pos position){
  return aboard->cells[position.y][position.x];
}

// Setters
// Set Number of food in board
void setNumberOfFoodItems(struct board* aboard, int n){
  aboard->food_items = n;
}

// Decrement of food count in board
void decrementNumberOfFoodItems(struct board* aboard){
  aboard->food_items--;
}

// Init Board
enum ResCodes initializeBoard(struct board* aboard){
  //Check dimensions of the board
  if(COLS < MIN_NUMBER_OF_COLS || LINES < MIN_NUMBER_OF_ROWS + ROWS_RESERVED){
    char buff[100];
    sprintf(buff, "Das Fenster ist zu klein: wir brauchen %dx%d", MIN_NUMBER_OF_COLS, MIN_NUMBER_OF_ROWS + ROWS_RESERVED);
    showDialog(buff, "Bitte eine Taste druecken");
    return RES_FAILED;
  }

  //Maximal index of a row
  aboard->last_row = MIN_NUMBER_OF_ROWS-1;
  aboard->last_col = MIN_NUMBER_OF_COLS-1;
  
  return RES_OK;
}

// Init Level
enum ResCodes initializeLevel(struct board* aboard){
  int y, x;
  
  // Init time
  //time_t t;
  //srand((unsigned) &t);

  // Fill board and screen buffer with empty cells.
  for(y=0; y <= aboard->last_row; y++){
    for(x=0; x <= aboard->last_col; x++){
      placeItem(aboard, y, x, BC_FREE_CELL, SYMBOL_FREE_CELL, COLP_FREE_CELL);
    }
  }
  
  // Draw a line in order to seperate the message area
  // No placeItem because outside of the board
  y = aboard->last_row+1;
  for(x=0; x <= aboard->last_col; x++){
    move(y,x);
    attron(COLOR_PAIR(COLP_BARRIER));
    addch(SYMBOL_BARRIER);
    attroff(COLOR_PAIR(COLP_BARRIER));
  }

  // Draw a line to signal the rightmost column of the board.
  for(y=0; y <= aboard->last_row; y++){
    placeItem(aboard, y, aboard->last_col, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }

  // Barriers: use a loop
  for(y=aboard->last_row/2; y <= aboard->last_row/2+10; y++){
    placeItem(aboard, y, aboard->last_col/3, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }
  for(y=aboard->last_row/3; y <= aboard->last_row/3+10; y++){
    placeItem(aboard, y, (aboard->last_col*2)/3, BC_BARRIER, SYMBOL_BARRIER, COLP_BARRIER);
  }
  
  // Food
  placeItem(aboard, 3, 3, BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_1, SYMBOL_FOOD_1, COLP_FOOD_1);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_2, SYMBOL_FOOD_2, COLP_FOOD_2);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  placeItem(aboard, rand()%aboard->last_row, rand()%aboard->last_col, BC_FOOD_3, SYMBOL_FOOD_3, COLP_FOOD_3);
  
  // Init number of food items
  aboard->food_items = 10;
  return RES_OK;
}
