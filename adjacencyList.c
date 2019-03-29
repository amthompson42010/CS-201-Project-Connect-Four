/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle adjacency list creation, and handle operations
 *  done on the lists.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.h"

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
 
    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int destination)
{
    // Add edge from src to dest
    struct node* newNode = createNode(destination);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void updateGraph(struct Graph *graph, int src, int destination, int isMultiEdge)
{
    if(isMultiEdge == 1)
    {
        addEdge(graph, src, destination);
    }
    else
    {
        addEdge(graph, src, destination);
        addEdge(graph, destination, src);
    }
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int DepthFirstSearch(struct Graph *graph, int vertex)
{
    struct node *adjList = graph->adjLists[vertex];
    struct node *copyOfAdjacencyList = adjList;

    while(copyOfAdjacencyList != NULL)
    {
        graph->vistedNodes[vertex] = 1;
        int vertexConnection = copyOfAdjacencyList->vertex;
        if(graph->vistedNodes[vertexConnection] == 0)
        {
            return 1 + DepthFirstSearch(graph, vertexConnection);
        }

        copyOfAdjacencyList = copyOfAdjacencyList->next;
    }

    return 0;
}

void boardToGraph(char **board, struct Graph *graph, int width, int height, int xPosition, int yPosition, int playerNum, int isMultiEdge)
{
    // Directions from a board cell
    int left = xPosition - 1;
    int up = yPosition - 1;
    int right = xPosition + 1;
    int down = yPosition + 1;
    int areaOne = width * yPosition;

    if((left >= 0) && (up >= 0) && board[up][(left*3)+1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), ((width * up) + left), isMultiEdge);
    }

    if((right < width) && (up >= 0) && board[up][(right * 3) + 1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), ((width * up) + (right)), isMultiEdge);
    }

    if((left >= 0) && board[yPosition][(left * 3)+1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), (areaOne + left), isMultiEdge);
    }

    if((right < width) && board[yPosition][(right * 3) + 1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), (areaOne + left), isMultiEdge);
    }

    if((left >= 0) && (down < height) && board[down][(left * 3) + 1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), ((width * down) + left), isMultiEdge);
    }

    if((down < height) && board[down][(xPosition * 3) + 1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), ((width * down) + xPosition), isMultiEdge);
    }

    if((right < width) && (down < height) && board[down][(right * 3) + 1] == (playerNum + '0'))
    {
        updateGraph(graph, (areaOne + xPosition), ((width * down) + right), isMultiEdge);
    }
}

int graphLength(struct Graph *graph, int vertex)
{
    int gLength = 0;
    struct node *list = graph->adjLists[vertex];
    struct node *tempList = list;

    while(tempList)
    {
        gLength++;
        tempList = tempList->next;
    }

    return gLength;
}

void isVisited(struct Graph *graph)
{
    int verticesCount = graph->numVertices;

    for(int i = 0; i < verticesCount; i++)
    {
        graph->vistedNodes[i] = 0;
    }
}

void freeAdjacencyList(struct Graph *graph, int vertex) {
    while(graph->adjLists[vertex] != NULL) {
        struct node *temp;
        temp = graph->adjLists[vertex];
        graph->adjLists[vertex] = temp->next;
        free(temp);
    }
}

void freeGraph(struct Graph *graph) {
    free(graph->vistedNodes);
    for(int i = 0; i < graph->numVertices; i++) {
        freeAdjacencyList(graph, i);
    }
    free(graph->adjLists);
    free(graph);
}