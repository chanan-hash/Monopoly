// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * Repair Pay Card
 * Make general repairs on all your property – For each house pay $25 – For each hotel $100
 */

#ifndef REPAIRPAY_HPP
#define REPAIRPAY_HPP

#include "supriseCard.hpp"

class Player;
class Streets;
class Board;
class Slot;


class RepairPay : public supriseCard
{
public:
    RepairPay();
    void action(Player &player);
};

#endif // REPAIRPAY_HPP