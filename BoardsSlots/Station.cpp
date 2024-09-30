// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "Station.hpp"
#include "../Player.hpp"

using namespace std;

Station::Station(const string &name, const string &type, int price, int rent) : Slot(name, type), price(price), rent(rent), owner(nullptr) {} // initialize the name, type, price, rent and owner of the station

void Station::setOwner(Player &player) // set the owner of the station
{
    if (owner != nullptr)
    {
        cout << "This station is already owned by " << owner->getName() << endl;
    }
    else
    {
        owner = &player; // set the owner of the station
        // player.addAsset(station);  // add the station to the player's assets
        // player.removeMoney(price); // remove the price of the station from the player
    }
}

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

int Station::getPrice() const // get the price of the station
{
    return price;
}

int Station::getRent() const // get the rent of the station
{
    return rent;
}

Player &Station::getOwner() const // get the owner of the station
{
    return *owner;
}

Player *Station::getOwnerPtr() const // get the owner of the station
{
    return owner;
}
