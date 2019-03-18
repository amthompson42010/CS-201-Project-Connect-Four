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

// int isEmpty() {

// }

void displayBoard(int column, int width, int height){
	for(int a = 1; a < height; a++)
	{
        printf("|");
        for(int b = 1; b <= width; b++)
        {
            printf(" -- ");
            printf("|");
        }
        printf("\n");
        printf("|");
        for(int b = 1; b <= width; b++)
        {
            if(column == b && a == (height-1))
            {
                printf(" X  |");
            }
            else
            {
                printf("    |");   
            }
        }
        printf("\n");
	}
    for(int b = 1; b <= width; b++)
    {
        printf("-----");
    }
    printf("-");
    printf("\n");

    int currWidth = width;
    if(width != 0 || height != 0)
    {
        printf("  1  ");
        currWidth--;
        for(int c = 2; c <= 9; c++)
        {
            if(currWidth != 0)
            {
                printf("  %d  ", c);
                currWidth--;
            }
        }

        currWidth--;
        if(currWidth != 0)
        {
            for(int d = 10; d <= width; d++)
            {
                printf("  %d ", d);
            }
        }
    }
    printf("\n\n\n");
}