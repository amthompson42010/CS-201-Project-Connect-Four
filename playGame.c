#include "menu.h"
#include "board.h"
#include "adjacencyList.h"
#include "player.h"
#include "gameState.h"
#include "playGame.h"

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

    int isWin = 0;

    char **board = createBoard(width, height);
    
    newPlayer *playerOne = createPlayer(width);
    char *move = playerOne->move;
    newPlayer *playerTwo = createPlayer(width);
    char *move2 = playerTwo->move;
    newPlayer *computer = createPlayer(width);
    char *move3 = computer->move;

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
        }
        
    }
}