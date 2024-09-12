/**
 * This is the Go slot
 * The player will get 200$ when he passes this slot
 * The player will get 400$ when he lands on this slot
 */

#ifndef GO_HPP
#define GO_HPP
#include "Slot.hpp"
#include "../Player.hpp"

class Go : public Slot
{
    public:
        Go(string &name, string &type);
        void add200(Player &player);
        void add400(Player &player);
        void printSlot() const override;
};

#endif // GO_HPP