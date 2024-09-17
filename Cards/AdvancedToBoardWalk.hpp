/**
 * Take a walk on the Boardwalk – Advance token to Boardwalk
 */

#ifndef ADVANCEDTOBOARDWALK_HPP
#define ADVANCEDTOBOARDWALK_HPP

#include "supriseCard.hpp"
#include "../Player.hpp"
#include "../Board.hpp"
#include"../BoardsSlots/Streets.hpp"

class AdvancedToBoardWalk : public supriseCard
{
public:
    AdvancedToBoardWalk();
    void action(Player &player, Board &board);
};

#endif // ADVANCEDTOBOARDWALK_HPP