/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle the different game modes of connect four.
 * 
 */

#ifndef GAMEMODES_H_INCLUDED
#define GAMEMODES_H_INCLUDED

#include "adjacencyList.h"
#include "board.h"

extern void checkWin();

/////////////////////////////////////////////////
//    Player versus Player
/////////////////////////////////////////////////
extern void pvp(int width, int height);

////////////////////////////////////////////////
//    Player versus Computer
////////////////////////////////////////////////
extern void pvc(int width, int height);

////////////////////////////////////////////////
//    Game Instructions
////////////////////////////////////////////////
extern void instructions();

#endif