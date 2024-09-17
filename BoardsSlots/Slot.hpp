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

using namespace std;

class Player;

class Slot
{
private:
    string name; // name of the slot
    string type; // type of the slot as mentioned above
    // int position;
    vector<Player> players; // who are the players on this slot, will help to move the player to the next slot
    // vector<std::shared_ptr<Player>> players; // who are the players on this slot, will help to move the player to the next slot

public:
    Slot(string &name, string &type);
    Slot(string& name);
    virtual ~Slot() = default;

    // For movment of the player
    void addPlayer(Player &player);
    void removePlayer(Player &player);

    // using shared_ptr instead of reference to avoid memory leak
    // void addPlayer(shared_ptr<Player> player);
    // void removePlayer(shared_ptr<Player> player);

    // Getters
    const string &getName() const;
    const string &getType() const;
    const vector<Player> &getPlayers() const;
    virtual void printSlot() const; // To know the details of the slot, each slot will have different details
    friend ostream &operator<<(ostream &os, const Slot &slot);

    // Pure virtual function
    virtual void slotAction() = 0; // function for virtual class
};

#endif // SLOT_HPP
