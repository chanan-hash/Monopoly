#include "GoBack.hpp"

GoBack::GoBack() : supriseCard("GoBack", "Go back 3 steps") {}

void GoBack::action(Player &player, Board &board)
{
    board.getBoard()[player.getPosition()]->removePlayer(player); // removing the player from the current position
    player.setPosition(player.getPosition() - 3);                 // setting the player position 3 steps back
    board.getBoard()[player.getPosition()]->addPlayer(player);    // adding the player to the new position
}