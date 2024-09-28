/*
 * Here we're creating the board for the game.
 * It will be initialized with 40 slots, like the monopoly board.
 */
// #include "MonopolyBoardGUI.hpp"

#include "Board.hpp"
#include "BoardsSlots/Slot.hpp"
#include "BoardsSlots/Streets.hpp"
#include "BoardsSlots/Station.hpp"
#include "BoardsSlots/Utility.hpp"
#include "BoardsSlots/FreeParking.hpp"
#include "BoardsSlots/Go.hpp"
#include "Player.hpp"

using namespace std;

Board::Board()
{
    slots.reserve(40);

    // GO
    slots.push_back(new Go("GO")); // 0

    // Brown properties
    slots.push_back(new Streets("Mediterranean Avenue", "Property", "Brown", 60, 2, 50, 50)); // 1
    slots.push_back(new Slot("Community Chest"));                                             // 2
    slots.push_back(new Streets("Baltic Avenue", "Property", "Brown", 60, 4, 50, 50));        // 3

    // Income Tax
    slots.push_back(new Slot("Income Tax")); // 4

    // Reading Railroad
    slots.push_back(new Station("Reading Railroad", "Station", 200, 25)); // 5

    // Light Blue properties
    slots.push_back(new Streets("Oriental Avenue", "Property", "Light Blue", 100, 6, 50, 50));    // 6
    slots.push_back(new Slot("Chance"));                                                          // 7
    slots.push_back(new Streets("Vermont Avenue", "Property", "Light Blue", 100, 6, 50, 50));     // 8
    slots.push_back(new Streets("Connecticut Avenue", "Property", "Light Blue", 120, 8, 50, 50)); // 9

    // Just Visiting / In Jail
    slots.push_back(new Slot("Just Visiting / In Jail")); // 10

    // Pink properties
    slots.push_back(new Streets("St. Charles Place", "Property", "Pink", 140, 10, 100, 100)); // 11
    slots.push_back(new Utility("Electric Company", "Utility", 150));                         // 12
    slots.push_back(new Streets("States Avenue", "Property", "Pink", 140, 10, 100, 100));     // 13
    slots.push_back(new Streets("Virginia Avenue", "Property", "Pink", 160, 12, 100, 100));   // 14

    // Pennsylvania Railroad
    slots.push_back(new Station("Pennsylvania Railroad", "Station", 200, 25)); // 15

    // Orange properties
    slots.push_back(new Streets("St. James Place", "Property", "Orange", 180, 14, 100, 100));  // 16
    slots.push_back(new Slot("Community Chest"));                                              // 17
    slots.push_back(new Streets("Tennessee Avenue", "Property", "Orange", 180, 14, 100, 100)); // 18
    slots.push_back(new Streets("New York Avenue", "Property", "Orange", 200, 16, 100, 100));  // 19

    // Free Parking
    slots.push_back(new FreeParking("Free Parking")); // 20

    // Red properties
    slots.push_back(new Streets("Kentucky Avenue", "Property", "Red", 220, 18, 150, 150)); // 21
    slots.push_back(new Slot("Chance"));                                                   // 22
    slots.push_back(new Streets("Indiana Avenue", "Property", "Red", 220, 18, 150, 150));  // 23
    slots.push_back(new Streets("Illinois Avenue", "Property", "Red", 240, 20, 150, 150)); // 24

    // B. & O. Railroad
    slots.push_back(new Station("B. & O. Railroad", "Station", 200, 25)); // 25

    // Yellow properties
    slots.push_back(new Streets("Atlantic Avenue", "Property", "Yellow", 260, 22, 150, 150)); // 26
    slots.push_back(new Streets("Ventnor Avenue", "Property", "Yellow", 260, 22, 150, 150));  // 27
    slots.push_back(new Utility("Water Works", "Utility", 150));                              // 28
    slots.push_back(new Streets("Marvin Gardens", "Property", "Yellow", 280, 24, 150, 150));  // 29

    // Go To Jail
    slots.push_back(new Slot("Go To Jail")); // 30

    // Green properties
    slots.push_back(new Streets("Pacific Avenue", "Property", "Green", 300, 26, 200, 200));        // 31
    slots.push_back(new Streets("North Carolina Avenue", "Property", "Green", 300, 26, 200, 200)); // 32
    slots.push_back(new Slot("Community Chest"));                                                  // 33
    slots.push_back(new Streets("Pennsylvania Avenue", "Property", "Green", 320, 28, 200, 200));   // 34

    // Short Line Railroad
    slots.push_back(new Station("Short Line", "Station", 200, 25)); // 35

    // Chance
    slots.push_back(new Slot("Chance")); // 36

    // Dark Blue properties
    slots.push_back(new Streets("Park Place", "Property", "Dark Blue", 350, 35, 200, 200)); // 37
    slots.push_back(new Slot("Luxury Tax"));                                                // 38
    slots.push_back(new Streets("Boardwalk", "Property", "Dark Blue", 400, 50, 200, 200));  // 39
}

Board::~Board()
{
    for (auto &slot : slots)
    {
        delete slot;
    }
}

vector<Slot *> &Board::getBoard()
{
    return slots;
}

const vector<Slot *> &Board::getBoard() const
{
    return slots;
}

void Board::printBoard()
{
    for (size_t i = 0; i < slots.size(); ++i)
    {
        cout << i << ": " << slots[i]->getName() << endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    runGUI(board);
    return os;
}

/**
 * The GUI is not part of the class, we've put it here for faster compilation
 */
// GUI-related functions
void initializeSlots(const Board &board, std::vector<sf::RectangleShape> &slotShapes, std::vector<sf::Text> &slotTexts, sf::Font &font)
{
    const int BOARD_SIZE = 700;
    const int SLOT_COUNT = 40;
    float slotWidth = BOARD_SIZE / 11.0f;
    float slotHeight = BOARD_SIZE / 11.0f;

    for (int i = 0; i < SLOT_COUNT; ++i)
    {
        sf::RectangleShape shape(sf::Vector2f(slotWidth, slotHeight));
        sf::Text text("", font, 10);

        // Position the slots
        if (i < 11)
        {
            shape.setPosition((10 - i) * slotWidth + 50, BOARD_SIZE - slotHeight + 50);
        }
        else if (i < 21)
        {
            shape.setPosition(50, (20 - i) * slotHeight + 50);
        }
        else if (i < 31)
        {
            shape.setPosition((i - 20) * slotWidth + 50, 50);
        }
        else
        {
            shape.setPosition(BOARD_SIZE - slotWidth + 50, (i - 30) * slotHeight + 50);
        }

        // Set color based on property color
        Slot *slot = board.getBoard()[i];
        sf::Color color = sf::Color::White;
        // if (Streets *street = dynamic_cast<Streets *>(slot))
        if (slot->getType() == "Property")
        {
            Streets *street = dynamic_cast<Streets *>(slot);
            std::string propertyColor = street->getColor();
            if (propertyColor == "Brown")
                color = sf::Color(102, 51, 0);
            else if (propertyColor == "Light Blue")
                color = sf::Color(173, 216, 230);
            else if (propertyColor == "Pink")
                color = sf::Color(255, 192, 203);
            else if (propertyColor == "Orange")
                color = sf::Color(255, 165, 0);
            else if (propertyColor == "Red")
                color = sf::Color::Red;
            else if (propertyColor == "Yellow")
                color = sf::Color::Yellow;
            else if (propertyColor == "Green")
                color = sf::Color::Green;
            else if (propertyColor == "Dark Blue")
                color = sf::Color::Blue;
        }
        // else if (Station *station = dynamic_cast<Station *>(slot)) // Station we'll color it gray
        else if (slot->getType() == "Station")
        {
            color = sf::Color(128, 128, 128);
        }
        // else if (Utility *utility = dynamic_cast<Utility *>(slot)) // Utility we'll color it purple
        else if (slot->getType() == "Utility")
        {
            color = sf::Color(128, 0, 128);
        }
        else if (slot->getName() == "Chance" || slot->getName() == "Community Chest") // Cards will be colored in crem
        {
            color = sf::Color(255, 255, 153);
        }

        shape.setFillColor(color);
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color::Black);

        // Set text
        // text.setString(slot->getName());
        text.setString(slot->toString());
        text.setFillColor(sf::Color::Black);

        // Adjust text size to fit within the slot
        float maxTextWidth = slotWidth - 10;   // Padding of 5 on each side
        float maxTextHeight = slotHeight - 10; // Padding of 5 on each side
        unsigned int characterSize = 10;       // Starting character size

        // Increase character size until the text fits within the slot
        while (true)
        {
            text.setCharacterSize(characterSize);
            sf::FloatRect textBounds = text.getLocalBounds();
            if (textBounds.width > maxTextWidth || textBounds.height > maxTextHeight)
            {
                text.setCharacterSize(characterSize - 1); // Use the previous size
                break;
            }
            characterSize++;
        }

        text.setPosition(shape.getPosition() + sf::Vector2f(5, 5));

        slotShapes.push_back(shape);
        slotTexts.push_back(text);
    }
}

void draw(sf::RenderWindow &window, const std::vector<sf::RectangleShape> &slotShapes, const std::vector<sf::Text> &slotTexts)
{
    for (size_t i = 0; i < slotShapes.size(); ++i)
    {
        window.draw(slotShapes[i]);
        window.draw(slotTexts[i]);
    }
}

void runGUI(const Board &board)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Monopoly Board");
    sf::Font font;
    if (!font.loadFromFile("Arimo-Italic-VariableFont_wght.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    std::vector<sf::RectangleShape> slotShapes;
    std::vector<sf::Text> slotTexts;
    initializeSlots(board, slotShapes, slotTexts, font);

    // Scrollbar properties
    sf::RectangleShape scrollbar(sf::Vector2f(20, 100));
    scrollbar.setPosition(780, 0);
    scrollbar.setFillColor(sf::Color(200, 200, 200));
    scrollbar.setOutlineThickness(1);
    scrollbar.setOutlineColor(sf::Color::Black);

    sf::View view = window.getDefaultView();
    bool isDragging = false;
    float lastMouseY = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0)
                {
                    view.move(0, -20); // Scroll up
                }
                else
                {
                    view.move(0, 20); // Scroll down
                }
                window.setView(view);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (scrollbar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        isDragging = true;
                        lastMouseY = event.mouseButton.y;
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    isDragging = false;
                }
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                if (isDragging)
                {
                    float deltaY = event.mouseMove.y - lastMouseY;
                    scrollbar.move(0, deltaY);
                    lastMouseY = event.mouseMove.y;

                    // Adjust view based on scrollbar position
                    float viewMoveY = deltaY * (700.0f / window.getSize().y); // Adjust this factor as needed
                    view.move(0, viewMoveY);
                    window.setView(view);
                }
            }
        }

        window.clear(sf::Color::White);
        window.setView(view);
        draw(window, slotShapes, slotTexts);
        window.draw(scrollbar);
        window.display();
    }
}
// void runGUI(const Board &board)
// {
//     sf::RenderWindow window(sf::VideoMode(800, 800), "Monopoly Board");
//     sf::Font font;
//     if (!font.loadFromFile("Arimo-Italic-VariableFont_wght.ttf"))
//     {
//         std::cerr << "Error loading font" << std::endl;
//         return;
//     }

//     std::vector<sf::RectangleShape> slotShapes;
//     std::vector<sf::Text> slotTexts;
//     initializeSlots(board, slotShapes, slotTexts, font);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear(sf::Color::White);
//         draw(window, slotShapes, slotTexts);
//         window.display();
//     }
// }