#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern int getScore(struct newPlayer* player);
extern int getLastRow(struct newPlayer* player);
extern int getLastColumn(struct newPlayer* player);
extern void setScore(struct newPlayer* player, int score);
extern void setLastRow(struct newPlayer* player, int row);
extern void setLastColumn(struct newPlayer* player, int column);
extern char* allocatePlayerMove(int x);
extern void setPlayerMove(char *move, int x, char playerSymbol);

#endif