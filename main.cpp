#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <sstream>
#include <SFML/Graphics.hpp>
// #include "MonopolyBoardGUI.hpp"

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
            bool hasRolledDice = false;
            bool endTurn = false;

            // Helping us to do several moves in this turn
            while (!endTurn)
            {
                cout << "What is your move? Enter the corresponding number:\n"
                     << "1. Roll dice\n"
                     << "2. See your details\n"
                     << "3. Buy a house\n"
                     << "4. Buy a hotel\n"
                     << "5. Print the board\n"
                     << "6. End turn " << endl;
                int move;
                cin >> move;
                while (move < 1 || move > 6)
                {
                    cout << "Invalid move, enter number between 1 and 6" << endl;
                    cin >> move;
                }

                if (move == 1)
                {
                    if (!hasRolledDice)
                    {

                        monopoly.movePlayer(*monopoly.getPlayers()[i], monopoly.getBoard(), 0);
                        hasRolledDice = true;
                    }
                    else
                    {
                        cout << "You have already rolled the dice, you can't roll again" << endl;
                    }
                }
                else if (move == 2)
                {
                    cout << "Player: " << monopoly.getPlayers()[i]->getName() << ", " << monopoly.getPlayers()[i]->toString() << endl;
                }
                else if (move == 3)
                {
                    cout << "Enter the name of the street you want to buy a house on" << endl;
                    string streetName;
                    getline(cin >> ws, streetName);

                    vector<Streets *> assets = monopoly.getPlayers()[i]->getAssets();
                    bool streetFound = false;

                    for (size_t j = 0; j < assets.size(); j++)
                    {
                        cout << "You have: " << assets[j]->getName() << endl;

                        if (assets[j]->getName() == streetName)
                        {
                            streetFound = true;
                            try
                            {
                                monopoly.buyHouse(*monopoly.getPlayers()[i], *assets[j]);
                            }
                            catch (exception &e)
                            {
                                cout << e.what() << endl;
                            }
                            break;
                        }
                    }
                    if (!streetFound)
                    {
                        cout << "Street not found, check your assets for name in option 2, and try again" << endl;
                    }
                }
                else if (move == 4)
                {

                    cout << "Enter the name of the street you want to buy a hotel on" << endl;
                    string streetName;
                    getline(cin >> ws, streetName);

                    vector<Streets *> assets = monopoly.getPlayers()[i]->getAssets();
                    bool streetFound = false;
                    for (size_t j = 0; j < assets.size(); j++)
                    {
                        if (assets[j]->getName() == streetName)
                        {
                            streetFound = true;
                            try
                            {
                                monopoly.buyHotel(*monopoly.getPlayers()[i], *assets[j]);
                            }
                            catch (exception &e)
                            {
                                cout << e.what() << endl;
                            }
                            break;
                        }
                    }
                    if (!streetFound)
                    {
                        cout << "Street not found, check your assets for name in option 2, and try again" << endl;
                    }
                }
                else if (move == 5)
                {
                    // monopoly.getBoard().printBoard();
                    // will be with << operator
                    std::cout << monopoly.getBoard() << endl;
                }
                else if (move == 6)
                {
                    if (!hasRolledDice) // if hasn't rolled the dice, we can't end the turn
                    {
                        cout << "You have to roll the dice before ending the turn" << endl;
                    }
                    else
                    {
                        endTurn = true;
                    }
                }
            }
        }
    }

    monopoly.deletePlayers();

    return 0;
}