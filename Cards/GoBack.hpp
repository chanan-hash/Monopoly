/**
 * GoBack card
 * This card will move the player 3 steps back
 */
#ifndef GOBACK_HPP
#define GOBACK_HPP

#include "../Player.hpp"
#include "supriseCard.hpp"
#include "../Board.hpp"
#include "../BoardsSlots/Slot.hpp"

class GoBack : public supriseCard
{
public:
    GoBack();
    void action(Player &player, Board &board);
};

#endif // GOBACK_HPP