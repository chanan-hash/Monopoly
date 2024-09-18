/**
 * This free parking class will be used to store the money that the player will pay for the taxes,
 * and also for the player to wait for a turn, but this check up will be in the turn
 */

#ifndef FREEPARKING_HPP
#define FREEPARKING_HPP

#include "Slot.hpp"
#include "../Player.hpp"

class FreeParking : public Slot
{
private:
    int money; // the money that the player will pay for the taxes
public:
    FreeParking(const string &name);
    FreeParking(const string &name, const string &type);
    void addMoney(int moneyToAdd); // add the money to FreeParking
    void addMoney(Player &player); // add the money to the player
    int getMoney() const; // get the money
    virtual void printSlot() const override;
};

#endif // FREEPARKING_HPP