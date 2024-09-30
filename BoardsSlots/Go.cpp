// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il


#include "Go.hpp"
#include "../Player.hpp"

using namespace std;

Go::Go(const string &name) : Slot(name) {} // initialize the name of the slot

Go::Go(const string &name,const  string &type) : Slot(name, type) {} // initialize the name and type of the slot

void Go::add200(Player &player) // add 200$ to the player
{
    player.addMoney(200);
}

void Go::add400(Player &player) // add 400$ to the player
{
    player.addMoney(400);
}

void Go::printSlot() const // print the details of the slot
{
    cout << "Go name: " << getName() << endl;
    cout << "Go type: " << getType() << endl;
}
