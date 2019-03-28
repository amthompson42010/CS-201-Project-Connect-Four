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
} newPlayer;

extern newPlayer* createPlayer(int x);
extern int getScore(struct newPlayer* player);
extern void setScore(struct newPlayer* player, int score);
extern char *getPlayerMove(struct newPlayer* player);
extern void setPlayerMove(struct newPlayer *player, int x, char playerSymbol);
extern void getPlayerSymbol(struct newPlayer *player);
extern void setPlayerSymbol(struct newPlayer* player, int playerNum);
extern void printMove(struct newPlayer *player, int x);
extern void updateMove(struct newPlayer *player, int newLocation, char playerSymbol);
extern void playerMove(char **board, struct Modes *newMode, struct newPlayer *player, struct Graph *graph, int width, int height, int whatPlayer, int playerOneScore, int playerTwoScore);
extern void whosMove(int playerNum);
extern void displayScore(int playerOneScore, int playerTwoScore, int gameMode);

#endif