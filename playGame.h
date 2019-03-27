#ifndef PLAYGAME_H_INCLUDED
#define PLAYGAME_H_INCLUDED

#include "menu.h"

extern void winner(int whatPlayer);
extern void tie();
extern int isGameWon(char **board, int width, int height, int playerID);
extern void start(struct Modes *newMode);

#endif