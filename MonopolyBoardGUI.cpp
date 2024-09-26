#include "MonopolyBoardGUI.hpp"
#include "BoardsSlots/Streets.hpp"
#include <stdexcept>

MonopolyBoardGUI::MonopolyBoardGUI(Board& b) 
    : board(b), window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Monopoly Board") {
    if (!font.loadFromFile("Arimo-Italic-VariableFont_wght.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    initializeSlots();
}

void MonopolyBoardGUI::initializeSlots() {
    float slotWidth = BOARD_SIZE / 11.0f;
    float slotHeight = BOARD_SIZE / 11.0f;

    for (int i = 0; i < SLOT_COUNT; ++i) {
        sf::RectangleShape shape(sf::Vector2f(slotWidth, slotHeight));
        sf::Text text("", font, 10);

        // Position the slots
        if (i < 11) {
            shape.setPosition((10 - i) * slotWidth + 50, BOARD_SIZE - slotHeight + 50);
        } else if (i < 21) {
            shape.setPosition(50, (20 - i) * slotHeight + 50);
        } else if (i < 31) {
            shape.setPosition((i - 20) * slotWidth + 50, 50);
        } else {
            shape.setPosition(BOARD_SIZE - slotWidth + 50, (i - 30) * slotHeight + 50);
        }

        // Set color based on property color
        Slot* slot = board.getBoard()[i];
        sf::Color color = sf::Color::White;
        if (Streets* street = dynamic_cast<Streets*>(slot)) {
            std::string propertyColor = street->getColor();
            if (propertyColor == "Brown") color = sf::Color(165, 42, 42);
            else if (propertyColor == "Light Blue") color = sf::Color(173, 216, 230);
            else if (propertyColor == "Pink") color = sf::Color(255, 192, 203);
            else if (propertyColor == "Orange") color = sf::Color(255, 165, 0);
            else if (propertyColor == "Red") color = sf::Color::Red;
            else if (propertyColor == "Yellow") color = sf::Color::Yellow;
            else if (propertyColor == "Green") color = sf::Color::Green;
            else if (propertyColor == "Dark Blue") color = sf::Color::Blue;
        }
        shape.setFillColor(color);
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color::Black);

        // Set text
        text.setString(slot->getName());
        text.setFillColor(sf::Color::Black);
        text.setPosition(shape.getPosition() + sf::Vector2f(5, 5));

        slotShapes.push_back(shape);
        slotTexts.push_back(text);
    }
}

void MonopolyBoardGUI::draw() {
    window.clear(sf::Color::White);

    for (const auto& shape : slotShapes) {
        window.draw(shape);
    }

    for (const auto& text : slotTexts) {
        window.draw(text);
    }

    window.display();
}

void MonopolyBoardGUI::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        draw();
    }
}

// Define the operator<< overload
// std::ostream& operator<<(std::ostream& os, Board& board) {
//     MonopolyBoardGUI gui(board);
//     gui.run();
//     return os;
// }