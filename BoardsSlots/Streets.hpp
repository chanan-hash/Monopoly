/**
 * This class represnt a street in the game.
 * Each street will have a name, color, price, rent, house price, hotel price, and the owner, how may houses and if a hotel is built.
 * It will inherit from Slot class.
 */

#ifndef STREETS_HPP
#define STREETS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Slot.hpp"
#include "../Player.hpp"

class Streets : public Slot
{
    // private:
    //     string name;
    //     string color;
    //     int price;
    //     int rent;
    //     int housePrice;
    //     int hotelPrice;
    //     Player owner;
    //     int houses;
    //     bool hotel;

    // public:
    //     Streets(string name, string color, int price, int rent, int housePrice, int hotelPrice);
    //     void setOwner(Player &owner);
    //     void addHouse();
    //     void removeHouse();
    //     void addHotel();
    //     void removeHotel();
    //     void printStreet();
    //     friend ostream& operator<<(ostream& os, const Streets& street);

private:
    // The name it will get from the Slot class
    string color;
    int price;
    int rent;
    int housePrice;
    int hotelPrice;
    Player *owner = nullptr;
    int houses;
    bool hotel;

public:
    Streets(string &name, string &type ,string &color, int price, int rent, int housePrice, int hotelPrice);
    
    // Getters
    const string &getColor() const;
    int getPrice() const;
    int getRent() const;
    int getHousePrice() const;
    int getHotelPrice() const;
    const Player getOwner() const;
    int getHouses() const;
    bool getHotel() const;
    bool operator==(const Streets &other) const;

    // Setters
    void setOwner(Player owner);
    void addHouse();
    void removeHouse();
    void addHotel();
    void removeHotel();
    virtual void printSlot() const override;
    friend ostream &operator<<(ostream &os, const Streets &street);
};

#endif // STREETS_HPP