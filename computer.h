
#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

typedef struct newComputer {
    int score;
    int lastColumn;
    int lastRow;
} newComputer;

extern newComputer* createComputer();
extern int getScore(newComputer* computer);
extern int getLastColumn(newComputer* computer);
extern int getLastRow(newComputer* computer);
extern void setScore(newComputer* computer, int score);
extern void setLastColumn(newComputer* computer, int lastColumn);
extern void setLastRow(newComputer* computer, int lastRow);

#endif