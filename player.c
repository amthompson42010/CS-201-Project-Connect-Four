/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle player creation and actions.
 * 
 */

#include "player.h"
#include "adjacencyList.h"
#include "board.h"
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

void whosMove(int playerNum) {
    printf("Player &d's turn", playerNum);
}

void displayScore(struct newPlayer *player, struct newPlayer *player2, int gameMode)
{
    if(gameMode == 1)
    {
        printf("\nPlayer 1 (O): %d vs Player 2 (X): %d\n", player->score, player2->score);
    }
    else
    {
        printf("\nPlayer 1 (O): %d vs Computer (X): %d\n", player->score, player2->score);
    }
}

void playerMove(char **board, struct Modes *newMode, struct newPlayer *player, struct newPlayer *player2, struct Graph *graph, int width, int height, int whatPlayer, int mode) {
    
    int column, xPosition = 0;

    if(whatPlayer == 1)
    {
        setPlayerMove(player->move, width, player->playerSymbol);
        whosMove(whatPlayer);
        printMove(player->move, width);
        displayBoard(board, width, height);
        displayScore(player, player2, newMode->mode);

        // Now to get the column the user wants to drop their piece in and update the board
        
    }
}