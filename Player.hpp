/**
 * This class represnts a simple player in the game
 * Each player has a name, money, card, and assets (streets, train stations, and utilities)
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Slot;
class Streets;
class Station;
class Utility;

class Player
{
private:
    string name;
    int money;
    vector<Streets *> assets; // It will hold all the assets of the player, streets, stations, and utilities
    int trains;               // more convenient to calculate the rent if needed
    int utilities;            // more convenient to calculate the rent if needed
    int position; // The position of the player on the board

    // Turns variables
    int turnsInJail = 0;
    bool isInJail = false;     // A flag to indicate if the player is in jail or not
    bool FreeJailCard = false; // A flag to indicate if the player has a free jail card or not
    bool missTurn = false;     // A flag to indicate if the player has to miss a turn or not

public:
    // Player();
    Player(string name);
    void addMoney(int amount); // we can add a negative amount to remove money
    void removeMoney(int amount);
    void addAsset(Streets &asset); // Adding the asset to the player
    void removeAsset(Streets &asset);
    void addTrain(Station &train); // Adding the train to the player, and increment the number of trains for payment calculation
    void removeTrain(Station &train);
    void addUtility(Utility &utility); // Adding the utility to the player, and increment the number of utilities for payment calculation
    void removeUtility(Utility &utility);

    // getters
    const string &getName() const;
    int getMoney() const;
    vector<Streets *> getAssets();
    int getTrains() const;
    int getUtilities() const;
    int getPosition() const;
    int getTurnsInJail() const;
    bool getIsInJail() const;
    bool getFreeJailCard() const;
    bool getMissTurn() const;
    void printPlayer();
    string toString();
    bool operator==(const Player &other) const;
    bool operator!=(const Player &other) const;
    // friend ostream &operator<<(ostream &os, const Player &player);

    // setters
    void setPosition(int position);
    void setIsInJail(bool isInJail);
    void setFreeJailCard(bool FreeJailCard);
    void setMissTurn(bool missTurn);

    void setTurnsInJail(int num);
};

#endif // PLAYER_HPP