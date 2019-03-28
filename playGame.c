/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle main game flow of Connect Four.
 * 
 */ 

#include "playGame.h"
#include "menu.h"
#include "board.h"
#include "adjacencyList.h"
#include "player.h"
#include "gameState.h"


void winner(int whatPlayer)
{
    printf("Player %d, you have won!\n\n", whatPlayer);
}

void tie()
{
    printf("The board is now full, there are no more available moves.\n");
    printf("The game is a tie!");
}

int isGameWon(char **board, int width, int height, int playerID) {
    return (horizontalWin(board, width, height, playerID) || verticalWin(board, width, height, playerID) || diagonalWin(board, width, height, playerID));
}

void start(struct Modes *newMode)
{
    int width = newMode->width;
    int height = newMode->height;
    int mode = newMode->mode;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int z = 0;

    int isWin = 0;

    char **board = createBoard(width, height);
    
    newPlayer *player = createPlayer(width);
    char *move = player->move;

    Graph *oneGraph = createGraph(width * height);
    Graph *twoGraph = createGraph(width * height);

    while(isWin != 1)
    {
        if(isFull(board, width))
        {
            isWin = 1;
            tie();
        }
        else if(!isGameWon(board, width, height, 2))
        {
            //playerMove(board, move, oneGraph, width, height, 2);
            playerMove(board, newMode, player, oneGraph, width, height, 1, playerOneScore, playerTwoScore);
            if(isFull(board, width))
            {
                isWin = 1;
                tie();
            }
            else if(!isGameWon(board, width, height, 1) && mode == 1)
            {
                //printf("CHECK");
                playerMove(board, newMode, player, oneGraph, width, height, 2, playerOneScore, playerTwoScore);
            }
            else if (z == 1) {
                printf("HIT");
            }
            else
            {
                isWin = 1;
                printf("GOOD HIT");
            }
            
        }
        else
        {

            isWin = 1;
            printf("GOOD HIT");
        }
        
        
    }
}