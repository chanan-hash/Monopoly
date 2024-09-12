#include "FreeParking.hpp"
#include "../Player.hpp"

using namespace std;

FreeParking::FreeParking(string &name, string &type) : Slot(name, type) {} // initialize the name and type of the slot

void FreeParking::addMoney(int moneyToAdd) // add the money to FreeParking
{
    this->money += moneyToAdd; // adding the money to the FreeParking according to what the player paid
}

void FreeParking::addMoney(Player &player) // add the money to the player
{
    if (money > 0)
    {
        player.addMoney(money);
        money = 0; // reset the money to 0 after the player took it
    }
}

void FreeParking::printSlot() const // print the details of the slot
{
    cout << "FreeParking name: " << getName() << endl;
    cout << "FreeParking type: " << getType() << endl;
}
