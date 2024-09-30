// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * Your building loan matures – Collect $150
 */

#ifndef LOAN_HPP
#define LOAN_HPP

#include "supriseCard.hpp"
#include "../Player.hpp"

class Loan : public supriseCard
{
public:
    Loan();
    void action(Player &player);
};

#endif // LOAN_HPP