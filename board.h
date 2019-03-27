/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Header for the board.c file.
 * 
 */

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdio.h>

extern int isFull(char **board, int width);
extern char **createBoard(int width, int height);
extern void displayBoard(char **board, int width, int height);

#endif