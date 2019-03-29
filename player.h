/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Header file for player.c
 * 
 */

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "adjacencyList.h"
#include "menu.h"

typedef struct newPlayer {
    char *move;
    char playerSymbol;
    int score;
    int column;
} newPlayer;

extern newPlayer* createPlayer(int x);
extern void updateScore(struct newPlayer* player);
extern void setPlayerMove(char *move, int x, char playerSymbol);
extern void getPlayerSymbol(struct newPlayer *player);
extern void printMove(struct newPlayer *player, int x);
extern void playerMove(char **board, struct Modes *newMode, struct Graph *graph, struct newPlayer *player, int width, int height, int whatPlayer, int playerOneScore, int playerTwoScore);
extern void whosMove(int playerNum);
extern void CPUMove(char **board, char *playerMove, struct Graph *playerOneGraph, struct Graph *playerTwoGraph, int x, int y, int scoreOne, int scoreTwo, int mode);
extern int getColumn();

extern void makeCPUMove(char **board, char *playerMove, struct Graph *graph, int x, int y, int xPos, int yPos, int scoreOne, int scoreTwo, int mode);
extern void displayScore(int playerOneScore, int playerTwoScore, int gameMode);

#endif