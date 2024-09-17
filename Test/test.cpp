#include "doctest.h"
#include "../Board.hpp"
#include "../Player.hpp"
#include"../Cards/supriseCard.hpp"
#include"../Cards/AdvancedToGo.hpp"

using namespace std;
TEST_CASE("Cards Testing"){
    // Creating the board
    Board board; // The default constructor will create the board with the default slots

    // Creating 3 Player
    Player player1("Player 1");
    Player player2("Player 2");
    Player player3("Player 3");
    
    // vector of player
    vector<Player> players;
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);

    // Putting the players on the board
    for (auto &player : players)
    {
        player.setPosition(0);
    }

    // Checking that the players are on the first slot
    for (const auto &player : players)
    {
        CHECK(player.getPosition() == 0);
    }

    // Adding the players to the first slot
    board.getBoard()[0]->addPlayer(player1);
    board.getBoard()[0]->addPlayer(player2);
    board.getBoard()[0]->addPlayer(player3);

    // Checking that the players are on the first slot
    for (const auto &player : players)
    {
        CHECK(board.getBoard()[0]->getPlayers()[0].getName() == player.getName());
    }

    SUBCASE("Advance to Go (Collect $200)"){
        // Creating the card
        AdvancedToGo advancedToGo;

        // putting plyer1 another slot
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[1]->addPlayer(player1);

        // setting the position of the player
        player1.setPosition(1);

        advancedToGo.action(player1, board);

        // Checking that the player is on the first slot
        CHECK(player1.getPosition() == 0);

        // Checking that the player has $200

        CHECK(player1.getMoney() == 1700);

        // Checking that the player is on the first slot
        CHECK(board.getBoard()[0]->getPlayers()[2].getName() == player1.getName());
        
    }
}
