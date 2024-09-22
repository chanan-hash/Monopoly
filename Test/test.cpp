#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <string>

#include "../Monopoly.hpp"

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

TEST_CASE("Testing game logic")
{
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

    Monopoly monopoly;

    SUBCASE("Checking diceRoll")
    {
        int dice = monopoly.diceRoll();
        CHECK(dice >= 1);
        CHECK(dice <= 6);
    }

    SUBCASE("Checking movePlayer")
    {

        std::istringstream simulatedInput("n\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        // player1 will move
        monopoly.movePlayer(player1, board);

        std::cin.rdbuf(originalCin);

        CHECK(player1.getPosition() >= 2); // because the player should move at least 2 steps

        // Checking that the player is on the new slot
        CHECK(board.getBoard()[player1.getPosition()]->getPlayers()[0].getName() == player1.getName());

        // Checking that he is not on the first slot
        for (size_t i = 0; i < board.getBoard()[0]->getPlayers().size(); i++)
        {
            CHECK(board.getBoard()[0]->getPlayers()[i].getName() != player1.getName());
        }
    }

    SUBCASE("Checking pay function")
    {
        // for now let's assume that player2 bought a street and player1 landed on it
        // so player1 should pay the rent to player2
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[6]->addPlayer(player1);

        player2.addAsset(*dynamic_cast<Streets *>(board.getBoard()[6]));
        CHECK(player2.getAssets().size() == 1);
        // Cheking that player2 is the owner of the street
        CHECK(dynamic_cast<Streets *>(board.getBoard()[6])->getOwner().getName() == player2.getName());
        CHECK(dynamic_cast<Streets *>(board.getBoard()[6]) != nullptr);

        // cout << dynamic_cast<Streets *>(board.getBoard()[6])-> getHouses() << endl;

        monopoly.payStreetRent(player1, player2, *dynamic_cast<Streets *>(board.getBoard()[6]));

        // Checking that player1 has 1494$
        CHECK(player1.getMoney() == 1494);

        // // Checking that player2 has 1506$
        CHECK(player2.getMoney() == 1506);

        // Now let's assume that player3 bought a street and player2 landed on it
        // and the street has 2 houses

        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[37]->addPlayer(player2);

        player3.addAsset(*dynamic_cast<Streets *>(board.getBoard()[37]));
        CHECK(player3.getAssets().size() == 1);

        // Adding to it 2 houses
        dynamic_cast<Streets *>(board.getBoard()[37])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[37])->addHouse();

        // Cheking that player3 is the owner of the street
        CHECK(dynamic_cast<Streets *>(board.getBoard()[37])->getOwner().getName() == player3.getName());
        CHECK(dynamic_cast<Streets *>(board.getBoard()[37]) != nullptr);

        monopoly.payStreetRent(player2, player3, *dynamic_cast<Streets *>(board.getBoard()[37]));

        // Checking that player2 has 1366$
        CHECK(player2.getMoney() == 1366);

        // Checking that player3 has 1640$
        CHECK(player3.getMoney() == 1640);

        // Adding a hotel to the street
        dynamic_cast<Streets *>(board.getBoard()[37])->addHotel();
        CHECK(dynamic_cast<Streets *>(board.getBoard()[37])->getHotel() == true);
        CHECK(dynamic_cast<Streets *>(board.getBoard()[37])->getName() == "Park Place");

        // moving player1 to the street
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[37]->addPlayer(player1);

        monopoly.payStreetRent(player1, player3, *dynamic_cast<Streets *>(board.getBoard()[37]));

        // Checking that player1 has 1144$
        CHECK(player1.getMoney() == 1144);

        // Checking that player3 has 1990$
        CHECK(player3.getMoney() == 1990);
    }

    SUBCASE("Checking passed GO")
    {
        // puting player1 on the last slot
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[39]->addPlayer(player1);
        player1.setPosition(39);

        cout << "player1 position: " << player1.getPosition() << endl;
        // Cheking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        // input n not to buy
        std::istringstream simulatedInput("n\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        // player1 will move
        monopoly.movePlayer(player1, board);

        std::cin.rdbuf(originalCin);

        cout << "player1 position: " << player1.getPosition() << endl;

        // Checking that player1 has 1700$
        CHECK(player1.getMoney() == 1700);
    }

    SUBCASE("Checking buying a street")
    {
        // puting player1 on the street
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[1]->addPlayer(player1);
        player1.setPosition(1);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        monopoly.buyStreet(player1, *dynamic_cast<Streets *>(board.getBoard()[1]));

        // Checking that player1 has 1440$
        CHECK(player1.getMoney() == 1440);

        // Checking that player1 has the street
        CHECK(player1.getAssets().size() == 1);
        CHECK(player1.getAssets()[0]->getName() == "Mediterranean Avenue");

        // Checking that the street has an owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[1])->getOwner().getName() == player1.getName());

        // puting player2 on the street
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[3]->addPlayer(player2);
        player2.setPosition(3);

        // removing player2 money so he can't buy the street
        player2.removeMoney(1500);

        // Checking that player2 has 0$
        CHECK(player2.getMoney() == 0);

        monopoly.buyStreet(player2, *dynamic_cast<Streets *>(board.getBoard()[3]));

        // Checcking that the street has no owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[3])->getOwnerPtr() == nullptr);

        // Cheking that player2 has no assets
        CHECK(player2.getAssets().size() == 0);
    }

    SUBCASE("Checking buying Station and payment")
    {
        // puting player1 on the station
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[5]->addPlayer(player1);
        player1.setPosition(5);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        monopoly.buyStation(player1, *dynamic_cast<Station *>(board.getBoard()[5]));

        // Checking that player1 has 1300$
        CHECK(player1.getMoney() == 1300);

        // Checking that player1 has the station
        CHECK(player1.getTrains() == 1);

        // Checking that the station has an owner
        CHECK(dynamic_cast<Station *>(board.getBoard()[5])->getOwner().getName() == player1.getName());

        // puting player2 on the station
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[5]->addPlayer(player2);
        player2.setPosition(5);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        monopoly.payStationRent(player2, player1, *dynamic_cast<Station *>(board.getBoard()[5]));

        CHECK(player2.getMoney() == 1475);
        CHECK(player1.getMoney() == 1325);

        // Adding to player1 another station
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[15]->addPlayer(player1);
        player1.setPosition(15);

        monopoly.buyStation(player1, *dynamic_cast<Station *>(board.getBoard()[15]));

        // Checking that player1 has 1125$
        CHECK(player1.getMoney() == 1125);

        // Checking that player1 has 2 stations
        CHECK(player1.getTrains() == 2);

        // Checking that the station has an owner
        CHECK(dynamic_cast<Station *>(board.getBoard()[15])->getOwner().getName() == player1.getName());

        // Now putting player3 on the station
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[5]->addPlayer(player3);
        player3.setPosition(5);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        monopoly.payStationRent(player3, player1, *dynamic_cast<Station *>(board.getBoard()[5]));

        CHECK(player3.getMoney() == 1450);

        CHECK(player1.getMoney() == 1175);

        // trying to buy the station while he has no money
        player3.removeMoney(1400);

        monopoly.buyStation(player3, *dynamic_cast<Station *>(board.getBoard()[35]));

        // Checking that the station has no owner
        CHECK(dynamic_cast<Station *>(board.getBoard()[35])->getOwnerPtr() == nullptr);

        // Cheking that player3 has no stations
        CHECK(player3.getTrains() == 0);

        // Check that he has the same amount of money
        CHECK(player3.getMoney() == 50);
    }

    SUBCASE("Testing Utility fucntions")
    {
        // let assume player 1 bought the utility
        // puting player1 on the utility
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[12]->addPlayer(player1);
        player1.setPosition(12);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        monopoly.buyUtility(player1, *dynamic_cast<Utility *>(board.getBoard()[12]));

        // Checking that player1 has 1350$
        CHECK(player1.getMoney() == 1350);

        // Checking that player1 has the utility
        CHECK(player1.getUtilities() == 1);

        // Checking that the utility has an owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[12])->getOwner().getName() == player1.getName());

        // puting player2 on the utility
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[12]->addPlayer(player2);
        player2.setPosition(12);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        monopoly.payUtilityRent(player2, player1, *dynamic_cast<Utility *>(board.getBoard()[12]), 5);

        // player2 should pay 20$ to player1
        CHECK(player2.getMoney() == 1480);
        CHECK(player1.getMoney() == 1370);

        // player2 wna;t to by the utility but he has no money
        player2.removeMoney(1470);
        CHECK(player2.getMoney() == 10);
        monopoly.buyUtility(player2, *dynamic_cast<Utility *>(board.getBoard()[28]));

        // Checking that the utility has no owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[28])->getOwnerPtr() == nullptr);

        // Checking that player2 has no utilities
        CHECK(player2.getUtilities() == 0);

        // Adding another utility to player1

        // puting player1 on the utility
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[28]->addPlayer(player1);
        player1.setPosition(28);

        monopoly.buyUtility(player1, *dynamic_cast<Utility *>(board.getBoard()[28]));

        // Checking that player1 has 1220$
        CHECK(player1.getMoney() == 1220);

        // Checking that player1 has 2 utilities
        CHECK(player1.getUtilities() == 2);

        // Checking that the utility has an owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[28])->getOwner().getName() == player1.getName());

        // puting player3 on the utility

        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[12]->addPlayer(player3);
        player3.setPosition(12);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        monopoly.payUtilityRent(player3, player1, *dynamic_cast<Utility *>(board.getBoard()[12]), 5);

        // player3 should pay 50$ to player1
        CHECK(player3.getMoney() == 1450);
        CHECK(player1.getMoney() == 1270);
    }

    SUBCASE("Cheking Taxes payment")
    {
        // puting player2 on the Income Tax slot
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[4]->addPlayer(player2);
        player2.setPosition(4);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        monopoly.SlotCheck(player2, board, 0);

        // player2 should pay 200$ to the bank
        CHECK(player2.getMoney() == 1300);

        // Checking that the money is added to the free parking
        Slot *slot = board.getBoard()[20];
        FreeParking *freeParking = dynamic_cast<FreeParking *>(slot);

        CHECK(freeParking->getMoney() == 200);

        // puting player3 on the Luxury Tax slot

        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[38]->addPlayer(player3);
        player3.setPosition(38);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        monopoly.SlotCheck(player3, board, 0);

        // player3 should pay 100$ to the bank
        CHECK(player3.getMoney() == 1400);

        // Checking that the money is added to the free parking
        CHECK(freeParking->getMoney() == 300);
    }

    SUBCASE("Checking Street buy by SlotCheck function")
    {
        // putting player2 on the street Virginia Avenue
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[14]->addPlayer(player2);
        player2.setPosition(14);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        // For the simulated input
        std::istringstream simulatedInput("y\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        monopoly.SlotCheck(player2, board, 0);

        std::cin.rdbuf(originalCin);

        // player2 should buy the street
        CHECK(player2.getMoney() == 1340);

        // Checking that player2 has the street
        CHECK(player2.getAssets().size() == 1);
        CHECK(player2.getAssets()[0]->getName() == "Virginia Avenue");

        // Checking that the street has an owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[14])->getOwner().getName() == player2.getName());

        // now putting player3 on the street Virginia Avenue and checking that he can't buy it and needs to pay the rent
        // working with the simulated input
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[14]->addPlayer(player3);
        player3.setPosition(14);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        monopoly.SlotCheck(player3, board, 0);

        // player3 should pay 12$ to player2
        CHECK(player3.getMoney() == 1488);

        CHECK(player2.getMoney() == 1352);

        // Checking that the street has an the same owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[14])->getOwner().getName() == player2.getName());

        // Checking that player3 has no assets
        CHECK(player3.getAssets().size() == 0);
    }

    SUBCASE("Checking Station buy by SlotCheck function")
    {

        // putting player1 on the station
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[5]->addPlayer(player1);
        player1.setPosition(5);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        // For the simulated input
        std::istringstream simulatedInput("your simulated input here\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        monopoly.SlotCheck(player1, board, 0);

        std::cin.rdbuf(originalCin);

        // player1 should buy the station
        CHECK(player1.getMoney() == 1300);

        // Checking that player1 has the station

        CHECK(player1.getTrains() == 1);

        // Checking that the station has an owner
        CHECK(dynamic_cast<Station *>(board.getBoard()[5])->getOwner().getName() == player1.getName());

        // now putting player2 on the station and checking that he can't buy it and needs to pay the rent
        // working with the simulated input
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[5]->addPlayer(player2);
        player2.setPosition(5);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        monopoly.SlotCheck(player2, board, 0);

        // player2 should pay 25$ to player1
        CHECK(player2.getMoney() == 1475);

        CHECK(player1.getMoney() == 1325);

        // Now player1 buyin another station
        // putting player1 on the station
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[15]->addPlayer(player1);
        player1.setPosition(15);

        // Checking that player1 has 1325$
        CHECK(player1.getMoney() == 1325);

        // For the simulated input
        std::istringstream simulatedInput2("your simulated input here\n");
        std::streambuf *originalCin2 = std::cin.rdbuf(simulatedInput2.rdbuf());

        monopoly.SlotCheck(player1, board, 0);

        std::cin.rdbuf(originalCin2);

        // player1 should buy the station
        CHECK(player1.getMoney() == 1125);

        // Checking that player1 has 2 stations
        CHECK(player1.getTrains() == 2);

        // Checking that the station has an owner
        CHECK(dynamic_cast<Station *>(board.getBoard()[15])->getOwner().getName() == player1.getName());

        // now putting player3 on the station and checking that he can't buy it and needs to pay the rent
        // working with the simulated input
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[5]->addPlayer(player3);
        player3.setPosition(5);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        monopoly.SlotCheck(player3, board, 0);

        // player3 should pay 50$ to player1
        CHECK(player3.getMoney() == 1450);

        CHECK(player1.getMoney() == 1175);
    }

    SUBCASE("Checking Utility buy by SlotCheck function")
    {
        // putting player1 on the utility
        // he won't buy it
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[12]->addPlayer(player1);
        player1.setPosition(12);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        // For the simulated input
        std::istringstream simulatedInput("n\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        monopoly.SlotCheck(player1, board, 0);

        std::cin.rdbuf(originalCin);

        // player1 should not buy the utility
        CHECK(player1.getMoney() == 1500);

        // Checking that player1 has no utilities
        CHECK(player1.getUtilities() == 0);

        // Checking that the utility has no owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[12])->getOwnerPtr() == nullptr);

        // Now player3 is buying the utility

        // putting player3 on the utility
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[12]->addPlayer(player3);
        player3.setPosition(12);

        // Checking that player3 has 1500$
        CHECK(player3.getMoney() == 1500);

        // For the simulated input
        std::istringstream simulatedInput2("y\n");
        std::streambuf *originalCin2 = std::cin.rdbuf(simulatedInput2.rdbuf());

        monopoly.SlotCheck(player3, board, 0);

        std::cin.rdbuf(originalCin2);

        // player3 should buy the utility
        CHECK(player3.getMoney() == 1350);

        // Checking that player3 has the utility
        CHECK(player3.getUtilities() == 1);

        // Checking that the utility has an owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[12])->getOwner().getName() == player3.getName());

        // now putting player2 on the utility and checking that he can't buy it and needs to pay the rent
        // working with the simulated input
        board.getBoard()[player2.getPosition()]->removePlayer(player2);
        board.getBoard()[12]->addPlayer(player2);
        player2.setPosition(12);

        // Checking that player2 has 1500$
        CHECK(player2.getMoney() == 1500);

        monopoly.SlotCheck(player2, board, 7);

        // player2 should pay 28$ to player3
        CHECK(player2.getMoney() == 1472);

        CHECK(player3.getMoney() == 1378);

        // Now player3 buyin another utility

        // putting player3 on the utility
        board.getBoard()[player3.getPosition()]->removePlayer(player3);
        board.getBoard()[28]->addPlayer(player3);
        player3.setPosition(28);

        // Checking that player3 has 1378$
        CHECK(player3.getMoney() == 1378);

        // For the simulated input
        std::istringstream simulatedInput3("y\n");
        std::streambuf *originalCin3 = std::cin.rdbuf(simulatedInput3.rdbuf());

        monopoly.SlotCheck(player3, board, 0);

        std::cin.rdbuf(originalCin3);

        // player3 should buy the utility

        CHECK(player3.getMoney() == 1228);

        // Checking that player3 has 2 utilities
        CHECK(player3.getUtilities() == 2);

        // Checking that the utility has an owner
        CHECK(dynamic_cast<Utility *>(board.getBoard()[28])->getOwner().getName() == player3.getName());

        // now putting player1 on the utility and checking that he can't buy it and needs to pay the rent
        // working with the simulated input

        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[12]->addPlayer(player1);
        player1.setPosition(12);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        monopoly.SlotCheck(player1, board, 10);

        // player1 should pay 100$ to player3
        CHECK(player1.getMoney() == 1400);

        CHECK(player3.getMoney() == 1328);
    }

    SUBCASE("Hotel buying")
    {
        // putting player1 on the street
        board.getBoard()[player1.getPosition()]->removePlayer(player1);
        board.getBoard()[1]->addPlayer(player1);
        player1.setPosition(1);

        // Checking that player1 has 1500$
        CHECK(player1.getMoney() == 1500);

        std::istringstream simulatedInput("y\n");
        std::streambuf *originalCin = std::cin.rdbuf(simulatedInput.rdbuf());

        monopoly.SlotCheck(player1, board, 0);

        std::cin.rdbuf(originalCin);

        // Checking that player1 has 1440$
        CHECK(player1.getMoney() == 1440);

        // Checking that player1 has the street
        CHECK(player1.getAssets().size() == 1);
        CHECK(player1.getAssets()[0]->getName() == "Mediterranean Avenue");

        // Checking that the street has an owner
        CHECK(dynamic_cast<Streets *>(board.getBoard()[1])->getOwner().getName() == player1.getName());

        // Now player1 will try to buy a hotel and get exception
        CHECK_THROWS(monopoly.buyHotel(player1, *dynamic_cast<Streets *>(board.getBoard()[1])));

        // lets add the houses to the street, but remove the money from player1
        player1.removeMoney(1440);

        // Adding to it 4 houses
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();
        dynamic_cast<Streets *>(board.getBoard()[1])->addHouse();

        // Checking that player1 has 0$
        CHECK(player1.getMoney() == 0);

        // Now player1 will try to buy a hotel and get exception
        CHECK_THROWS(monopoly.buyHotel(player1, *dynamic_cast<Streets *>(board.getBoard()[1])));

        // Adding the money to player1
        player1.addMoney(1440);

        monopoly.buyHotel(player1, *dynamic_cast<Streets *>(board.getBoard()[1]));

        // Checking that the street has a hotel
        CHECK(dynamic_cast<Streets *>(board.getBoard()[1])->getHotel() == true);        
    }
}
