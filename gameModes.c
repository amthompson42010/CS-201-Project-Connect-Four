/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle the different game modes of connect four.
 * 
 */

#include "adjacencyList.h"
#include "board.h"

/////////////////////////////////////////////////
//    Player versus Player
/////////////////////////////////////////////////
void pvp(char **board, int width, int height)
{
    displayBoard(board, width, height);
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