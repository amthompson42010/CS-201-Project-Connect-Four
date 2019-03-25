/**
 * 
 *  Created By Alexander Mark Thompson
 * 
 *  Main file for connect four game.
 *  
 *  Game modes:
 *      - Player versus Player
 *      - PLayer versus Computer
 *      - Instructions
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "gameModes.h"
#include "menu.h"

void mainRun(struct Modes *newMode);

////////////////////////////////////////////////
// Main Function
////////////////////////////////////////////////
int main()
{
    system("clear");

    struct Modes *newMode = malloc(sizeof(newMode));
    mainRun(newMode);
 
    return 0;
}

void printHeader(int whatPlayer)
{
    // Make sure to clear screen first
    printf("Enter the number of the column that you would like to drop your piece in.");
    printf("Player %d's turn.\n\n", whatPlayer);
}

void displayScore(int scoreOne, int scoreTwo, int gameMode)
{
    if(gameMode == 1)
    {
        printf("\nPlayer 1 (O): %d vs Player 2 (X): %d\n", scoreOne, scoreTwo);
    }
    else
    {
        printf("\nPlayer 1 (O): %d vs Computer (X): %d\n", scoreOne, scoreTwo);
    }
}

////////////////////////////////////////////////////////
//   Function to handle the beginning remarks,
//   as well as handling when the game modes
//   are selected.
////////////////////////////////////////////////////////
void mainRun(struct Modes *newMode) {
    welcomeScreen();              

    for(int k=0;k<3;k++)printf("\n");

    getScreenWidth(newMode);
    getScreenHeight(newMode);
    mainModeOptions(newMode);

    char **board = createBoard(newMode->width, newMode->height);

    if(newMode->mode == 1)
    {
        pvp(board, newMode->width, newMode->height);
    }
    else
    {
        printf("UH OH");
    }
}