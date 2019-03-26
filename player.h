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
extern void setPlayerMove(char *move, int x, char playerSymbol);
extern void getPlayerSymbol(struct newPlayer *player);
extern void setPlayerSymbol(struct newPlayer* player, int playerNum);
extern void printMove(char *move, int x);
extern void updateMove(char *move, int currLocation, int newLocation, char playerSymbol);
void playerMove(char **board, struct Modes *newMode, struct newPlayer *player, struct newPlayer *player2, struct Graph *graph, int width, int height, int whatPlayer, int mode);
void whosMove(int playerNum);
void displayScore(struct newPlayer *player, struct newPlayer *player2, int gameMode);

#endif