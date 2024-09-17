/**
 * @file BankPays.hpp
 * @brief This file contains the declaration of the BankPays class
 * Bank pays you dividend of $50
 */

#ifndef BANKPAYS_HPP
#define BANKPAYS_HPP

#include "../Player.hpp"
#include "supriseCard.hpp"
#include "../Board.hpp"

class BankPays : public supriseCard
{
public:
    BankPays();
    ~BankPays() = default;
    void action(Player &player);
};

#endif // BANKPAYS_HPP
