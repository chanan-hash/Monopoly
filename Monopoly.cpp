#include "Monopoly.hpp"
#include <cmath>

// Monopoly::Monopoly()
// {
// }

int Monopoly::diceRoll() const
{
    return (rand() % 6) + 1;
}

void Monopoly::movePlayer(Player &player, Board &board)
{
    int dice1 = diceRoll();
    int dice2 = diceRoll();
    int dice = dice1 + dice2;

    cout << "Player " << player.getName() << " rolled " << dice1 << " and " << dice2 << " for a total of " << dice << endl;

    board.getBoard()[player.getPosition()]->removePlayer(player); // remove the player from the current slot

    player.setPosition((player.getPosition() + dice) % BOARD_SIZE); // for the case of passing the Go slot

    board.getBoard()[player.getPosition()]->addPlayer(player); // add the player to the new slot

    // Now all the checkup
    SlotCheck(player, board);
}

void Monopoly::SlotCheck(Player &player, Board &board)
{
    // Getting the slot from player position
    Slot *slot = board.getBoard()[player.getPosition()];

    // If the slot is a street
    if (slot->getName() == "Property")
    {
        Streets *street = dynamic_cast<Streets *>(slot);
        // Checking if the street is owned
        if (street->getOwnerPtr() != nullptr)
        {
            payStreetRent(player, street->getOwner(), *street);
        }
        else
        {
            cout << "Do you want to buy this street? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                // buyStreet(player, *street);
            }
        }
    }
    /// need to add the other slots

    // Checking if it is a GO slot
    else if (slot->getName() == "Go")
    {
        player.addMoney(400);
    }
}

void Monopoly::payStreetRent(Player &player1, Player &player2, Streets &street)
{
    // Streets *street = dynamic_cast<Streets *>(board.getBoard()[player1.getPosition()]);
    // Checking if the street has houses
    if (street.getHouses() > 0)
    {
        int renth = street.getRent() * pow(2, street.getHouses());
        player1.removeMoney(renth);
        player2.addMoney(renth);
    }
    // Checking if the street has a hotel
    else if (street.getHotel())
    {
        int rentH = (street.getRent() * 10);
        player1.removeMoney(rentH);
        player2.addMoney(rentH);
    }
    else
    {
        int rent = street.getRent();
        player1.removeMoney(rent);
        player2.addMoney(rent);
    }
}
