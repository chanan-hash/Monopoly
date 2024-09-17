#include "Loan.hpp"

Loan::Loan() : supriseCard("Loan", "Your building loan matures, Collect $150") {}

void Loan::action(Player &player)
{
    player.addMoney(150);
}