#include "adjacencyList.c"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "board.c"

void openingScreen() {
    printf("                              Welcome to connect four\n");              //WELCOME MESSAGE
    sleep(2);
    for(int k=0;k<3;k++)printf("\n");
    int choice;
    int width;
    int height;
    printf("                                   1-Single Player\n"                ////////////////////////////
           "                                   ----------  \n"              //                          //
          "                                   2-Multiplayer\n"              //    MAIN MENU            //
          "                                   -------------\n"              ////////////////////////////
          "                                   3-Player v Computer\n"
          "                                   -----------\n"
          "                                   4-instruction\n"
          "                                   -------------      "
          "                                   \n\n\n");

    printf("Please enter a number from the choices above: ");
    scanf("%d", &choice);
    printf("\n\n");
    if(choice == 1 || choice == 2 || choice == 3)
    {
        printf("How many columns do you want? ");
        scanf("%d", &width);

        printf("How many rows do you want to use? ");
        scanf("%d", &height);
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
        addEdge(graph, 2, 4);
        addEdge(graph, 3, 4);
        addEdge(graph, 4, 6);
        addEdge(graph, 5, 1);
        addEdge(graph, 5, 6);
    
        printGraph(graph);
    }
}

int main()
{
    system("cls||clear");
    openingScreen();
 
    return 0;
}