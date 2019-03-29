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
#include "gameModes.h"


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

void start(struct Modes *newMode, int score1, int score2)
{
    int width = newMode->width;
    int height = newMode->height;
    int mode = newMode->mode;
    

    int isWin = 0;

    char **board = createBoard(width, height);
    
    newPlayer *player = createPlayer(width);
    
    newPlayer *player2 = createPlayer(width);

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
            playerMove(board, newMode, oneGraph, player, width, height, 1, score1, score2);
            if(isFull(board, width))
            {
                isWin = 1;
                tie();
                int again = playAgain();
                if(again == 1)
                {
                    start(newMode, score1, score2);
                }
            }
            else if(!isGameWon(board, width, height, 1) && mode == 1)
            {
                playerMove(board, newMode, oneGraph, player, width, height, 2, score1, score2);   
            }
            else if(!isGameWon(board, width, height, 1) && mode == 2) {
                CPUMove(board, player->move, oneGraph, twoGraph, width, height, score1, score2, newMode->mode);
            }
            else
            {
                isWin = 1;
                player->score = score1;
                updateScore(player);
                winner(1);
                displayScore(score1, score2, newMode->mode);
                int again = playAgain();
                if(again == 1)
                {
                    start(newMode, player->score, player2->score);
                    
                }
            }
            
        }
        else
        {

            isWin = 1;
            player2->score = score2;
            updateScore(player2);
            winner(2);
            displayScore(score1, score2, newMode->mode);
            int again = playAgain();
            if(again == 1)
            {
                start(newMode, player->score, player2->score);
            }
        }
        
        
    }
}