/*
 * Here we're creating the board for the game.
 * It will be initialized with 40 slots, like the monopoly board.
 */

#include "Board.hpp"

using namespace std;
Board::Board()
{
    slots.reserve(40);

    // GO
    slots.push_back(make_unique<Go>("GO"));

    // Brown properties
    slots.push_back(make_unique<Streets>("Mediterranean Avenue", 60, "Brown"));
    slots.push_back(make_unique<Streets>("Baltic Avenue", 60, "Brown"));

    // Income Tax
    slots.push_back(make_unique<Slot>("Income Tax"));

    // Reading Railroad
    slots.push_back(make_unique<Station>("Reading Railroad", 200));

    // Light Blue properties
    slots.push_back(make_unique<Streets>("Oriental Avenue", 100, "Light Blue"));
    slots.push_back(make_unique<Streets>("Vermont Avenue", 100, "Light Blue"));
    slots.push_back(make_unique<Streets>("Connecticut Avenue", 120, "Light Blue"));

    // Just Visiting / In Jail
    slots.push_back(make_unique<Slot>("Just Visiting / In Jail"));

    // Pink properties
    slots.push_back(make_unique<Streets>("St. Charles Place", 140, "Pink"));
    slots.push_back(make_unique<Utility>("Electric Company", 150));
    slots.push_back(make_unique<Streets>("States Avenue", 140, "Pink"));
    slots.push_back(make_unique<Streets>("Virginia Avenue", 160, "Pink"));

    // Pennsylvania Railroad
    slots.push_back(make_unique<Station>("Pennsylvania Railroad", 200));

    // Orange properties
    slots.push_back(make_unique<Streets>("St. James Place", 180, "Orange"));
    slots.push_back(make_unique<Streets>("Tennessee Avenue", 180, "Orange"));
    slots.push_back(make_unique<Streets>("New York Avenue", 200, "Orange"));

    // Free Parking
    slots.push_back(make_unique<FreeParking>("Free Parking"));

    // Red properties
    slots.push_back(make_unique<Streets>("Kentucky Avenue", 220, "Red"));
    slots.push_back(make_unique<Streets>("Indiana Avenue", 220, "Red"));
    slots.push_back(make_unique<Streets>("Illinois Avenue", 240, "Red"));

    // B. & O. Railroad
    slots.push_back(make_unique<Station>("B. & O. Railroad", 200));

    // Yellow properties
    slots.push_back(make_unique<Streets>("Atlantic Avenue", 260, "Yellow"));
    slots.push_back(make_unique<Streets>("Ventnor Avenue", 260, "Yellow"));
    slots.push_back(make_unique<Utility>("Water Works", 150));
    slots.push_back(make_unique<Streets>("Marvin Gardens", 280, "Yellow"));

    // Go To Jail
    slots.push_back(make_unique<Slot>("Go To Jail"));

    // Green properties
    slots.push_back(make_unique<Streets>("Pacific Avenue", 300, "Green"));
    slots.push_back(make_unique<Streets>("North Carolina Avenue", 300, "Green"));
    slots.push_back(make_unique<Streets>("Pennsylvania Avenue", 320, "Green"));

    // Short Line Railroad
    slots.push_back(make_unique<Station>("Short Line", 200));

    // Chance
    slots.push_back(make_unique<Slot>("Chance"));

    // Dark Blue properties
    slots.push_back(make_unique<Streets>("Park Place", 350, "Dark Blue"));
    slots.push_back(make_unique<Slot>("Luxury Tax"));
    slots.push_back(make_unique<Streets>("Boardwalk", 400, "Dark Blue"));
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
