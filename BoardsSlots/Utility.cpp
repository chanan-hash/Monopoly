#include "Utility.hpp"
#include "../Player.hpp"

using namespace std;

Utility::Utility(string &name, string &type, int price, int rent) : Slot(name, type), price(price), rent(rent), owner(nullptr) {}

int Utility::getPrice() const
{
    return this->price;
}

int Utility::getRent() const
{
    return this->rent;
}

const Player Utility::getOwner() const
{
    return *owner;
}

void Utility::setOwner(Player &player)
{
    this->owner = &player;
}

void Utility::printSlot() const
{
    cout << "Utility name: " << getName() << endl;
    cout << "Utility type: " << getType() << endl;
    cout << "Utility price: " << price << endl;
    cout << "Utility rent: " << rent << endl;
    if (owner != nullptr)
    {
        cout << "Utility owner: " << owner->getName() << endl;
    }
    else
    {
        cout << "Utility owner: None" << endl;
    }
}
