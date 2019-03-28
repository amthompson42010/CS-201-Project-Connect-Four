/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Header File for playGame.c
 * 
 */

#ifndef PLAYGAME_H_INCLUDED
#define PLAYGAME_H_INCLUDED

#include "menu.h"
#include "board.h"
#include "adjacencyList.h"
#include "player.h"
#include "gameState.h"

extern void winner(int whatPlayer);
extern void tie();
extern int isGameWon(char **board, int width, int height, int playerID);
extern void start(struct Modes *newMode);

#endif