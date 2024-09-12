#include "Streets.hpp"
#include "../Player.hpp"

using namespace std;

Streets::Streets(string &name, string &type, string &color, int price, int rent, int housePrice, int hotelPrice) : Slot(name, type), color(color), price(price), rent(rent), housePrice(housePrice), hotelPrice(hotelPrice), houses(0), hotel(false){}

const string &Streets::getColor() const
{
    return color;
}

int Streets::getPrice() const
{
    return price;
}

int Streets::getRent() const
{
    return rent;
}

int Streets::getHousePrice() const
{
    return housePrice;
}

int Streets::getHotelPrice() const
{
    return hotelPrice;
}

const Player Streets::getOwner() const
{
    return *owner;
}

int Streets::getHouses() const
{
    return houses;
}

bool Streets::getHotel() const
{
    return hotel;
}

void Streets::setOwner(Player owner) // because we're using reference in the Slot class
{
    if(this->owner != nullptr)
    {
        cout << "This street is already owned by " << this->owner->getName() << endl;
        return;
    }
    this->owner = &owner;
}

void Streets::addHouse()
{
    if(hotel)
    {
        cout << "You can't add a house to a street with a hotel" << endl;
        return;
    }
    if(houses == 4)
    {
        cout << "You can't add more than 4 houses to a street" << endl;
        return;
    }
    houses++;
}

void Streets:: addHotel()
{
    if(hotel)
    {
        cout << "This street already has a hotel" << endl;
        return;
    }
    hotel = true;
}

void Streets::printSlot() const
{
    cout << "Street name: " << getName() << endl;
    cout << "Street color: " << color << endl;
    cout << "Street price: " << price << endl;
    cout << "Street rent: " << rent << endl;
    cout << "Street house price: " << housePrice << endl;
    cout << "Street hotel price: " << hotelPrice << endl;
    cout << "Street owner: " << owner->getName() << endl;
    cout << "Street houses: " << houses << endl;
    cout << "Street hotel: " << hotel << endl;
}