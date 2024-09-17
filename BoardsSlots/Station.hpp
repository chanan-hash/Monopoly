/**
 * This class is representing the train stations in the game
 * The player will pay the rent to the owner of the station according to the number of stations that the owner has
 */
#ifndef STATION_HPP
#define STATION_HPP

#include "Slot.hpp"
#include "../Player.hpp"
using namespace std;

class Station : public Slot
{
    private:
        int price; // the price of the station
        int rent; // the rent of the station
        Player *owner; // the owner of the station

    public:
        Station(string &name, string &type, int price, int rent);
        // Getters
        int getPrice() const;
        int getRent() const;
        const Player getOwner() const;

        // Setters
        void setOwner(Player &player); // set the owner of the station
        // void payRent(Player &player); // pay the rent to the owner of the station
        virtual void printSlot() const override;
};

#endif // STATION_HPP