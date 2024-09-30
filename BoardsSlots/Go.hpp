// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * This is the Go slot
 * The player will get 200$ when he passes this slot
 * The player will get 400$ when he lands on this slot
 */

#ifndef GO_HPP
#define GO_HPP
#include "Slot.hpp"
#include "../Player.hpp"

using namespace std;

class Go : public Slot
{
public:
    Go(const string &name);
    Go(const string &name,const  string &type);
    void add200(Player &player);
    void add400(Player &player);
    virtual void printSlot() const override;
};

#endif // GO_HPP