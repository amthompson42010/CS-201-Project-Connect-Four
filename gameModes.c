/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle the different game modes of connect four.
 * 
 */

#include "adjacencyList.h"
#include "board.h"

void checkWin()
{
    
}

/////////////////////////////////////////////////
//    Player versus Player
/////////////////////////////////////////////////
void pvp(int width, int height)
{
    int column[2];
    int ans;
    int ans2;
    int inital[2];

    displayBoard(inital, width, height);
    printf("Please enter a column that you would like to drop your piece in from the options above:  ");
    scanf("%d", &ans);
    column[0] = ans;
    system("clear");
    printf("\n\n");
    
    displayBoard(column, width, height);
    printf("Please enter a column that you would like to drop your piece in from the options above:  ");
    scanf("%d", &ans2);
    system("clear");
    printf("\n\n");
    column[1] = ans2;
    printf("%d %d", column[0], column[1]);
    displayBoard(column, width, height);
}

////////////////////////////////////////////////
//    Player versus Computer
////////////////////////////////////////////////
// void pvc(int width, int height)
// {
//     // int column;
//     // displayBoard(0, width, height);
//     // printf("Please enter a column that you would like to drop your piece in from the options above:  ");
//     // scanf("%d", &column);
//     // displayBoard(column, width, height);
// }

////////////////////////////////////////////////
//    Game Instructions
////////////////////////////////////////////////
void instructions()
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