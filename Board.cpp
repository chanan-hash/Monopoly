// Authors: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/*
 * Here we're creating the board for the game.
 * It will be initialized with 40 slots, like the monopoly board.
 */

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
    const int BOARD_SIZE = 1200;
    const int SLOT_COUNT = 40;            // The number of slots on regular Monopoly board
    float slotWidth = BOARD_SIZE / 11.0f; // For making it the same order as monopoly board
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
        shape.setOutlineThickness(2); // The outline of the slot's thickness
        shape.setOutlineColor(sf::Color::Black);

        // Set text
        // Get the slot type and owner information
        std::string slotType = slot->getType();
        std::string ownerInfo = "Owner: None";

        // Check if the slot is a Street, Station, or Utility
        if (slotType == "Property")
        {
            Streets *street = dynamic_cast<Streets *>(slot);
            if (street)
            {
                Player *owner = street->getOwnerPtr();
                if (owner != nullptr)
                {
                    ownerInfo = "Owner: " + owner->getName();
                }
            }
        }
        else if (slotType == "Station")
        {
            Station *station = dynamic_cast<Station *>(slot);
            if (station)
            {
                Player *owner = station->getOwnerPtr();
                if (owner != nullptr)
                {
                    ownerInfo = "Owner: " + owner->getName();
                }
            }
        }
        else if (slotType == "Utility")
        {
            Utility *utility = dynamic_cast<Utility *>(slot);
            if (utility)
            {
                Player *owner = utility->getOwnerPtr();
                if (owner != nullptr)
                {
                    ownerInfo = "Owner: " + owner->getName();
                }
            }
        }
        else if (slot->getName() == "Free Parking" || slot->getName() == "GO" || slot->getName() == "Just Visiting / In Jail" || slot->getName() == "Go To Jail" || slot->getName() == "Chance" || slot->getName() == "Community Chest" || slot->getName() == "Luxury Tax" || slot->getName() == "Income Tax")
        {
            ownerInfo = "";
        }

        text.setString(slot->toString() + "\n" + ownerInfo);
        text.setFillColor(sf::Color::Black);

        // Adjust text size to fit within the slot
        float maxTextWidth = slotWidth - 10;   // Padding of 5 on each side
        float maxTextHeight = slotHeight - 10; // Padding of 5 on each side
        unsigned int characterSize = 12;       // Starting character size

        // Increase character size until the text fits within the slot
        while (characterSize > 6)
        {
            text.setCharacterSize(characterSize);
            sf::FloatRect textBounds = text.getLocalBounds();
            if (textBounds.width <= maxTextWidth && textBounds.height <= maxTextHeight)
            {
                break;
            }
            characterSize--;
        }

        // text.setPosition(shape.getPosition() + sf::Vector2f(5, 5));

        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text.setPosition(shape.getPosition().x + slotWidth / 2.0f, shape.getPosition().y + slotHeight / 2.0f);

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
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Monopoly Board"); // Increased window size
    sf::Font font;
    if (!font.loadFromFile("Arimo-Italic-VariableFont_wght.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    std::vector<sf::RectangleShape> slotShapes;
    std::vector<sf::Text> slotTexts;
    initializeSlots(board, slotShapes, slotTexts, font);

    sf::View view(sf::FloatRect(0, 0, 1000, 1000));
    window.setView(view);

    sf::Clock clock;         // For controlling panning speed
    float panSpeed = 300.0f; // Increase the pan speed

    while (window.isOpen())
    {

        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.delta > 0)
                    view.zoom(0.95f);
                else
                    view.zoom(1.05f);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Middle)
                {
                    // Reset zoom and position
                    view = sf::View(sf::FloatRect(0, 0, 1000, 1000));
                }
            }
        }

        // moving quickly with arrow keys
        // // Pan the view with arrow keys
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        //     view.move(-5.0f, 0.0f);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        //     view.move(5.0f, 0.0f);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        //     view.move(0.0f, -5.0f);
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        //     view.move(0.0f, 5.0f);

        // Pan the view with arrow keys (slower movement)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            view.move(-panSpeed * dt, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            view.move(panSpeed * dt, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            view.move(0.0f, -panSpeed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            view.move(0.0f, panSpeed * dt);

        window.clear(sf::Color::White);
        window.setView(view);
        draw(window, slotShapes, slotTexts);
        window.display();
    }
}
