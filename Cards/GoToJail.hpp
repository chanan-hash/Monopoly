/**
 * Go to jail card class definition
 * Go directly to Jail – do not pass Go, do not collect $200
 */

#ifndef GOTOJAIL_HPP
#define GOTOJAIL_HPP

#include "../Player.hpp"
#include "supriseCard.hpp"
#include "../Board.hpp"

class GoToJail : public supriseCard
{
public:
    GoToJail();
    void action(Player &player, Board &board);
};

#endif // GOTOJAIL_HPP

