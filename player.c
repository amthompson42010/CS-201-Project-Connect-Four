/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  File to handle player creation and actions.
 * 
 */

#include "player.h"

char* allocatePlayerMove(int x)
{
    char* move = malloc(x * 3 * sizeof(char));

    return player;
}

int getScore(struct newPlayer* player)
{
    return player->score;
}

int getLastRow(struct newPlayer* player)
{
    return player->lastRow;
}

int getLastColumn(struct newPlayer* player)
{
    return player->lastColumn;
}

void setScore(struct newPlayer* player, int score)
{
    player->score = score;
}

void setLastRow(struct newPlayer* player, int row)
{
    player->lastRow = row;
}

void setLastColumn(struct newPlayer* player, int column)
{
    player->lastColumn = column;
}