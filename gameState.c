int horizontalWin(char **board, int width, int height, char playerSymbol)
{
    // Variable to keep track of how many pieces in a row
    int numOfPieces = 0;

    // Loops through each row, checking for 4 in a row horizontally
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(board[i][(j * 3) + 1] == playerSymbol)
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

int verticalWin(char **board, int width, int height, char playerSymbol)
{
    // Variable to keep track of how many pieces are in a row
    int numOfPieces = 0;

    // Loops through each column checking for four in a row vertically.
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(board[j][(i * 3) + 1] == playerSymbol)
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

int diagonalWin(char **board, int width, int height, char playerSymbol)
{
    
}