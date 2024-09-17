#include "AdvancedToBoardWalk.hpp"

AdvancedToBoardWalk::AdvancedToBoardWalk() : supriseCard("Advanced To Boardwalk", "Take a walk on the Boardwalk, Advance token to Boardwalk") {}

void AdvancedToBoardWalk::action(Player &player, Board &board)
{
    // Get the player's current position
    int playerPosition = player.getPosition();

    // Get the position of the Boardwalk, it on the 39th position
    int boardwalkPosition = 39;

    // Here the card doesn't say anything about passing the Go slot, so we don't need to check if the player passes the Go slot

    board.getBoard()[playerPosition]->removePlayer(player);
    // Move the player to the Boardwalk
    player.setPosition(boardwalkPosition);
    board.getBoard()[boardwalkPosition]->addPlayer(player);
};