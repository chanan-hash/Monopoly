#include "TrainTrip.hpp"

TrainTrip::TrainTrip() : supriseCard("Train Trip", "Take a trip to Reading Railroad – If you pass Go collect $200") {}

void TrainTrip::action(Player &player, Board &board)
{
    // Get the player's current position
    int playerPosition = player.getPosition();

    // Get the position of the Reading Railroad, it on the 5th position
    int readingRailroadPosition = 5;
        
    // Check if the player passes the Go slot, if the plyer position is greater than 5 means the player passes the Go slot

    if (playerPosition > readingRailroadPosition)
    {
        // If the player passes the Go slot, add $200 to the player's money
        player.addMoney(200);
    }
    board.getBoard()[playerPosition]->removePlayer(player);
    // Move the player to the Reading Railroad
    player.setPosition(readingRailroadPosition);
    board.getBoard()[readingRailroadPosition]->addPlayer(player);
}
