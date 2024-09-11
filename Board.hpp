/*
* This class represents a simple game board
* The board is made up of 40 squares.
* Each square has a name, a type, and a price
* The board will be a vector of squares, and to go from one square to the next, we will use the index of the square in the vector
* The board will have a method to move a player from one square to the next, it will be cyclic, so if the player is on the last square and moves one more square, it will go to the first square
* It will also have a method to print the board.
*/

#include<iostream>


// friend operator << printing with gui