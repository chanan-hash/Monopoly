#include "PayPlayer.hpp"

PayPlayer::PayPlayer() : supriseCard("Pay Player", "You have been elected Chairman of the Board, Pay each player $50") {}

void PayPlayer::action(Player &player, vector<Player *> &players)
{
    int money = 50;

    for (auto &p : players)
    {
        if (p->getName() != player.getName())
        {
            player.removeMoney(money);
            p->addMoney(money);
        }
    }
}