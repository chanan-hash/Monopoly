#include "Slot.hpp"
using namespace std;

Slot::Slot(string &name, string &type) : name(name), type(type) {} // initialize the name and type of the slot
Slot::Slot(string &name) : name(name) {} // initialize the name of the slot
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

// if we're using shared_ptr instead of reference to avoid memory leak
// void Slot::addPlayer(shared_ptr<Player> player) // add the player to the slot
// {
//     players.push_back(player);
// }

// // trying to remove by iterator made problems
// void Slot::removePlayer(shared_ptr<Player> player) // remove the player from the slot
// {
//     for(size_t i = 0; i < players.size(); i++)
//     {
//         if(players[i] == player)
//         {
//             players.erase(players.begin() + i); // remove the player from the slot
//             break;
//         }
//     }
// }

// const vector<shared_ptr<Player>> Slot::getPlayers() const // get the players on the slot
// {
//     return players;
// }
