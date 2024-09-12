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
#include "../Player.hpp"

using namespace std;

class Slot
{
private:
    string name; // name of the slot
    string type; // type of the slot as mentioned above
    // int position;
    vector<Player> players; // who are the players on this slot, will help to move the player to the next slot

public:
    Slot(string name, string type);
    virtual ~Slot() = default;

    // For movment of the player
    void addPlayer(Player player);
    void removePlayer(Player player);

    // Getters
    string getName() const;
    string getType() const;
    vector<Player> getPlayers() const;
    void printSlot() const; // To know the details of the slot
    friend ostream &operator<<(ostream &os, const Slot &slot);

    // Pure virtual function
    virtual void abstract() = 0; // function for virtual class
};

#endif // SLOT_HPP
