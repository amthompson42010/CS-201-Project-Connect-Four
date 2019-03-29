/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle the different game modes of connect four.
 * 
 */

#include "adjacencyList.h"
#include "board.h"
#include "player.h"
#include "gameModes.h"
#include "playGame.h"

/////////////////////////////////////////////////
//    Player versus Player
/////////////////////////////////////////////////
void pvp(struct Modes *mode)
{
    start(mode, 0, 0);
}

////////////////////////////////////////////////
//    Player versus Computer
////////////////////////////////////////////////
void pvc(struct Modes *mode)
{
    start(mode, 0, 0);
}


////////////////////////////////////////////////
// Replay Options
////////////////////////////////////////////////
int playAgain()
{
    int again;
    printf("Would you like to play again? (1 = yes, 2 = no) ");
    
    if(scanf("%d", &again) == 1)
    {
        again = again;
    }
    else
    {
        printf("\nThe input you have given is not a possible choice\n");
        getchar();
        again = playAgain();
    }

    return again;
   
}