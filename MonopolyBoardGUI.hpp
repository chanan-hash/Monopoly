#ifndef MONOPOLY_BOARD_GUI_HPP
#define MONOPOLY_BOARD_GUI_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include <vector>

class MonopolyBoardGUI {
private:
    sf::RenderWindow window;
    Board& board;
    std::vector<sf::RectangleShape> slotShapes;
    std::vector<sf::Text> slotTexts;
    sf::Font font;

    const int WINDOW_SIZE = 800;
    const int BOARD_SIZE = 700;
    const int SLOT_COUNT = 40;

    void initializeSlots();
    void draw();

public:
    MonopolyBoardGUI(Board& b);
    void run();
};

// Declare the operator<< overload
std::ostream& operator<<(std::ostream& os, Board& board);

#endif // MONOPOLY_BOARD_GUI_HPP