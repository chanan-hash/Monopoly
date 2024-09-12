/**
 * This class represnts a simple player in the game
 * Each player has a name, money, card, and assets (streets, train stations, and utilities)
 */ 
#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Player
{
    private:
        string name;
        int money;
        vector<supriseCard> card; // need to be implemented
        vector<assets> assets; // need to be implemented

    public:
        Player(string name);
        void addMoney(int amount); // we can add a negative amount to remove money
        void removeMoney(int amount);
        void addCard(supriseCard card); // need to be implemented
        void removeCard(supriseCard card); // need to be implemented
        void addAsset(assets asset); // need to be implemented
        void removeAsset(assets asset); // need to be implemented

        // getters
        string getName();
        int getMoney();
        vector<supriseCard> getCard(); // need to be implemented
        vector<assets> getAssets(); // need to be implemented
        void printPlayer();
        friend ostream& operator<<(ostream& os, const Player& player);
};

