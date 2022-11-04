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

// A worm structure
struct worm{
  int maxindex;
  int headindex;

  struct pos wormpos[WORM_LENGTH];

  int dx;
  int dy;

  enum ColorPairs wcolor;
};

// Directions for the worm
enum WormHeading{
  WORM_UP,
  WORM_DOWN,
  WORM_LEFT,
  WORM_RIGHT,
};

// Functions concerning the management of the worm data
extern enum ResCodes initializeWorm(struct worm* aworm, int len_max, struct pos headpos, enum WormHeading dir, enum ColorPairs color);
extern void showWorm(struct worm* aworm);
extern void moveWorm(struct worm* aworm, enum GameStates* agame_state);
extern void setWormHeading(struct worm* aworm, enum WormHeading dir);
extern void cleanWormTail(struct worm* aworm);
extern bool isInUseByWorm(struct worm* aworm, struct pos new_headpos);
extern struct pos getWormHeadPos(struct worm* aworm);

#endif  // #define _WORM_MODEL_H
