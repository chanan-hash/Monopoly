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
    void action(Player &player, vector<Player> &players);
};

#endif // PAYPLAYER_HPP
