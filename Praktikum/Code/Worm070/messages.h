// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// Displaying messages and dialogs

#ifndef _MESSAGES_H
#define _MESSAGES_H

#include "worm.h"
#include "worm_model.h"
#include "board_model.h"

extern void clearLineInMessageArea(int row);
extern void showStatus(struct board* aboard, struct worm* aworm);
extern int showDialog(char* prompt1, char* prompt2);

#endif  // #define _MESSAGES_H
