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
            cout << "What is your move? Enter the corresponding number:\n"
                 << "1. Roll dice\n"
                 << "2. See your details\n"
                 << "3. Buy a house\n"
                 << "4. Buy a hotel\n"
                 << "5. Print the board" << endl;
            int move;
            cin >> move;
            while (move < 1 || move > 5)
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
                cout << "Player: " << monopoly.getPlayers()[i]->getName() << ", " << monopoly.getPlayers()[i]->toString() << endl;
            }
            else if (move == 3)
            {
                cout << "Enter the name of the street you want to buy a house on" << endl;
                string streetName;
                cin >> streetName;
                // neet to find the name of the street in the player assets, so we need to get the player assets and look
                // for the street with the same name
                vector<Streets *> assets = monopoly.getPlayers()[i]->getAssets();
                for (size_t j = 0; j < assets.size(); j++)
                {
                    if (assets[j]->getName() == streetName)
                    {
                        try
                        {
                            monopoly.buyHouse(*monopoly.getPlayers()[i], *assets[j]);
                        }
                        catch (const char *msg)
                        {
                            cout << msg << endl;
                        }
                    }
                }
                cout << "Street not found, check your assetes for name in option 2, and try again" << endl;
            }
            else if (move == 4)
            {
                cout << "Enter the name of the street you want to buy a hotel on" << endl;
                string streetName;
                cin >> streetName;
                // neet to find the name of the street in the player assets, so we need to get the player assets and look
                // for the street with the same name
                vector<Streets *> assets = monopoly.getPlayers()[i]->getAssets();
                for (size_t j = 0; j < assets.size(); j++)
                {
                    if (assets[j]->getName() == streetName)
                    {
                        try
                        {
                            monopoly.buyHotel(*monopoly.getPlayers()[i], *assets[j]);
                        }
                        catch (const char *msg)
                        {
                            cout << msg << endl;
                        }
                    }
                }
                cout << "Street not found, check your assetes for name in option 2, and try again" << endl;
            }
            else if (move == 5)
            {
                // monopoly.getBoard().printBoard();
                // will be with << operator
                // cout << monopoly.getBoard() << endl;
            }
        }
    }

    monopoly.deletePlayers();

    return 0;
}