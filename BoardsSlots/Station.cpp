#include "Station.hpp"
#include "../Player.hpp"

using namespace std;

Station::Station(string &name, string &type, int price, int rent) : Slot(name, type), price(price), rent(rent), owner(nullptr) {} // initialize the name, type, price, rent and owner of the station

void Station::setOwner(Player &player) // set the owner of the station
{
    if (owner != nullptr)
    {
        cout << "This station is already owned by " << owner->getName() << endl;
    }
    else
    {
        owner = &player;           // set the owner of the station
        // player.addAsset(station);  // add the station to the player's assets
        // player.removeMoney(price); // remove the price of the station from the player
    }
}

// void Station::payRent(Player &player) // pay the rent to the owner of the station
// {
//     if (owner != nullptr && owner->getName() != player.getName()) // if the owner is not null and the owner is not the player
//     {
//         int rentToPay = rent * owner->getStations(); // calculate the rent to pay
//         player.removeMoney(rentToPay);               // remove the money from the player
//         owner->addMoney(rentToPay);                  // add the money to the owner
//     }
// }

void Station::printSlot() const // print the details of the slot
{
    cout << "Station name: " << getName() << endl;
    cout << "Station type: " << getType() << endl;
    cout << "Station price: " << price << endl;
    cout << "Station rent: " << rent << endl;
    if (owner != nullptr)
    {
        cout << "Station owner: " << owner->getName() << endl;
    }
    else
    {
        cout << "Station owner: None" << endl;
    }
}