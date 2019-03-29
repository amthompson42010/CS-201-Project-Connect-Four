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
#include "playGame.h"
#include <stdio.h>
#include <stdlib.h>

newPlayer* createPlayer(int x)
{
    struct newPlayer* player = malloc(sizeof(struct newPlayer));
    char *pMove = malloc(x * 3 * sizeof(char));
    player->move = pMove;
    player->playerSymbol = 'O';
    player->score = 0;
    player->column = 0;

    return player;
}

char *getPlayerMove(struct newPlayer* player)
{
    return player->move;
}

void setPlayerMove(char *move, int x, char playerSymbol)
{
    //char *move = player->move;
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

void updateScore(struct newPlayer* player)
{
    player->score = player->score + 1;
}

void setPlayerSymbol(struct newPlayer* player, int playerNum)
{
    if(playerNum == 1)
    {
        player->playerSymbol = 'O';
    }
    else
    {
        player->playerSymbol = 2;
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
        printf("\nPlayer 1 (1): %d vs Player 2 (2): %d\n", playerOneScore, playerTwoScore);
    }
    else
    {
        printf("\nPlayer 1 (1): %d vs Computer (2): %d\n", playerOneScore, playerTwoScore);
    }
}
int getColumn()
{

    int column;
    // Now to get the column the user wants to drop their piece in and update the board
    printf("Enter a column that you would like to drop your piece: ");


    if(scanf("%d", &column) != 1)
    {
        printf("You did not enter a number\n");
        getchar();
        
        column = getColumn();
    }
    
    
    return column;
}

void playerMove(char **board, struct Modes *newMode, struct Graph *graph, struct newPlayer *player, int width, int height, int whatPlayer, int playerOneScore, int playerTwoScore) {
    
    setPlayerMove(player->move, width, player->playerSymbol);
    whosMove(whatPlayer);
    displayBoard(board, width, height);
    displayScore(playerOneScore, playerTwoScore, newMode->mode);
    int col = getColumn(player);

    updateBoard(board, col, (height - 1), whatPlayer);
    if(newMode->mode == 2)
    {
        boardToGraph(board, graph, width, height, col, (height - 1), whatPlayer, 2);
    }
}

void makeCPUMove(char **board, char *playerMove, struct Graph *graph, int x, int y, int xPos, int yPos, int scoreOne, int scoreTwo, int mode) {
    setPlayerMove(playerMove, x, 1);
    updateBoard(board, xPos, yPos, 2);
    displayScore(scoreOne, scoreTwo, mode);
    printf("\nThe Computer has made its move.\n");
    boardToGraph(board, graph, x, y, xPos, yPos, 2, 2);
}

void CPUMove(char **board, char *playerMove, struct Graph *playerOneGraph, struct Graph *playerTwoGraph, int x, int y, int scoreOne, int scoreTwo, int mode) {
    int depthFirstSearchLengthOne, depthFirstSearchLengthTwo, graphLengthOne, graphLengthTwo;
    int maxLength1 = -1, maxLength2 = -1, maxgraphLengthOne = -1, maxgraphLengthTwo = -1;
    for(int i = 0; i < x; i++) {
         int moveFound = 0, currYPos = y;
         while(moveFound && currYPos >= 0) {
             if(board[currYPos][(i * 3) + 1] == ' ') {
                 moveFound = 1;
                 if(isGameWon(board, x, y, 2)) {
                     makeCPUMove(board, playerMove, playerTwoGraph, x, y, i, currYPos, scoreOne, scoreTwo, mode);
                     return;
                 }
                 else if(isGameWon(board, x, y, 1)) {
                     makeCPUMove(board, playerMove, playerTwoGraph, x, y, i, currYPos, scoreOne, scoreTwo, mode);
                     return;
                 }
                 else
                 {
                    boardToGraph(board, playerOneGraph, x, y, i, currYPos, 1, 1);
                    depthFirstSearchLengthOne = DepthFirstSearch(playerOneGraph, (x * currYPos) + i);
                    graphLengthOne = graphLength(playerOneGraph, (x * currYPos) + i);
                    printGraph(playerOneGraph);
                    isVisited(playerOneGraph);
                    freeAdjacencyList(playerOneGraph, (x * currYPos) + i);

                    boardToGraph(board, playerTwoGraph, x, y, i, currYPos, 1, 1);
                    depthFirstSearchLengthTwo = DepthFirstSearch(playerTwoGraph, (x * currYPos) + i);
                    graphLengthTwo = graphLength(playerTwoGraph, (x * currYPos) + i);
                    isVisited(playerTwoGraph);
                    freeAdjacencyList(playerTwoGraph, (x * currYPos) + i);

                    if(depthFirstSearchLengthOne > maxLength1 || (depthFirstSearchLengthOne == maxLength1 && graphLengthOne > maxgraphLengthOne)) {
                        maxLength1 = depthFirstSearchLengthOne;
                        maxgraphLengthOne = graphLengthOne;
                    }
                    if(depthFirstSearchLengthTwo > maxLength2 || (depthFirstSearchLengthTwo == maxgraphLengthTwo && graphLengthTwo > maxgraphLengthTwo)) {
                        maxLength2 = depthFirstSearchLengthTwo;
                        maxgraphLengthTwo = graphLengthTwo;
                    }
                 }
             }
             else
             {
                 currYPos--;
             }
         }
    }
    if(maxLength2 == 0)
    {
        makeCPUMove(board, playerMove, playerTwoGraph, x, y, (rand() % x), (y - 1), scoreOne, scoreTwo, mode);
    }
    else
    {
        makeCPUMove(board, playerMove, playerTwoGraph, x, y, (rand() % x), (y - 1), scoreOne, scoreTwo, mode);
    }
    
}
