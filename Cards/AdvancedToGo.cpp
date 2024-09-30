// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "AdvancedToGo.hpp"

AdvancedToGo::AdvancedToGo() : supriseCard("AdvancedToGo", "Advance to Go (Collect $200)") {}

void AdvancedToGo::action(Player &player, Board &board)
{
    board.getBoard()[player.getPosition()]->removePlayer(player); // removing the player from the current position
    board.getBoard()[0]->addPlayer(player); // adding the player to the Go position
    player.setPosition(0); // setting the player position to 0
    player.addMoney(200); // adding $200 to the player
}
