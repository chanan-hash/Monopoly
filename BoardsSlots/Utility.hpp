/**
 * This class represents the utility slot we have electricity and water
 * The payemtn is according to how many utilities you have, and what is the dice result
 */
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Slot.hpp"
#include "../Player.hpp"
using namespace std;

class Utility : public Slot
{
private:
    int price;
    int rent;
    Player *owner;

public:
    Utility(string &name, string &type, int price, int rent);

    // Getters
    int getPrice() const;
    int getRent() const;
    const Player getOwner() const;

    // Setters
    void setOwner(Player &player);
    virtual void printSlot() const override;
};

#endif