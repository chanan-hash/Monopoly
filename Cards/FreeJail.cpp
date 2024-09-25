#include "FreeJail.hpp"

FreeJail::FreeJail() : supriseCard("Free Jail", "Freeing you from jail, keep the card") {}

void FreeJail::action(Player &player)
{
    player.setFreeJailCard(true);
}