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
    char move;
    char playerSymbol;
    int score;
} newPlayer;

extern newPlayer* createPlayer();
extern int getScore(struct newPlayer* player);
extern void setScore(struct newPlayer* player, int score);
extern void getPlayerMove(struct newPlayer* player);
extern void setPlayerMove(char move, int x, char playerSymbol);
extern void getPlayerSymbol(struct newPlayer* player);
extern void setPlayerSymbol(struct newPlayer* player, int playerNum);

#endif