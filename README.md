# Alex Thompson's Connect Four Game

Installation
============

via Cloning
-----------

Navigate to where you would like the game to be stored on your local box.

```
git clone https://github.com/amthompson42010/CS-201-Project-Connect-Four
``` 

via Zip File
------------

Download the zip file and unzip the file to where you would like the game to be stored on your local box.

Running
=======

```
cd CS-201-Project-Connect-Four
./run.sh
```

run.sh is a shell script that will build and run the project.

If you would like to not use the run.sh script, you may run the project as so:

```
cd CS-201-Project-Connect-Four
make
make run
```
or simply,
```
cd CS-201-Project-Connect-Four
make run
```

Cleaning the Solution
=====================

You may clean the solution as so:
```
cd CS-201-Project-Connect-Four
make clean
```

Playing the Game
================

It is recommended to make the terminal full screen so that large boards may render.

If you chose the option above to run the application via the script, then the game automatically boots up.
If you chose the option to not run the script, then folling the run game instructions "make run" will boot up the game.

Which ever method you chose to run the game the terminal should now display:

![alt text](https://github.com/amthompson42010/CS-201-Project-Connect-Four/raw/master/readmePics/mainMenu.PNG "Main Menu")

From this image, you can see that I have already entered in some choices.

Here are the steps on this screen:

1. Enter in an option for what mode you want to play.
    
    1 is for the player versus player mode
    
    2 is for the player versus computer mode
2. Enter in a width of the board that you want to play on.
    
    There is no limit however, for boards with widths greater than 47 there is a message telling the user that the board may
    not render properly for the size they entered.
3. Enter in a height of the board that you want to play on.
    
    There is no limit.

After steps 1-3 are complete the terminal will look like so:

If player versus player option is selected:

![alt text](https://github.com/amthompson42010/CS-201-Project-Connect-Four/raw/master/readmePics/pvp.PNG "PVP") 

If player versus computer option is selected:

![alt text](https://github.com/amthompson42010/CS-201-Project-Connect-Four/raw/master/readmePics/pvc.PNG "PVC")

Both game modes flow in similar patterns, the only difference being in the player versus computer option, there is no required
input for the computer's move.

From here the game is a basic connect four game. You can see via the images above there are numbers under each column.
The prompt that will come up per players turn will ask what column they would like to drop their piece in.
The column that you want to drop your piece in should match the numbers listed under the board.

For Player 1 the connect four piece used is a '1'.
For Player 2 and the Computer the connect four piece used is a '2'.

This helps keep track of which piece is yours when playing.

Winning
=======

The win condition is to have 4 of your pieces in a diagonal, left to right, right to left, or vertically.

Once a player wins they will see a message like the following image asking if they would like to continue:

![alt text](https://github.com/amthompson42010/CS-201-Project-Connect-Four/raw/master/readmePics/continue.PNG "Continue")

Here simply select 1 to play again in which the score will be updated, or select 2, exiting the current game session and clearing the score.