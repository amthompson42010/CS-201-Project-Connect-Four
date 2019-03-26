/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Header file for player.c
 * 
 */

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

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
extern void getPlayerSymbol(struct newPlayer* player);
extern void setPlayerSymbol(struct newPlayer* player, int playerNum);
extern void printMove(char *move, int x);
extern void updateMove(char *move, int currLocation, int newLocation, char playerSymbol);


#endif