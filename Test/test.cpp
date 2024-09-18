#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Board.hpp"
#include "../Player.hpp"
#include "../Cards/supriseCard.hpp"
#include "../Cards/AdvancedToGo.hpp"
#include "../Cards/AdvancedToBoardWalk.hpp"
#include "../Cards/BankPays.hpp"
#include "../Cards/GoBack.hpp"
#include "../Cards/Loan.hpp"
#include "../Cards/GoToJail.hpp"
#include "../Cards/PayPlayer.hpp"
#include "../Cards/PayTax.hpp"
#include "../Cards/RepairPay.hpp"
#include "../Cards/TrainTrip.hpp"

#include "../BoardsSlots/Streets.hpp"
#include "../BoardsSlots/FreeParking.hpp"

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

        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[22]->addPlayer(player2);

        // setting the position of the player
        player2.setPosition(22);
        cout << "player2 position: " << player2.getPosition() << endl;
        goBack.action(player2, board);
        cout << "player2 position: " << player2.getPosition() << endl;

        // Checking that the player is not on the 22th slot
        CHECK(player2.getPosition() != 22);
        CHECK(player2.getPosition() == 19);

        // Checking that the player is on the 19th slot
        CHECK(board.getBoard()[19]->getPlayers()[0].getName() == player2.getName());
        CHECK(board.getBoard()[player2.getPosition()]->getName() == "New York Avenue");

        auto slot19 = board.getBoard()[player2.getPosition()];
        Streets *street = dynamic_cast<Streets *>(slot19);
        CHECK(street->getRent() == 16);
    }

    SUBCASE("Loan")
    {
        // Creating the card
        Loan loan;
        CHECK(player1.getMoney() == 1500);

        // player1 is the only player on the board
        loan.action(player1);

        // Checking that the player has $1500
        CHECK(player1.getMoney() == 1650);
    }

    SUBCASE("GO TO JAIL")
    {
        // Creating the card
        GoToJail goToJail;

        // Checking that the player is not in jail
        CHECK_FALSE(player1.getIsInJail());
        // moving player1 to the jail slot
        goToJail.action(player1, board);

        // Checking that the player is on the jail slot
        CHECK(player1.getPosition() == 10);

        // Checking that the player is on the jail slot
        CHECK(board.getBoard()[10]->getPlayers()[0].getName() == player1.getName());

        CHECK(player1.getIsInJail() == true);
    }

    SUBCASE("Pay Player")
    {
        // Creating the card
        PayPlayer payPlayer;
        CHECK(player1.getMoney() == 1500);
        CHECK(player2.getMoney() == 1500);
        CHECK(player3.getMoney() == 1500);

        payPlayer.action(player1, players);
        CHECK(player1.getMoney() == 1400);
        CHECK(player2.getMoney() == 1550);
        CHECK(player3.getMoney() == 1550);
    }

    SUBCASE("Pay Tax")
    {
        // Creating the card
        PayTax payTax;

        CHECK(player2.getMoney() == 1500);

        payTax.action(player2, board);

        CHECK(player2.getMoney() == 1485);

        Slot *slot = board.getBoard()[20];
        FreeParking *freeParking = dynamic_cast<FreeParking *>(slot);

        CHECK(freeParking->getMoney() == 15);
    }

    SUBCASE("Train Trip")
    {
        // Creating the card
        TrainTrip trainTrip;

        // moving player1 to the 2th slot
        // means he's not passing the Go slot

        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[2]->addPlayer(player1);

        // setting the position of the player
        player1.setPosition(2);

        trainTrip.action(player1, board);

        // Checking that the player is on the 5th slot
        CHECK(player1.getPosition() == 5);

        // Checking that the player is on the 5th slot
        CHECK(board.getBoard()[5]->getPlayers()[0].getName() == player1.getName());

        // Checking that the player has 1500$
        CHECK(player1.getMoney() == 1500);

        // moving player2 to the 7th slot
        // means he's passing the Go slot

        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[7]->addPlayer(player2);

        // setting the position of the player
        player2.setPosition(7);

        trainTrip.action(player2, board);

        // Checking that the player is on the 5th slot
        CHECK(player2.getPosition() == 5);

        // Checking that the player is on the 5th slot
        CHECK(board.getBoard()[5]->getPlayers()[1].getName() == player2.getName());

        // Checking that the player has 1700$
        CHECK(player2.getMoney() == 1700);
    }

    SUBCASE("Repair Pay")
    {
        // Creating the card
        RepairPay repairPay;

        // If the player has 0 assets he should not pay anything

        CHECK(player3.getMoney() == 1500);

        repairPay.action(player3);

        CHECK(player3.getMoney() == 1500);
        
        // Now let's add some assets to the player
        // here it before we have the buying functionality it will be in the game logic
        // so we will add the assets manually

        // Lets assume that the player has 2 streets with 2 houses each and 1 street with a hotel
        // The 2 brown streets
        player3.addAsset(*dynamic_cast<Streets *>(board.getBoard()[1]));
        player3.addAsset(*dynamic_cast<Streets *>(board.getBoard()[3]));

        // Adding to them 2 houses each
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[3])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[3])->addHouse();

        player3.addAsset(*dynamic_cast<Streets *>(board.getBoard()[6]));

        // Adding to it a hotel
        dynamic_cast<Streets *>(board.getBoard()[6])->addHotel();

        // Now the player has 2 streets with 2 houses each and 1 street with a hotel
        // The total repair cost should be 25 * 4 + 100 = 200
        repairPay.action(player3);

        // Checking that the player has 1300$
        CHECK(player3.getMoney() == 1300);

        // Checking the Street's owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[1])->getOwner().getName() == player3.getName());
        CHECK(dynamic_cast<Streets *>(board.getBoard()[3])->getOwner().getName() == player3.getName());
        CHECK(dynamic_cast<Streets *>(board.getBoard()[6])->getOwner().getName() == player3.getName());
    }
}