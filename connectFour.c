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
#include <unistd.h>
#include <string.h>
#include "time.h"
#include "gameModes.h"


//////////////////////////////////////////////////
//             Main Menu Function
//      
//   Returns the choice from the menu options
//////////////////////////////////////////////////
int mainMenu() {

    int choice;

    printf(           
          "                                   1-Player v Player\n"              
          "                                   -------------\n"              
          "                                   2-Player v Computer\n"
          "                                   -----------\n"
          "                                   3-instruction\n"
          "                                   -------------      "
          "                                   \n\n\n");

    printf("Please enter a number from the choices above: ");
    scanf("%d", &choice);

    return choice;
}

////////////////////////////////////////////////////////
//   Function to handle the beginning remarks,
//   as well as handling when the game modes
//   are selected.
////////////////////////////////////////////////////////
void mainRun() {
    printf("                              Welcome to connect four\n");              
    sleep(1);
    for(int k=0;k<3;k++)printf("\n");
    int width;
    int height;
    int min = 4;
    int max = 46;

    time_t t;
    srand((unsigned) time(&t));

    width = (rand() % (max+1)) + (min-4);
    height = width - 1;
    
    int ans = mainMenu();
    printf("\n\n");
    if(ans == 1)
    {
        pvp(width, height);
    }
    else if(ans == 2)
    {
        //pvc(width, height);
    }
    else
    {
        instructions();
    }
}

////////////////////////////////////////////////
// Main Function
////////////////////////////////////////////////
int main()
{
    system("clear");
    mainRun();
 
    return 0;
}