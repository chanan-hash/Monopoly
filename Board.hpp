// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/*
 * This class represents a simple game board
 * The board is made up of 40 squares.
 * Each square has a name, a type, and a price
 * The board will be a vector of squares, and to go from one square to the next, we will use the index of the square in the vector
 * The board will have a method to move a player from one square to the next, it will be cyclic, so if the player is on the last square and moves one more square, it will go to the first square
 * It will also have a method to print the board.
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Slot;
class Streets;
class Station;
class Utility;
class FreeParking;
class Go;
// class Player;

class Board
{
private:
    vector<Slot *> slots; // A vector of slots, it will be initialized with 40 slots, like the monopoly board

public:
    Board(); // Constructor
    ~Board(); // Destructor
    vector<Slot *> &getBoard();
    const vector<Slot *> &getBoard() const;
    void printBoard(); // Method to print the board
    friend ostream &operator<<(ostream &os, const Board &board); // printing with gui
};

void initializeSlots(const Board &board, std::vector<sf::RectangleShape> &slotShapes, std::vector<sf::Text> &slotTexts, sf::Font &font);
void draw(sf::RenderWindow &window, const std::vector<sf::RectangleShape> &slotShapes, const std::vector<sf::Text> &slotTexts);
void runGUI(const Board &board);

#endif // BOARD_HPP
