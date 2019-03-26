#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

extern int horizontalWin(char **board, int width, int height, char playerSymbol);
extern int verticalWin(char **board, int width, int height, char playerSymbol);
extern int diagonalWin(char **board, int width, int height, int whatPlayer);

#endif