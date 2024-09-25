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
    monopoly.initPlayers();

    // Starting the game
    // it will continue until the game is finished

    while (monopoly.isGameFinished() == false)
    {
        for (size_t i = 0; i < monopoly.getPlayers().size(); i++)
        {
            cout << "Player " << monopoly.getPlayers()[i]->getName() << " turn" << endl;
            cout << "What is your move? enter 1 to roll dice and move, 2 for buying house" << endl;
            int move;
            cin >> move;
            while (move != 1 && move != 2)
            {
                cout << "Invalid move, enter 1 to roll doce and move, 2 for buying house" << endl;
                cin >> move;
            }
            if (move == 1)
            {
                monopoly.movePlayer(*monopoly.getPlayers()[i], monopoly.getBoard(), 0);
            }
            else if (move == 2)
            {
                // need to check if from the plyer the place he wants to by
                // monopoly.buyHouse(*monopoly.getPlayers()[i], *dynamic_cast<Streets *>(monopoly.getBoard().getBoard()[monopoly.getPlayers()[i]->getPosition()]));
            }
            // Adding options for the plyaer like to print his money, his position, his properties
        }
    }

    monopoly.deletePlayers();

    return 0;
}