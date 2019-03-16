#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// int isEmpty() {

// }

void displayBoard(int width, int height){
    printf("width: %d, height: %d \n\n", width, height);
	for(int a = 1; a < height; a++)
	{
        printf("|");
        for(int b = 1; b < width; b++)
        {
            printf(" -- ");
            printf("|");
        }
        printf("\n");
        printf("|");
        for(int b = 1; b < width; b++)
        {
            printf("    |");
        }
        printf("\n");
	}
    for(int b = 1; b < width; b++)
    {
        printf("-----");
    }
    printf("-");
    printf("\n");
    printf("  1");
    for(int c = 2; c <= 9; c++)
    {
        printf("    %d ", c);
    }
    printf("\n");
}