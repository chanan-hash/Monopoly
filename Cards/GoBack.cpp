#include "GoBack.hpp"

GoBack::GoBack() : supriseCard("GoBack", "Go back 3 steps") {}

void GoBack::action(Player &player, Board &board)
{
    board.getBoard()[player.getPosition()]->removePlayer(player); // removing the player from the current position
    int pos = player.getPosition();
    if (pos == 2) // if the player is on the 3rd slot
    {
        player.setPosition(board.getBoard().size() - 1);                  // setting the player position to the 39th slot
        board.getBoard()[board.getBoard().size() - 1]->addPlayer(player); // adding the player to the new position
        return;
    }
    player.setPosition(player.getPosition() - 3);              // setting the player position 3 steps back, by cycling the board
    board.getBoard()[player.getPosition()]->addPlayer(player); // adding the player to the new position
}