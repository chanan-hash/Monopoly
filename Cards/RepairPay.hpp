/**
 * Repair Pay Card
 * Make general repairs on all your property – For each house pay $25 – For each hotel $100
 */

#ifndef REPAIRPAY_HPP
#define REPAIRPAY_HPP

#include "../Player.hpp"
#include "supriseCard.hpp"
#include "Board.hpp"
#include "Streets.hpp"

class RepairPay : public supriseCard
{
public:
    RepairPay();
    void action(Player &player);
};

#endif // REPAIRPAY_HPP