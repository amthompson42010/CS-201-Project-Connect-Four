#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

extern int horizontalWin(char **board, int width, int height, int whatPlayer);
extern int verticalWin(char **board, int width, int height, int whatPlayer);
extern int diagonalWin(char **board, int width, int height, int whatPlayer);

#endif