#include "computer.h"

newComputer* createComputer()
{
    struct newComputer* computer = malloc(sizeof(struct newComputer));
    computer->score = 0;
    computer->lastColumn = 0;
    computer->lastRow = 0;
}

int getScore(newComputer* computer)
{
    return computer->score;
}

int getLastColumn(newComputer* computer)
{
    return computer->lastColumn;
}

int getLastRow(newComputer* computer)
{
    return computer->lastRow;
}

void setScore(newComputer* computer, int score)
{
    computer->score = score;
}

void setLastColumn(newComputer* computer, int lastColumn)
{
    computer->lastColumn = lastColumn;
}

void setLastRow(newComputer* computer, int lastRow)
{
    computer->lastRow = lastRow;
}