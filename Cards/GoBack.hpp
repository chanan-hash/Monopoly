// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * GoBack card
 * This card will move the player 3 steps back
 * We need to check if the player is on the third slot on the community chest he will go to the 39th slot
 * so for that we'll use modulu board size
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