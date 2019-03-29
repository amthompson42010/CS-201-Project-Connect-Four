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
#include "player.h"

/////////////////////////////////////////////////
//    Check for a win
/////////////////////////////////////////////////
extern void checkWin();

/////////////////////////////////////////////////
//    Player versus Player
/////////////////////////////////////////////////
extern void pvp(struct Modes *mode);

////////////////////////////////////////////////
//    Player versus Computer
////////////////////////////////////////////////
extern void pvc(struct Modes *mode);

extern int playAgain();

#endif