// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * PayTax.hpp
 * Pay poor tax of $15
 * The money goes to the free parking
 */

#ifndef PAYTAX_HPP
#define PAYTAX_HPP

#include"supriseCard.hpp"
#include"../Player.hpp"
#include"../Board.hpp"
#include"../BoardsSlots/FreeParking.hpp"

class PayTax : public supriseCard
{
public:
    PayTax();
    void action(Player &player, Board &board);
};

#endif // PAYTAX_HPP
