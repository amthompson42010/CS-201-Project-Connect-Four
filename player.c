/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle player creation and actions.
 * 
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>

newPlayer* createPlayer(int x)
{
    struct newPlayer* player = malloc(sizeof(struct newPlayer));
    char *pMove = malloc(x * 3 * sizeof(char));
    player->move = pMove;
    player->playerSymbol = 'O';
    player->score = 0;

    return player;
}

char *getPlayerMove(struct newPlayer* player)
{
    return player->move;
}

void setPlayerMove(char *move, int x, char playerSymbol)
{
    for(int i = 0; i < x * 3; i++)
    {
        move[i] = ' ';
    }
    move[1] = playerSymbol;
}

void printMove(char *move, int x)
{
    for(int i = 0; i < x * 3; i++)
    {
        printf("%c", move[i]);
    }
    printf("\n");
}

int getScore(struct newPlayer* player)
{
    return player->score;
}

int getSymbol(struct newPlayer* player)
{
    return player->playerSymbol;
}

void setScore(struct newPlayer* player, int score)
{
    player->score = score;
}

void setPlayerSymbol(struct newPlayer* player, int playerNum)
{
    if(playerNum == 1)
    {
        player->playerSymbol = 'O';
    }
    else
    {
        player->playerSymbol = 'X';
    }
}

void updateMove(char *move, int currLocation, int newLocation, char playerSymbol) {
    move[(currLocation * 3) + 1] = ' ';
    move[(newLocation * 3) + 1] = playerSymbol;
}