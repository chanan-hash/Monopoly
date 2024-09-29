// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "Slot.hpp"
#include "../Player.hpp"

using namespace std;

Slot::Slot(const string &name, const string &type) : name(name), type(type) {} // initialize the name and type of the slot
Slot::Slot(const string &name) : name(name) {}                                 // initialize the name of the slot
// Slot::Slot(const Slot &other) : name(other.name), type(other.type) {}

void Slot::addPlayer(Player &player) // add the player to the slot
{
    players.push_back(player);
}

void Slot::removePlayer(Player &player) // remove the player from the slot
{
    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i].getName() == player.getName())
        {
            players.erase(players.begin() + i); // remove the player from the slot
            break;
        }
    }
}

const string &Slot::getName() const // get the name of the slot
{
    return name;
}

const string &Slot::getType() const // get the type of the slot
{
    return type;
}

const vector<Player> &Slot::getPlayers() const // get the players on the slot
{
    return players;
}

void Slot::printSlot() const // print the slot details
{
    cout << "Slot name: " << name << endl;
    cout << "Slot type: " << type << endl;
    cout << "Players on the slot: " << endl;
    for (size_t i = 0; i < players.size(); i++)
    {
        cout << players[i].getName() << endl;
    }
}

string Slot::toString() const // convert the slot to string
{
    string res = "";
    res += name + "\n";
    res += "Players on: \n";
    for (size_t i = 0; i < players.size(); i++)
    {
        res += players[i].getName() + "\n";
    }
    return res;
}