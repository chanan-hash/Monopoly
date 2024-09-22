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
// Board::Board()
// {
//     slots.reserve(40);

//     // GO
//     slots.push_back(make_unique<Go>("GO"));

//     // Brown properties
//     slots.push_back(make_unique<Streets>("Mediterranean Avenue", "Property", "Brown", 60, 2, 50, 50));
//     slots.push_back(make_unique<Streets>("Baltic Avenue", "Property", "Brown", 60, 4, 50, 50));

//     // Income Tax
//     slots.push_back(make_unique<Slot>("Income Tax"));

//     // Reading Railroad
//     slots.push_back(make_unique<Station>("Reading Railroad", "Station", 200, 25));

//     // Light Blue properties
//     slots.push_back(make_unique<Streets>("Oriental Avenue", "Property", "Light Blue", 100, 6, 50, 50));
//     slots.push_back(make_unique<Streets>("Vermont Avenue", "Property", "Light Blue", 100, 6, 50, 50));
//     slots.push_back(make_unique<Streets>("Connecticut Avenue", "Property", "Light Blue", 120, 8, 50, 50));

//     // Just Visiting / In Jail
//     slots.push_back(make_unique<Slot>("Just Visiting / In Jail"));

//     // Pink properties
//     slots.push_back(make_unique<Streets>("St. Charles Place", "Property", "Pink", 140, 10, 100, 100));
//     slots.push_back(make_unique<Utility>("Electric Company", "Utility", 150));
//     slots.push_back(make_unique<Streets>("States Avenue", "Property", "Pink", 140, 10, 100, 100));
//     slots.push_back(make_unique<Streets>("Virginia Avenue", "Property", "Pink", 160, 12, 100, 100));

//     // Pennsylvania Railroad
//     slots.push_back(make_unique<Station>("Pennsylvania Railroad", "Station", 200, 25));

//     // Orange properties
//     slots.push_back(make_unique<Streets>("St. James Place", "Property", "Orange", 180, 14, 100, 100));
//     slots.push_back(make_unique<Streets>("Tennessee Avenue", "Property", "Orange", 180, 14, 100, 100));
//     slots.push_back(make_unique<Streets>("New York Avenue", "Property", "Orange", 200, 16, 100, 100));

//     // Free Parking
//     slots.push_back(make_unique<FreeParking>("Free Parking"));

//     // Red properties
//     slots.push_back(make_unique<Streets>("Kentucky Avenue", "Property", "Red", 220, 18, 150, 150));
//     slots.push_back(make_unique<Streets>("Indiana Avenue", "Property", "Red", 220, 18, 150, 150));
//     slots.push_back(make_unique<Streets>("Illinois Avenue", "Property", "Red", 240, 20, 150, 150));

//     // B. & O. Railroad
//     slots.push_back(make_unique<Station>("B. & O. Railroad", "Station", 200, 25));

//     // Yellow properties
//     slots.push_back(make_unique<Streets>("Atlantic Avenue", "Property", "Yellow", 260, 22, 150, 150));
//     slots.push_back(make_unique<Streets>("Ventnor Avenue", "Property", "Yellow", 260, 22, 150, 150));
//     slots.push_back(make_unique<Utility>("Water Works", "Utility", 150));
//     slots.push_back(make_unique<Streets>("Marvin Gardens", "Property", "Yellow", 280, 24, 150, 150));

//     // Go To Jail
//     slots.push_back(make_unique<Slot>("Go To Jail"));

//     // Green properties
//     slots.push_back(make_unique<Streets>("Pacific Avenue", "Property", "Green", 300, 26, 200, 200));
//     slots.push_back(make_unique<Streets>("North Carolina Avenue", "Property", "Green", 300, 26, 200, 200));
//     slots.push_back(make_unique<Streets>("Pennsylvania Avenue", "Property", "Green", 320, 28, 200, 200));

//     // Short Line Railroad
//     slots.push_back(make_unique<Station>("Short Line", "Station", 200, 25));

//     // Chance
//     slots.push_back(make_unique<Slot>("Chance"));

//     // Dark Blue properties
//     slots.push_back(make_unique<Streets>("Park Place", "Property", "Dark Blue", 350, 35, 200, 200));
//     slots.push_back(make_unique<Slot>("Luxury Tax"));
//     slots.push_back(make_unique<Streets>("Boardwalk", "Property", "Dark Blue", 400, 50, 200, 200));
// }

// vector<unique_ptr<Slot>> &Board::getBoard()
// {
//     return slots;
// }

// const vector<unique_ptr<Slot>> &Board::getBoard() const
// {
//     return slots;
// }

// void Board::printBoard()
// {
//     for (size_t i = 0; i < slots.size(); ++i)
//     {
//         cout << i << ": " << slots[i]->getName() << endl;
//     }
// }

Board::Board()
{
    slots.reserve(40);

    // GO
    slots.push_back(new Go("GO")); // 0

    // Brown properties
    slots.push_back(new Streets("Mediterranean Avenue", "Property", "Brown", 60, 2, 50, 50)); // 1
    slots.push_back(new Slot("Community Chest")); // 2
    slots.push_back(new Streets("Baltic Avenue", "Property", "Brown", 60, 4, 50, 50)); // 3

    // Income Tax
    slots.push_back(new Slot("Income Tax")); // 4

    // Reading Railroad
    slots.push_back(new Station("Reading Railroad", "Station", 200, 25)); // 5

    // Light Blue properties
    slots.push_back(new Streets("Oriental Avenue", "Property", "Light Blue", 100, 6, 50, 50)); // 6
    slots.push_back(new Slot("Chance")); // 7
    slots.push_back(new Streets("Vermont Avenue", "Property", "Light Blue", 100, 6, 50, 50));  // 8
    slots.push_back(new Streets("Connecticut Avenue", "Property", "Light Blue", 120, 8, 50, 50)); // 9

    // Just Visiting / In Jail
    slots.push_back(new Slot("Just Visiting / In Jail")); // 10

    // Pink properties
    slots.push_back(new Streets("St. Charles Place", "Property", "Pink", 140, 10, 100, 100)); // 11
    slots.push_back(new Utility("Electric Company", "Utility", 150)); // 12
    slots.push_back(new Streets("States Avenue", "Property", "Pink", 140, 10, 100, 100)); // 13
    slots.push_back(new Streets("Virginia Avenue", "Property", "Pink", 160, 12, 100, 100)); // 14

    // Pennsylvania Railroad
    slots.push_back(new Station("Pennsylvania Railroad", "Station", 200, 25)); // 15

    // Orange properties
    slots.push_back(new Streets("St. James Place", "Property", "Orange", 180, 14, 100, 100)); // 16
    slots.push_back(new Slot("Community Chest")); // 17
    slots.push_back(new Streets("Tennessee Avenue", "Property", "Orange", 180, 14, 100, 100)); // 18
    slots.push_back(new Streets("New York Avenue", "Property", "Orange", 200, 16, 100, 100)); // 19

    // Free Parking
    slots.push_back(new FreeParking("Free Parking")); // 20

    // Red properties
    slots.push_back(new Streets("Kentucky Avenue", "Property", "Red", 220, 18, 150, 150)); // 21
    slots.push_back(new Slot("Chance")); // 22
    slots.push_back(new Streets("Indiana Avenue", "Property", "Red", 220, 18, 150, 150)); // 23
    slots.push_back(new Streets("Illinois Avenue", "Property", "Red", 240, 20, 150, 150)); // 24

    // B. & O. Railroad
    slots.push_back(new Station("B. & O. Railroad", "Station", 200, 25)); // 25

    // Yellow properties
    slots.push_back(new Streets("Atlantic Avenue", "Property", "Yellow", 260, 22, 150, 150)); // 26
    slots.push_back(new Streets("Ventnor Avenue", "Property", "Yellow", 260, 22, 150, 150)); // 27
    slots.push_back(new Utility("Water Works", "Utility", 150)); // 28
    slots.push_back(new Streets("Marvin Gardens", "Property", "Yellow", 280, 24, 150, 150)); // 29

    // Go To Jail
    slots.push_back(new Slot("Go To Jail")); // 30

    // Green properties
    slots.push_back(new Streets("Pacific Avenue", "Property", "Green", 300, 26, 200, 200)); // 31
    slots.push_back(new Streets("North Carolina Avenue", "Property", "Green", 300, 26, 200, 200)); // 32
    slots.push_back(new Slot("Community Chest")); // 33
    slots.push_back(new Streets("Pennsylvania Avenue", "Property", "Green", 320, 28, 200, 200)); // 34

    // Short Line Railroad
    slots.push_back(new Station("Short Line", "Station", 200, 25)); // 35

    // Chance
    slots.push_back(new Slot("Chance")); // 36

    // Dark Blue properties
    slots.push_back(new Streets("Park Place", "Property", "Dark Blue", 350, 35, 200, 200)); // 37
    slots.push_back(new Slot("Luxury Tax")); // 38
    slots.push_back(new Streets("Boardwalk", "Property", "Dark Blue", 400, 50, 200, 200)); // 39
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

Board::~Board()
{
    for (auto &slot : slots)
    {
        delete slot;
    }
}
