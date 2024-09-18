#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Board.hpp"
#include "../Player.hpp"
#include "../Cards/supriseCard.hpp"
#include "../Cards/AdvancedToGo.hpp"
#include "../Cards/AdvancedToBoardWalk.hpp"
#include "../Cards/BankPays.hpp"
#include "../Cards/GoBack.hpp"

using namespace std;
TEST_CASE("Cards Testing")
{
    // Creating the board
    Board board; // The default constructor will create the board with the default slots

    // Creating 3 Player
    Player player1("Player 1");
    Player player2("Player 2");
    Player player3("Player 3");

    // vector of player
    vector<Player *> players; // because we need to pass the player by reference
    players.push_back(&player1);
    players.push_back(&player2);
    players.push_back(&player3);

    // Setting the players position to 0
    player1.setPosition(0);
    player2.setPosition(0);
    player3.setPosition(0);

    // Checking that the position of the players is 0
    for (size_t i = 0; i < players.size(); i++)
    {
        CHECK(players[i]->getPosition() == 0);
    }

    // Adding the players to the first slot
    board.getBoard()[0]->addPlayer(player1);
    board.getBoard()[0]->addPlayer(player2);
    board.getBoard()[0]->addPlayer(player3);

    // Checking that the players are on the first slot
    for (size_t i = 0; i < players.size(); i++)
    {
        CHECK(board.getBoard()[0]->getPlayers()[i].getName() == players[i]->getName());
    }

    SUBCASE("Advance to Go (Collect $200)")
    {
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

        // cout << "player1 position: " << player1.getPosition() << endl;
        // cout << "player1 money: " << player1.getMoney() << endl;
        // cout << "player1 name: " << player1.getName() << endl;

        // cout << "player2 position: " << player2.getPosition() << endl;
        // cout << "player2 name: " << player2.getName() << endl;
        // cout << "player2 money: " << player2.getMoney() << endl;
    }

    SUBCASE("Checking AdvancedToBoardWalk")
    {
        // Creating the card
        AdvancedToBoardWalk advancedToBoardWalk;

        // moving player2 to the last slot
        advancedToBoardWalk.action(player2, board);
        cout << "player2 position: " << player2.getPosition() << endl;

        // Checking that the player is on the last slot
        CHECK(player2.getPosition() == 39);

        // cheking that this slot player is not empty
        CHECK_FALSE(board.getBoard()[39]->getPlayers().empty());
        CHECK(board.getBoard()[39]->getPlayers()[0].getName() == player2.getName());
    }

    SUBCASE("Bank pays")
    {
        // Creating the card
        BankPays bankPays;

        // setting the money of the player to 0
        player3.removeMoney(1500);

        // Checking that the player has $0
        CHECK(player3.getMoney() == 0);

        // player3 is the only player on the board
        bankPays.action(player3);

        // Checking that the player has $1500
        CHECK(player3.getMoney() == 50);
    }

    SUBCASE("3 Steps back")
    {
        // Creating the card
        GoBack goBack;
        cout << "player3 position: " << player3.getPosition() << endl;
        // moving player3 to third slot
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[2]->addPlayer(player3);

        // setting the position of the player
        player3.setPosition(2);

        cout << "player3 position: " << player3.getPosition() << endl;

        goBack.action(player3, board);
        cout << "player3 position: " << player3.getPosition() << endl;
        
        // Checking that the player is not on the first slot
        CHECK(player3.getPosition() != 0);

        // // Checking that the player is on the 39th slot
        CHECK(player3.getPosition() == 39);

        // // Checking that the player is on the 39th slot
        CHECK(board.getBoard()[39]->getPlayers()[0].getName() == player3.getName());
    }
}