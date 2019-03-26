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
#include "player.h"

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

    newPlayer *player = createPlayer(newMode->width);

    if(newMode->mode == 1)
    {
        pvp(board, newMode->width, newMode->height, player);
    }
    else
    {
        printf("UH OH");
    }
}