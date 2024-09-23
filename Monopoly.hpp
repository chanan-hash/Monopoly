/**
 * This class is the game logic.
 * Here all the game course will be.
 * The turns, the actions, buying, renting , paying.
 */

#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include "Board.hpp"
#include "Player.hpp"

#include "Cards/supriseCard.hpp"
#include "Cards/AdvancedToGo.hpp"
#include "Cards/AdvancedToBoardWalk.hpp"
#include "Cards/BankPays.hpp"
#include "Cards/GoBack.hpp"
#include "Cards/Loan.hpp"
#include "Cards/GoToJail.hpp"
#include "Cards/PayPlayer.hpp"
#include "Cards/PayTax.hpp"
#include "Cards/RepairPay.hpp"
#include "Cards/TrainTrip.hpp"
#include "BoardsSlots/Streets.hpp"
#include "BoardsSlots/FreeParking.hpp"
#include "BoardsSlots/Go.hpp"
#include "BoardsSlots/Station.hpp"
#include "BoardsSlots/Slot.hpp"
#include "BoardsSlots/Utility.hpp"

const int BOARD_SIZE = 40;

using namespace std;

// class Board;
// class supriseCard;
// class Player;

class Monopoly
{

private:
    Board board;
    vector<supriseCard *> supriseCards;
    vector<Player *> players;

public:
    // Monopoly(); // Constructor will initialize the board and the suprise cards, getting Board, players and suprise cards
    int diceRoll() const;                          // Method to roll the dice
    void movePlayer(Player &player, Board &board,int doubleCount); // Method to move the player

    void SlotCheck(Player &player, Board &board, int dice); // Method to check the slot
    void payStreetRent(Player &player1, Player &player2, Streets &street);
    void buyStreet(Player &player, Streets &street);

    void payStationRent(Player &player1, Player &player2, Station &station);
    void buyStation(Player &player, Station &station);

    void payUtilityRent(Player &player1, Player &player2, Utility &utility, int dice);
    void buyUtility(Player &player, Utility &utility);

    // house and hotel buying
    void buyHouse(Player &player, Streets &street);
    void buyHotel(Player &player, Streets &street);

    bool checkIfHasAllRoad(Player &player, Streets &street) const;
    bool checkSameNumberOfHouses(Player &player, Streets &street) const;
    bool checkNumberOfHousesDiff1(Player &player, Streets &street) const;

    // Getters
    Board &getBoard();
    const Board &getBoard() const;
    vector<supriseCard *> &getSupriseCards();
    const vector<supriseCard *> &getSupriseCards() const;
    vector<Player *> &getPlayers();
    const vector<Player *> &getPlayers() const;
};

#endif // MONOPOLY_HPP