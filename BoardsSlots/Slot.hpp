/**
 * This will be an abstract father class for all the board slots.
 * 1. Streets
 * 2. Station (Train)
 * 3. Utility (Electricity, Water)
 * 4. Jail
 * 5. Go to Jail
 * 6. Free Parking
 * 7. Chance -suprise-card
 * 8. Community Chest - suprise-card
 * 9. Tax (Income, Luxury)
 * 10. Go
 */

#ifndef SLOT_HPP
#define SLOT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory> // for shared_ptr may be used in the future
#include "../Player.hpp"


using namespace std;

class Player;

class Slot
{
private:
    string name; // name of the slot
    string type; // type of the slot as mentioned above
    vector<Player> players; // who are the players on this slot, will help to move the player to the next slot

public:
    Slot(const string &name,const  string &type);
    Slot(const string& name);
    Slot(const Slot& other) = default; // Copy constructor
    virtual ~Slot() = default;

    // For movment of the player
    void addPlayer(Player &player);
    void removePlayer(Player &player);

    // Getters
    const string &getName() const;
    const string &getType() const;
    const vector<Player> &getPlayers() const;
    virtual void printSlot() const; // To know the details of the slot, each slot will have different details

    string toString() const;
};

#endif // SLOT_HPP
