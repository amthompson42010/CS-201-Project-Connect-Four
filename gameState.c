int horizontalWin(char **board, int width, int height, int whatPlayer)
{
    // Variable to keep track of how many pieces in a row
    int numOfPieces = 0;

    // Loops through each row, checking for 4 in a row horizontally
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(board[i][(j * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            // Winning condition
            if(numOfPieces == 4)
            {
                return 1;
            }
        }
    }

    return 0;
}

int verticalWin(char **board, int width, int height, int whatPlayer)
{
    // Variable to keep track of how many pieces are in a row
    int numOfPieces = 0;

    // Loops through each column checking for four in a row vertically.
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(board[j][(i * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            // Winning condition
            if(numOfPieces == 4)
            {
                return 1;
            }
        }
    }

    return 0;
}


/**
 *
 * Checks for a diagonal four different ways
 * 
 *    1. Starting at bottom left cell of board [0th cell], moving diagonal right then up 
 *       counting the number of pieces.
 *    2. Starting at the 1st cell, moving left to right for each row checking for the diagonal.
 *    3. Doing the same thing as the 1st method only doing it backwards to check for 
 *       diagonals going from right to left.
 *    4. Doing the same thing as the 2nd method, but backwards checking for diagonals reading 
 *       right to left.
 * 
 */
int diagonalWin(char **board, int width, int height, int whatPlayer)
{
    int checkXPos = 0, checkYPos = 0, numOfPieces = 0;

    // LOOP 1
    // Starts a bottom left cell, and checks diagonally for the number of pieces
    // going towards the top right
    for(int i = 0; i < height; i++)
    {
        checkYPos = i;
        while(checkXPos < width && checkYPos < height)
        {
            if(board[checkYPos][(checkXPos * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            if(numOfPieces == 4)
            {
                return 1;
            }

            checkXPos++;
            checkYPos++;
            
        }
    }

    // LOOP 2
    // Starts at the first cell because the 0th cell has already been checked.
    // Moves right, checking for each diagonal, and does the same thing for each row
    // on the board.
    for(int i = 1; i < width; i++)
    {
        checkXPos = i;

        while(checkXPos < width && checkYPos < height)
        {
            if(board[checkYPos][(checkXPos * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            if(numOfPieces == 4)
            {
                return 1;
            }

            checkXPos++;
            checkYPos++;
            
        }
    }

    // LOOP 3
    // Does the same thing as LOOP 1, but going towards top left for the diagonal.
    for(int i = 0; i < height; i++)
    {
        checkXPos = width - 1;
        checkYPos = i;

        while(checkXPos >= 0 && checkYPos < height)
        {
            if(board[checkYPos][(checkXPos * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            if(numOfPieces == 4)
            {
                return 1;
            }

            checkXPos++;
            checkYPos++;
            
        }
    }

    // LOOP 4
    // Does the same thing as LOOP 2, but reads from right to left.
    // Starting at width - 2, because the diagonal on width - 1 was already checked.
    for(int i = width -2; i > 0; i--)
    {
        checkXPos = i;

        while(checkXPos >= 0 && checkYPos < height)
        {
            if(board[checkYPos][(checkXPos * 3) + 1] == (whatPlayer + '0'))
            {
                numOfPieces++;
            }
            else
            {
                numOfPieces = 0;
            }

            if(numOfPieces == 4)
            {
                return 1;
            }

            checkXPos++;
            checkYPos++;
            
        }
        
    }

    return 0;
}