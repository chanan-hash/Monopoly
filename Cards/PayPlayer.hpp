// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * You have been elected Chairman of the Board – Pay each player $50
 */

#ifndef PAYPLAYER_HPP
#define PAYPLAYER_HPP

#include "supriseCard.hpp"
#include "../Player.hpp"

class PayPlayer : public supriseCard
{
public:
    PayPlayer();
    void action(Player &player, vector<Player*> &players); // getting the player that pays and the vector of players
};

#endif // PAYPLAYER_HPP
