/**
 * This card is a class that will handle the free jail card.
 */

#ifndef FREEJAIL_HPP
#define FREEJAIL_HPP

#include "supriseCard.hpp"
#include "../Player.hpp"

class FreeJail : public supriseCard
{
public:
    FreeJail();
    ~FreeJail() = default;
    void action(Player &player);
};

#endif // FREEJAIL_HPP