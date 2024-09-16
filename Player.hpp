/**
 * This class represnts a simple player in the game
 * Each player has a name, money, card, and assets (streets, train stations, and utilities)
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "supriseCard.hpp"
#include "Slot.hpp"
#include "Streets.hpp"
#include "Station.hpp"
#include "Utility.hpp"

using namespace std;

class Player
{
private:
    string name;
    int money;
    vector<supriseCard> card; // need to be implemented
    vector<Slot> assets;      // It will hold all the assets of the player, streets, stations, and utilities
    int trains;               // more convenient to calculate the rent if needed
    int utilities;            // more convenient to calculate the rent if needed

    int position; // The position of the player on the board

public:
    Player(string name);
    void addMoney(int amount); // we can add a negative amount to remove money
    void removeMoney(int amount);
    void addCard(supriseCard card);    // need to be implemented
    void removeCard(supriseCard card); // need to be implemented
    void addAsset(Streets& asset);      // Adding the asset to the player
    void removeAsset(Streets& asset);
    void addTrain(Station& train); // Adding the train to the player, and increment the number of trains for payment calculation
    void removeTrain(Station& train);
    void addUtility(Utility& utility); // Adding the utility to the player, and increment the number of utilities for payment calculation
    void removeUtility(Utility& utility);

    // getters
    string &getName() const;
    int getMoney() const;
    vector<supriseCard> getCard();
    vector<Slot> getAssets();
    int getTrains() const;
    int getUtilities() const;
    int getPosition() const;
    void printPlayer();
    bool operator==(const Player &other) const;
    bool operator!=(const Player &other) const;
    friend ostream &operator<<(ostream &os, const Player &player);

    // setters
    void setPosition(int position);
};

#endif // PLAYER_HPP