// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "BankPays.hpp"

BankPays::BankPays() : supriseCard("BankPays", "Bank pays you dividend of $50") {}

void BankPays::action(Player &player)
{
    player.addMoney(50);
}
