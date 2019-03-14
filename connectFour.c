#include "adjacencyList.c"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    system("cls||clear");
    printf("                              Welcome to connect four\n");              //WELCOME MESSAGE
    sleep(2);
    for(int k=0;k<3;k++)printf("\n");
    printf("                                   1-new game\n"                ////////////////////////////
           "                                   ----------  \n"              //                          //
          "                                   2-high scores\n"              //    MAIN MENU            //
          "                                   -------------\n"              ////////////////////////////
          "                                   3-load game\n"
          "                                   -----------\n"
          "                                   4-instruction\n"
          "                                   -------------      "
          "                                   \n");
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
 
    return 0;
}