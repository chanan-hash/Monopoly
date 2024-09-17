#include "GoToJail.hpp"
#include "../BoardsSlots/Slot.hpp" // Include the header file for the Slot class

GoToJail::GoToJail() : supriseCard("GoToJail", "Go directly to Jail, do not pass Go, do not collect $200") {}

void GoToJail::action(Player &player, Board &board)
{
    board.getBoard()[player.getPosition()]->removePlayer(player); // removing the player from the current position
    player.setPosition(10);                                       // setting the player position to jail
    board.getBoard()[10]->addPlayer(player);                      // adding the player to the new position
    player.setIsInJail(true);                                     // setting the player in jail
}