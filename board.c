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
#include "player.h"

int isFull(char **board, int width)
{
    int checkForFull = 1;

    for(int i = 0; i < width; i++)
    {
        if(board[0][(i * 3) + 1] == ' ')
        {
            checkForFull = 0;
        }
    }

    return checkForFull;
}

void updateBoard(char **board, struct newPlayer *player, int x, int y, int xPos, int yPos, int playerNum) {
    
        if(board[0][(xPos * 3) + 1] == ' ')
        {
            int validSpace = 0;
            while(!validSpace && yPos >= 0)
            {
                if(board[yPos][(xPos * 3) + 1] == ' ')
                {
                    validSpace = 1;
                }
                else
                {
                    yPos--;
                }
                
            }
            board[yPos][(xPos * 3) + 1] = playerNum + '0';

        }
        else
        {
            printf("This column space is full.\n");
        }
        
}

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
    for(int k = 0; k < width; k++)
    {
        if(k <= 9)
        {
            printf(" %d ", k);
        }
        else
        {
            printf(" %d", k);
        }
        
    }
    printf("\n\n");
}