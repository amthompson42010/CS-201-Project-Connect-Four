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

#include "adjacencyList.c"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "board.c"
#include "time.h"

//////////////////////////////////////////////////
//             Main Menu Function
//      
//   Returns the choice from the menu options
//////////////////////////////////////////////////
int mainMenu() {

    int choice;

    printf(           
          "                                   1-Player v Player\n"              //    MAIN MENU            //
          "                                   -------------\n"              ////////////////////////////
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
void openingScreen() {
    printf("                              Welcome to connect four\n");              //WELCOME MESSAGE
    sleep(2);
    for(int k=0;k<3;k++)printf("\n");
    int width;
    int height;
    int min = 1;
    int max = 46;

    time_t t;
    srand((unsigned) time(&t));

    width = (rand() % (max+1)) + min;
    height = width - 1;
    
    int ans = mainMenu();
    printf("\n\n");
    if(ans == 1 || ans == 2)
    {
        displayBoard(width, height);
    } 
    else
    {
        struct Graph* graph = createGraph(6);
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 2);
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 4);
        addEdge(graph, 1, 3);
        addEdge(graph, 5, 4);
        addEdge(graph, 3, 4);
        addEdge(graph, 8, 6);
        addEdge(graph, 5, 1);
        addEdge(graph, 2, 6);
    
        printGraph(graph);
    }
}

////////////////////////////////////////////////
// Main Function
////////////////////////////////////////////////
int main()
{
    system("cls||clear");
    openingScreen();
 
    return 0;
}