/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle adjacency list creation, and handle operations
 *  done on the lists.
 * 
 */
 
#ifndef ADJACENCYLIST_H_INCLUDED
#define ADJACENCYLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int vertex;
    struct node* next;
} node;

typedef struct Graph
{
    int numVertices;
    int *vistedNodes;
    struct node** adjLists;
} Graph;

extern node* createNode(int);
extern Graph* createGraph(int vertices);
extern void addEdge(struct Graph* graph, int src, int dest);
extern int DepthFirstSearch(struct Graph *graph, int vertex);
extern void boardToGraph(char **board, struct Graph *graph, int width, int height, int xPosition, int yPosition, int playerNum, int isMultiEdge);
extern int graphLength(struct Graph *graph, int vertex);
extern void isVisited(struct Graph *graph);
extern void freeAdjacencyList(struct Graph *graph, int vertex); 

#endif