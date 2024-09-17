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
#include "BoardsSlots/Go.cpp"
#include "Player.hpp"


using namespace std;
Board::Board()
{
    slots.reserve(40);

    // GO
    slots.push_back(make_unique<Go>("GO"));

    // Brown properties
    slots.push_back(make_unique<Streets>("Mediterranean Avenue", "Property", "Brown", 60, 2, 50, 50));
    slots.push_back(make_unique<Streets>("Baltic Avenue", "Property", "Brown", 60, 4, 50, 50));

    // Income Tax
    slots.push_back(make_unique<Slot>("Income Tax"));

    // Reading Railroad
    slots.push_back(make_unique<Station>("Reading Railroad","Station", 200));

    // Light Blue properties
    slots.push_back(make_unique<Streets>("Oriental Avenue", "Property", "Light Blue", 100, 6, 50, 50));
    slots.push_back(make_unique<Streets>("Vermont Avenue", "Property", "Light Blue", 100, 6, 50, 50));
    slots.push_back(make_unique<Streets>("Connecticut Avenue", "Property", "Light Blue", 120, 8, 50, 50));

    // Just Visiting / In Jail
    slots.push_back(make_unique<Slot>("Just Visiting / In Jail"));

    // Pink properties
    slots.push_back(make_unique<Streets>("St. Charles Place", "Property", "Pink", 140, 10, 100, 100));
    slots.push_back(make_unique<Utility>("Electric Company","Utility", 150));
    slots.push_back(make_unique<Streets>("States Avenue", "Property", "Pink", 140, 10, 100, 100));
    slots.push_back(make_unique<Streets>("Virginia Avenue", "Property", "Pink", 160, 12, 100, 100));

    // Pennsylvania Railroad
    slots.push_back(make_unique<Station>("Pennsylvania Railroad","Station", 200));

    // Orange properties
    slots.push_back(make_unique<Streets>("St. James Place", "Property", "Orange", 180, 14, 100, 100));
    slots.push_back(make_unique<Streets>("Tennessee Avenue", "Property", "Orange", 180, 14, 100, 100));
    slots.push_back(make_unique<Streets>("New York Avenue", "Property", "Orange", 200, 16, 100, 100));

    // Free Parking
    slots.push_back(make_unique<FreeParking>("Free Parking"));

    // Red properties
    slots.push_back(make_unique<Streets>("Kentucky Avenue", "Property", "Red", 220, 18, 150, 150));
    slots.push_back(make_unique<Streets>("Indiana Avenue", "Property", "Red", 220, 18, 150, 150));
    slots.push_back(make_unique<Streets>("Illinois Avenue", "Property", "Red", 240, 20, 150, 150));

    // B. & O. Railroad
    slots.push_back(make_unique<Station>("B. & O. Railroad","Station", 200));

    // Yellow properties
    slots.push_back(make_unique<Streets>("Atlantic Avenue", "Property", "Yellow", 260, 22, 150, 150));
    slots.push_back(make_unique<Streets>("Ventnor Avenue", "Property", "Yellow", 260, 22, 150, 150));
    slots.push_back(make_unique<Utility>("Water Works","Utility", 150));
    slots.push_back(make_unique<Streets>("Marvin Gardens", "Property", "Yellow", 280, 24, 150, 150));

    // Go To Jail
    slots.push_back(make_unique<Slot>("Go To Jail"));

    // Green properties
    slots.push_back(make_unique<Streets>("Pacific Avenue", "Property", "Green", 300, 26, 200, 200));
    slots.push_back(make_unique<Streets>("North Carolina Avenue", "Property", "Green", 300, 26, 200, 200));
    slots.push_back(make_unique<Streets>("Pennsylvania Avenue", "Property", "Green", 320, 28, 200, 200));

    // Short Line Railroad
    slots.push_back(make_unique<Station>("Short Line","Station", 200));

    // Chance
    slots.push_back(make_unique<Slot>("Chance"));

    // Dark Blue properties
    slots.push_back(make_unique<Streets>("Park Place", "Property", "Dark Blue", 350, 35, 200, 200));
    slots.push_back(make_unique<Slot>("Luxury Tax"));
    slots.push_back(make_unique<Streets>("Boardwalk", "Property", "Dark Blue", 400, 50, 200, 200));
}


vector<unique_ptr<Slot>> &Board::getBoard()
{
    return slots;
}

const vector<unique_ptr<Slot>> &Board::getBoard() const
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

// friend operator << printing with gui
