/**
 * Take a trip to Reading Railroad – If you pass Go collect $200
 */

#ifndef TRAINTRIP_HPP
#define TRAINTRIP_HPP

#include "supriseCard.hpp"
#include "../Player.hpp"
#include "../Board.hpp"
#include "../BoardsSlots/Station.hpp"

class TrainTrip : public supriseCard
{
public:
    TrainTrip();
    void action(Player &player, Board &board);
};

#endif // TRAINTRIP_HPP