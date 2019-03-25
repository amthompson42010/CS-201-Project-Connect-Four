/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle creating the board, and handling operations
 *  done on the board.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "board.h"

char **createBoard(int width, int height)
{
    char **board = malloc(height * sizeof(char *));
    for(int i = 0; i < height; i++)
    {
        board[i] = malloc(width * 3 * sizeof(char));
    }

    int count = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (width * 3); j++)
        {
            if(count == 0)
            {
                board[i][j] = '[';
                count++;
            }
            else if(count == 1)
            {
                board[i][j] = ' ';
                count++;
            }
            else
            {
                board[i][j] = ']';
                count = 0;
            }
        }
    }

    return board;
}

void displayBoard(char **board, int width, int height){
    printf("\n");
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width * 3; j++)
        {
            printf("%c", board[i][j]);
        }

        printf("\n");
    }
    printf("\n\n");
}