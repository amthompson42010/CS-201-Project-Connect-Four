/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Header file for menu.c
 *  Also creates a struct for Modes.
 * 
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct Modes {
    int mode;
    int width;
    int height;
    int scoreOne;
    int scoreTwo;
} newMode;

extern void mainModeOptions();
extern void welcomeScreen();
extern void setMode(struct Modes *newMode, int mode);
extern void getScreenWidth(struct Modes *newMode);
extern void setScreenWidth(struct Modes *newMode, int x);
extern void getScreenHeight(struct Modes *newMode);
extern void setScreenHeight(struct Modes *newMode, int y);


#endif