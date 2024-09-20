#include "Monopoly.hpp"
#include <cmath>
#include <sstream>
#include <string>

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

    // need to check if the player is in jail
    bool inJail = player.getIsInJail();
    if (!inJail)
    {

        int oldPosition = player.getPosition(); // for checking if the player passed the Go slot

        cout << "Player " << player.getName() << " rolled " << dice1 << " and " << dice2 << " for a total of " << dice << endl;

        board.getBoard()[player.getPosition()]->removePlayer(player); // remove the player from the current slot

        player.setPosition((player.getPosition() + dice) % BOARD_SIZE); // for the case of passing the Go slot

        board.getBoard()[player.getPosition()]->addPlayer(player); // add the player to the new slot

        // check if the player passed the Go slot
        if (oldPosition > player.getPosition())
        {
            Go *go = dynamic_cast<Go *>(board.getBoard()[0]);
            go->add200(player);
        }

        // Now all the checkup
        SlotCheck(player, board, dice);
    }

    // if the player is in jail but rolled a double
    else if (inJail && (dice1 == dice2))
    {
        // player.setIsInJail(false);
        // int oldPosition = player.getPosition(); // for checkups

        // cout << "Player " << player.getName() << " rolled " << dice1 << " and " << dice2 << " for a total of " << dice << endl;

        // board.getBoard()[player.getPosition()]->removePlayer(player); // remove the player from the current slot

        // player.setPosition((player.getPosition() + dice) % BOARD_SIZE); // for the case of passing the Go slot

        // board.getBoard()[player.getPosition()]->addPlayer(player); // add the player to the new slot

        // // check if the player passed the Go slot
        // if (oldPosition > player.getPosition())
        // {
        //     Go *go = dynamic_cast<Go *>(board.getBoard()[0]);
        //     go->add200(player);
        // }

        // // Now all the checkup
        // SlotCheck(player, board);
    }
    else
    {
        cout << "Player " << player.getName() << " is in jail" << endl;
    }
}

void Monopoly::SlotCheck(Player &player, Board &board, int dice)
{
    // Getting the slot from player position
    Slot *slot = board.getBoard()[player.getPosition()];

    cout << "Player " << player.getName() << " landed on " << slot->getName() << endl;

    // If the slot is a street
    if (slot->getType() == "Property")
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
                buyStreet(player, *street);
            }
            // else
            // {
            //     return;
            // }
        }
    }

    // If the slot is a station
    else if (slot->getType() == "Station")
    {
        Station *station = dynamic_cast<Station *>(slot);
        // Checking if the station is owned
        if (station->getOwnerPtr() != nullptr)
        {
            payStationRent(player, station->getOwner(), *station);
        }
        else
        {
            cout << "Do you want to buy this station? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                buyStation(player, *station);
            }
        }
    }

    else if (slot->getName() == "Utility")
    {
        Utility *utility = dynamic_cast<Utility *>(slot);
        // Checking if the utility is owned
        if (utility->getOwnerPtr() != nullptr)
        {
            payUtilityRent(player, utility->getOwner(), *utility, dice);
        }
        else
        {
            cout << "Do you want to buy this utility? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                buyUtility(player, *utility);
            }
        }
    }

    // Checking if it is a GO slot
    else if (slot->getName() == "Go")
    {

        Go *go = dynamic_cast<Go *>(slot);

        // if the player lands on go he gets 400$
        go->add400(player);
    }

    // need to add the other slots
    // doing the tasxes slots
    else if (slot->getName() == "Income Tax")
    {
        player.removeMoney(200);
        // Adding it to the free parking
        FreeParking *freeParking = dynamic_cast<FreeParking *>(board.getBoard()[20]);
        freeParking->addMoney(200);
    }
    else if (slot->getName() == "Luxury Tax")
    {
        player.removeMoney(100);
        // Adding it to the free parking
        FreeParking *freeParking = dynamic_cast<FreeParking *>(board.getBoard()[20]);
        freeParking->addMoney(100);
    }
    // jail slot
    // free parking slot
    // card slots
}

// Handling the street rent
void Monopoly::payStreetRent(Player &player1, Player &player2, Streets &street)
{
    // Streets *street = dynamic_cast<Streets *>(board.getBoard()[player1.getPosition()]);
    // Checking if the street has houses
    if (street.getHouses() > 0)
    {
        int renth = street.getRent() * pow(2, street.getHouses());
        //         int renth = street.getRent() * pow(2, street.getHouses() -1);

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

void Monopoly::buyStreet(Player &player, Streets &street)
{
    if (player.getMoney() < street.getPrice())
    {
        cout << "You don't have enough money to buy this street" << endl;
        return;
    }
    player.removeMoney(street.getPrice());
    player.addAsset(street);
}

// Handling the station rent
void Monopoly::payStationRent(Player &player1, Player &player2, Station &station)
{
    // Checking how many stations the owner has
    int stations = player2.getTrains();
    int rent = station.getRent() * pow(2, stations - 1);
    player1.removeMoney(rent);
    player2.addMoney(rent);
}

void Monopoly::buyStation(Player &player, Station &station)
{
    if (player.getMoney() < station.getPrice())
    {
        cout << "You don't have enough money to buy this station" << endl;
        return;
    }
    player.removeMoney(station.getPrice());
    player.addTrain(station);
}

// Handling the utility rent
// The rent payment is according to the number of utilities the owner and the dice result
void Monopoly::payUtilityRent(Player &player1, Player &player2, Utility &utility, int dice)
{
    // Checking how many utilities the owner has
    int utilities = player2.getUtilities();
    int rent = 0;

    if (utilities == 1)
    {
        rent = 4 * dice;
    }

    else if (utilities == 2)
    {
        rent = 10 * dice;
    }

    player1.removeMoney(rent);
    player2.addMoney(rent);
}

void Monopoly::buyUtility(Player &player, Utility &utility)
{
    if (player.getMoney() < utility.getPrice())
    {
        cout << "You don't have enough money to buy this utility" << endl;
        return;
    }
    player.removeMoney(utility.getPrice());
    player.addUtility(utility);
}