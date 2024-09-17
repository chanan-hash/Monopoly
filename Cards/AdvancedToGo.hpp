/**
 * Suprise card AdvencedToGo 
 * Advance to Go (Collect $200)
 */

#ifndef ADVANCEDTOGO_HPP
#define ADVANCEDTOGO_HPP

#include<vector>
#include "../Player.hpp"
#include "supriseCard.hpp"
#include "../Board.hpp"
#include "../BoardsSlots/Slot.hpp"

using namespace std;

class AdvancedToGo : public supriseCard
{
public:
    AdvancedToGo();
    ~AdvancedToGo() = default;
    void action(Player &player, Board &board);
};



#endif