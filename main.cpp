#include <iostream>
#include <vector>
#include <string>

#include "Monopoly.hpp"

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
#include "Cards/FreeJail.hpp"

#include "BoardsSlots/Streets.hpp"
#include "BoardsSlots/FreeParking.hpp"

using namespace std;

int main()
{
    // Creating the game
    Monopoly monopoly;
    cout << "Welcome to Monopoly" << endl;

    // Initializing the players
    // monopoly.initPlayers();

    // // Starting the game
    // // it will continue until the game is finished

    // while (monopoly.isGameFinished() == false)
    // {
    //     for (size_t i = 0; i < monopoly.getPlayers().size(); i++)
    //     {
    //         monopoly.movePlayer(*monopoly.getPlayers()[i], monopoly.getBoard(), 0);
    //     }
    // }

    // monopoly.deletePlayers();

    return 0;
}