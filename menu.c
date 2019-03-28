/**
 * 
 *  Created by Alexander Mark Thompson
 * 
 *  Creates the different menus/screens for the game. 
 *  Modes are set in this file.
 *      Modes:
 *          1. Player versus Player
 *          2. Player versus Computer
 *          3. Instructions
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Modes {
    int mode;
    int width;
    int height;
    int scoreOne;
    int scoreTwo;
} newMode;

void setScreenWidth(struct Modes *newMode, int x);
void setScreenHeight(struct Modes *newMode, int y);

/////////////////////////////////////////////////////////////////////////////
// Simple welcome print
/////////////////////////////////////////////////////////////////////////////
void welcomeScreen() {
    printf(" ######   #######  ##    ## ##    ## ########  ######  ########    ########  #######  ##     ## ########\n");
    printf("##    ## ##     ## ###   ## ###   ## ##       ##    ##    ##       ##       ##     ## ##     ## ##     ##\n");
    printf("##       ##     ## ####  ## ####  ## ##       ##          ##       ##       ##     ## ##     ## ##     ##\n");
    printf("##       ##     ## ## ## ## ## ## ## ######   ##          ##       ######   ##     ## ##     ## ########\n");
    printf("##       ##     ## ##  #### ##  #### ##       ##          ##       ##       ##     ## ##     ## ##   ##\n");
    printf("##    ## ##     ## ##   ### ##   ### ##       ##    ##    ##       ##       ##     ## ##     ## ##    ##\n");
    printf(" ######   #######  ##    ## ##    ## ########  ######     ##       ##        #######   #######  ##     ##\n\n");

    
    printf("Created by Alexander Thompson");
}

int continueGame(int currWidth, int MAX_WIDTH) {
    int cont;
    printf("Warning: %d makes the scale off.\n It is recommended that a number less than or equal to %d.\n Do you want to continue? (y = yes, n = no) ", currWidth, MAX_WIDTH);
    scanf("%d", &cont);

    if(cont == 'y')
    {
        return 1;
    }
    else if(cont == 'n')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Function that prompts the user for the width of the board.
///////////////////////////////////////////////////////////////////////////////
void getScreenWidth(struct Modes *newMode) {
    
    int x;
    // The max width was tested on a full screen terminal of the game running, 
    // on a 21 inch monitor.
    int MAX_WIDTH = 47;

    printf("Please enter the width of the board that you would like: ");
    scanf("%d", &x);

    // Check to make sure x contains a number and not a letter
    if(x != 0)
    {
        if(x > MAX_WIDTH)
        {
            int cont = continueGame(x, MAX_WIDTH);
            if(cont == 1)
            {
                setScreenWidth(newMode, x);
            }
            else if(cont == 2)
            {
                getScreenWidth(newMode);
            }
        }
        else if(x >= 4)
        {
            setScreenWidth(newMode, x);
        }
        else
        {
            printf("You entered a negative number, please enter a positive number.");
            getScreenWidth(newMode);
        }
    }
    else
    {
        printf("The format of what was entered was not a number.");
        getScreenWidth(newMode);
    }
}

///////////////////////////////////////////////////////////////////////////////////
// Function to set the width of the screen.
///////////////////////////////////////////////////////////////////////////////////
void setScreenWidth(struct Modes *newMode, int x)
{
    newMode->width = x;
}

///////////////////////////////////////////////////////////////////////////////////
// Function to prompt the user for the height of the board they want.
///////////////////////////////////////////////////////////////////////////////////
void getScreenHeight(struct Modes *newMode)
{
    int y;

    printf("Please enter the height of the board that you would like: ");
    scanf("%d", &y);
    system("clear");
    printf("\n\n");

    // Check to make sure the user input is a number and not a string.
    if(y != 0)
    {
        setScreenHeight(newMode, y);
    }
    else
    {
        printf("The format of what was entered was not a number.");
        getScreenHeight(newMode);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// Function to set the screen height
/////////////////////////////////////////////////////////////////////////////////////
void setScreenHeight(struct Modes *newMode, int y)
{
    newMode->height = y;
}

//////////////////////////////////////////////////////////////////////////////////
// Function to set the mode
//////////////////////////////////////////////////////////////////////////////////
void setMode(struct Modes *newMode, int mode)
{
    newMode->mode = mode;
}

int getMode(struct Modes *newMode)
{
    return newMode->mode;
}

//////////////////////////////////////////////////////////////////////////////
// Function to get what mode the player wants to play.
// If the number 1 is selected, the player versus player option is set.
// If the number 2 is selected, the player versus computer option is set.
//////////////////////////////////////////////////////////////////////////////
void mainModeOptions(struct Modes *newMode) {

    int mode;

    printf(           
          "                                   1-Player v Player\n"              
          "                                   -------------\n"              
          "                                   2-Player v Computer\n"
          "                                   -----------\n"
          "                                   3-instruction\n"
          "                                   -------------      "
          "                                   \n\n\n");

    printf("Please enter a number from the choices above: ");
    scanf("%d", &mode);

    // Check to make sure x contains a number and not a letter
    if(mode != 0)
    {
        if(mode == 1 || mode == 2 || mode == 3)
        {
            setMode(newMode, mode);
        }
        else
        {
            printf("Error, you have entered an unknown mode. This must be a number between 1 and 3.\n");
            mainModeOptions(newMode);
        }
    }
    else
    {
        printf("You did not enter a number from the menu for a mode.");
        mainModeOptions(newMode);
    }
    

}