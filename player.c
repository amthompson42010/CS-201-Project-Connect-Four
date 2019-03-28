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

void setPlayerMove(struct newPlayer *player, int x, char playerSymbol)
{
    char *move = player->move;
    for(int i = 0; i < x * 3; i++)
    {
        move[i] = ' ';
    }
    move[1] = playerSymbol;

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

void updateMove(struct newPlayer *player, int newLocation, char playerSymbol) {
    char *move = player->move;
    move[(newLocation * 3) + 1] = playerSymbol;
}

void whosMove(int playerNum) {
    printf("\nPlayer %d's turn", playerNum);
}

void displayScore(int playerOneScore, int playerTwoScore, int gameMode)
{
    if(gameMode == 1)
    {
        printf("\nPlayer 1 (O): %d vs Player 2 (X): %d\n", playerOneScore, playerTwoScore);
    }
    else
    {
        printf("\nPlayer 1 (O): %d vs Computer (X): %d\n", playerOneScore, playerTwoScore);
    }
}

void playerMove(char **board, struct Modes *newMode, struct newPlayer *player, struct Graph *graph, int width, int height, int whatPlayer, int playerOneScore, int playerTwoScore) {
    
    int xPosition = 0;
    int column = 0;
    int exitCond = 0;

    //setPlayerSymbol(player, whatPlayer);
    setPlayerMove(player, width, player->playerSymbol);
    whosMove(whatPlayer);
    displayBoard(board, width, height);
    displayScore(playerOneScore, playerTwoScore, newMode->mode);

    // Now to get the column the user wants to drop their piece in and update the board
    printf("Enter a column that you would like to drop your piece: ");
    scanf("%d", &column);

    //updateMove(player, column, player->playerSymbol);
    updateBoard(board, player, width, height, column, (height - 1), whatPlayer);

}