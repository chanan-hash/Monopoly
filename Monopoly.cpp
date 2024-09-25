#include "Monopoly.hpp"
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>

Monopoly::Monopoly() // inintilize the board and the suprise cards, we won't initilize the players here because of the test,it good to separate the initilization of the players from the constructor
{
    // The board initialization will be done in the Board constructor
    initSupriseCards();
}

Monopoly::~Monopoly()
{
    // Deleting the players, we'll have to use the init function to delete the players
    // for (size_t i = 0; i < players.size(); i++)
    // {
    //     delete players[i];
    // }

    // Deleting the suprise cards
    for (size_t i = 0; i < supriseCards.size(); i++)
    {
        delete supriseCards[i];
    }
}

int Monopoly::diceRoll() const
{
    // srand(time(NULL));

    return (rand() % 6) + 1;
}

void Monopoly::movePlayer(Player &player, Board &board, int doubleCount)
{
    int dice1 = diceRoll();
    int dice2 = diceRoll();
    int dice = dice1 + dice2;

    // need to check if the player is in jail
    bool inJail = player.getIsInJail();

    bool missTurn = player.getMissTurn();

    if (doubleCount == 3)
    {
        cout << "Player " << player.getName() << " rolled 3 doubles in a row, he will go to jail" << endl;
        board.getBoard()[player.getPosition()]->removePlayer(player);
        player.setPosition(10);
        board.getBoard()[10]->addPlayer(player);
        player.setIsInJail(true);
        return;
    }

    if (missTurn) // if the player has to miss a turn we just return
    {
        player.setMissTurn(false);
        cout << "Player " << player.getName() << " has to miss a turn" << endl;
        return;
    }

    if (inJail && (dice1 != dice2) && !player.getFreeJailCard()) // if the player is in jail and didn't roll a double, and he doesn't have a free jail card
    {
        cout << "Player " << player.getName() << " is in jail" << endl;
        cout << "Do you want to pay 50$ to get out of jail? (y/n)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            player.removeMoney(50);
            player.setIsInJail(false);
        }
        else if (player.getTurnsInJail() == 2) // in the beginning of the 3rd turn if the player didn't pay the 50$ he will pay it
        {
            cout << "Player " << player.getName() << " has been in jail for 3 turns, he will pay 50$ to get out" << endl;
            player.removeMoney(50);
            player.setIsInJail(false);
        }
        else
        {
            cout << "Player " << player.getName() << " will stay in jail" << endl;
            player.setTurnsInJail(player.getTurnsInJail() + 1);
            return;
        }
    }
    else if (inJail && (dice1 == dice2)) // if the player is in jail and rolled a double
    {
        player.setIsInJail(false);
    }

    else if (player.getFreeJailCard())
    {
        cout << "Do you want to use your free jail card? (y/n)" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            player.setFreeJailCard(false);
            player.setIsInJail(false);
        }
        else
        {
            return; // didn't use the free jail card stay in jail
        }
    }

    int oldPosition = player.getPosition(); // for checking if the player passed the Go slot

    cout << "Player " << player.getName() << " rolled " << dice1 << " and " << dice2 << " for a total of " << dice << endl;

    board.getBoard()[player.getPosition()]->removePlayer(player); // remove the player from the current slot

    player.setPosition((player.getPosition() + dice) % BOARD_SIZE); // for the case of passing the Go slot

    board.getBoard()[player.getPosition()]->addPlayer(player); // add the player to the new slot

    // check if the player passed the Go slot
    if (oldPosition > player.getPosition())
    {
        Go *go = dynamic_cast<Go *>(board.getBoard()[0]);
        go->add200(player);
    }

    // Now all the checkup
    SlotCheck(player, board, dice);

    // Checking if the player rolled a double
    if (dice1 == dice2)
    {
        cout << "Player " << player.getName() << " rolled a double, he can roll again" << endl;
        doubleCount++;
        movePlayer(player, board, doubleCount);
    }
}

void Monopoly::SlotCheck(Player &player, Board &board, int dice)
{
    // Getting the slot from player position
    Slot *slot = board.getBoard()[player.getPosition()];

    cout << "Player " << player.getName() << " landed on " << slot->getName() << endl;

    // If the slot is a street
    if (slot->getType() == "Property")
    {
        Streets *street = dynamic_cast<Streets *>(slot);
        // Checking if the street is owned
        if (street->getOwnerPtr() != nullptr)
        {
            payStreetRent(player, street->getOwner(), *street);
        }
        else
        {
            cout << "Do you want to buy this street? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                buyStreet(player, *street);
            }
        }
    }

    // If the slot is a station
    else if (slot->getType() == "Station")
    {
        Station *station = dynamic_cast<Station *>(slot);
        // Checking if the station is owned
        if (station->getOwnerPtr() != nullptr)
        {
            payStationRent(player, station->getOwner(), *station);
        }
        else
        {
            cout << "Do you want to buy this station? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                buyStation(player, *station);
            }
        }
    }

    else if (slot->getType() == "Utility")
    {
        Utility *utility = dynamic_cast<Utility *>(slot);
        // Checking if the utility is owned
        if (utility->getOwnerPtr() != nullptr)
        {
            payUtilityRent(player, utility->getOwner(), *utility, dice);
        }
        else
        {
            cout << "Do you want to buy this utility? (y/n)" << endl;
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                buyUtility(player, *utility);
            }
        }
    }

    // Checking if it is a GO slot
    else if (slot->getName() == "Go")
    {

        Go *go = dynamic_cast<Go *>(slot);

        // if the player lands on go he gets 400$
        go->add400(player);
    }

    // need to add the other slots
    // doing the tasxes slots
    else if (slot->getName() == "Income Tax")
    {
        player.removeMoney(200);
        // Adding it to the free parking
        FreeParking *freeParking = dynamic_cast<FreeParking *>(board.getBoard()[20]);
        freeParking->addMoney(200);
    }
    else if (slot->getName() == "Luxury Tax")
    {
        player.removeMoney(100);
        // Adding it to the free parking
        FreeParking *freeParking = dynamic_cast<FreeParking *>(board.getBoard()[20]);
        freeParking->addMoney(100);
    }

    // Free parking slot
    else if (slot->getName() == "Free Parking")
    {
        FreeParking *freeParking = dynamic_cast<FreeParking *>(slot);
        // FreeParking *freeParking = dynamic_cast<FreeParking *>(board.getBoard()[20]);

        freeParking->addMoneyToPlayer(player); // adding all the money in the free parking to the player
        player.setMissTurn(true);              // the player will miss the next turn
    }
    // jail slot
    else if (slot->getName() == "Go To Jail")
    {
        // Removing the player from the slot
        slot->removePlayer(player);
        // Adding the player to the jail slot
        Slot *jail = board.getBoard()[10];
        jail->addPlayer(player);
        player.setPosition(10); // setting his position to the jail slot

        player.setIsInJail(true);
    }

    // Card slots
    else if (slot->getName() == "Chance" || slot->getName() == "Community Chest")
    {
        // Getting a random card
        supriseCard *card = supriseCards[0]; // taking the first card

        cout << "Player " << player.getName() << " picked a card: " << card->getName() << " " << card->getDescription() << endl;

        // will use switch case to check the type of the card and according to that do the action

        string cardName = card->getName();
        if (cardName == "AdvancedToGo")
        {
            AdvancedToGo *advanceToGo = dynamic_cast<AdvancedToGo *>(card);
            advanceToGo->action(player, board);
        }

        else if (cardName == "Advanced To Boardwalk")
        {
            AdvancedToBoardWalk *advanceToBoardWalk = dynamic_cast<AdvancedToBoardWalk *>(card);
            advanceToBoardWalk->action(player, board);
            // need ot check if the  street or not and owned or not
            Slot *slot = board.getBoard()[player.getPosition()];
            Streets *street = dynamic_cast<Streets *>(slot);
            // Checking if the street is owned
            if (street->getOwnerPtr() != nullptr)
            {
                payStreetRent(player, street->getOwner(), *street);
            }
            else
            {
                cout << "Do you want to buy this street? (y/n)" << endl;
                char answer;
                cin >> answer;
                if (answer == 'y')
                {
                    buyStreet(player, *street);
                }
            }
        }

        else if (cardName == "BankPays")
        {
            BankPays *bankPays = dynamic_cast<BankPays *>(card);
            bankPays->action(player);
        }

        else if (cardName == "GoBack")
        {
            GoBack *goBack = dynamic_cast<GoBack *>(card);
            goBack->action(player, board);

            // need ot check if the slot is a street or not and owned or not
            Slot *slot = board.getBoard()[player.getPosition()];
            if (slot->getType() == "Property")
            {
                Streets *street = dynamic_cast<Streets *>(slot);
                // Checking if the street is owned
                if (street->getOwnerPtr() != nullptr)
                {
                    payStreetRent(player, street->getOwner(), *street);
                }
                else
                {
                    cout << "Do you want to buy this street? (y/n)" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y')
                    {
                        buyStreet(player, *street);
                    }
                }
            }
            else if (slot->getType() == "Station") // if it a satation
            {
                Station *station = dynamic_cast<Station *>(slot);
                // Checking if the station is owned
                if (station->getOwnerPtr() != nullptr)
                {
                    payStationRent(player, station->getOwner(), *station);
                }
                else
                {
                    cout << "Do you want to buy this station? (y/n)" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y')
                    {
                        buyStation(player, *station);
                    }
                }
            }
            else if (slot->getType() == "Utility") // if it a utility
            {
                Utility *utility = dynamic_cast<Utility *>(slot);
                // Checking if the utility is owned
                if (utility->getOwnerPtr() != nullptr)
                {
                    payUtilityRent(player, utility->getOwner(), *utility, dice);
                }
                else
                {
                    cout << "Do you want to buy this utility? (y/n)" << endl;
                    char answer;
                    cin >> answer;
                    if (answer == 'y')
                    {
                        buyUtility(player, *utility);
                    }
                }
            }
        }

        else if (cardName == "Loan")
        {
            Loan *loan = dynamic_cast<Loan *>(card);
            loan->action(player);
        }
        else if (cardName == "GoToJail")
        {
            GoToJail *goToJail = dynamic_cast<GoToJail *>(card);
            goToJail->action(player, board);
        }
        else if (cardName == "Pay Player")
        {
            PayPlayer *payPlayer = dynamic_cast<PayPlayer *>(card);
            payPlayer->action(player, players);
        }
        else if (cardName == "Pay Tax")
        {
            PayTax *payTax = dynamic_cast<PayTax *>(card);
            payTax->action(player, board);
        }
        else if (cardName == "RepairPay")
        {
            RepairPay *repairPay = dynamic_cast<RepairPay *>(card);
            repairPay->action(player);
        }
        else if (cardName == "Train Trip")
        {
            TrainTrip *trainTrip = dynamic_cast<TrainTrip *>(card);
            trainTrip->action(player, board);
            // checking if the station is owned
            // if it is owned the player will pay the rent, the train is Reading Railroad
            // if it is not owned the player will have the option to buy it

            Station *station = dynamic_cast<Station *>(board.getBoard()[5]);
            if (station->getOwnerPtr() != nullptr)
            {
                payStationRent(player, station->getOwner(), *station);
            }
            else
            {
                cout << "Do you want to buy this station? (y/n)" << endl;
                char answer;
                cin >> answer;
                if (answer == 'y')
                {
                    buyStation(player, *station);
                }
            }
        }
        else if (cardName == "Free Jail")
        {
            FreeJail *freeJail = dynamic_cast<FreeJail *>(card);
            freeJail->action(player);
        }

        // Removing the card from the vector
        supriseCards.erase(supriseCards.begin());
        // Adding it to the end of the vector
        supriseCards.push_back(card);
    }
}

// Handling the street rent
void Monopoly::payStreetRent(Player &player1, Player &player2, Streets &street)
{
    // Streets *street = dynamic_cast<Streets *>(board.getBoard()[player1.getPosition()]);
    // Checking if the street has houses
    if (street.getHouses() > 0)
    {
        int renth = street.getRent() * pow(2, street.getHouses());
        //         int renth = street.getRent() * pow(2, street.getHouses() -1);

        player1.removeMoney(renth);
        player2.addMoney(renth);
    }
    // Checking if the street has a hotel
    else if (street.getHotel())
    {
        int rentH = (street.getRent() * 10);
        player1.removeMoney(rentH);
        player2.addMoney(rentH);
    }
    else
    {
        int rent = street.getRent();
        player1.removeMoney(rent);
        player2.addMoney(rent);
    }
}

void Monopoly::buyStreet(Player &player, Streets &street)
{
    if (player.getMoney() < street.getPrice())
    {
        cout << "You don't have enough money to buy this street" << endl;
        return;
    }
    player.removeMoney(street.getPrice());
    player.addAsset(street);
}

// Handling the station rent
void Monopoly::payStationRent(Player &player1, Player &player2, Station &station)
{
    // Checking how many stations the owner has
    int stations = player2.getTrains();
    int rent = station.getRent() * pow(2, stations - 1);
    player1.removeMoney(rent);
    player2.addMoney(rent);
}

void Monopoly::buyStation(Player &player, Station &station)
{
    if (player.getMoney() < station.getPrice())
    {
        cout << "You don't have enough money to buy this station" << endl;
        return;
    }
    player.removeMoney(station.getPrice());
    player.addTrain(station);
}

// Handling the utility rent
// The rent payment is according to the number of utilities the owner and the dice result
void Monopoly::payUtilityRent(Player &player1, Player &player2, Utility &utility, int dice)
{
    // Checking how many utilities the owner has
    int utilities = player2.getUtilities();
    int rent = 0;

    if (utilities == 1)
    {
        rent = 4 * dice;
    }

    else if (utilities == 2)
    {
        rent = 10 * dice;
    }

    player1.removeMoney(rent);
    player2.addMoney(rent);
}

void Monopoly::buyUtility(Player &player, Utility &utility)
{
    if (player.getMoney() < utility.getPrice())
    {
        cout << "You don't have enough money to buy this utility" << endl;
        return;
    }
    player.removeMoney(utility.getPrice());
    player.addUtility(utility);
}

// house and hotel buying
// To buy a house the player should have all the streets of the same color
// then to buy another house the player should have the same number of houses on all the streets, or not more than one difference
void Monopoly::buyHouse(Player &player, Streets &street)
{
    if (!checkIfHasAllRoad(player, street)) // Here we're checking if the player has all the streets of the same color
    {
        // cout << "You need to have all the streets of the same color to buy a house" << endl;
        // return;
        throw runtime_error("You need to have all the streets of the same color to buy a house"); // in the main we'll catch it
    }
    if (player.getMoney() < street.getHousePrice())
    {
        // cout << "You don't have enough money to buy a house" << endl;
        // return;
        throw runtime_error("You don't have enough money to buy a house"); // in the main we'll catch it
    }
    if (!checkSameNumberOfHouses(player, street)) // Here we're checking if the player has the same number of houses on all the streets
    {
        // cout << "You need to have the same number of houses on all the streets to buy a house" << endl;
        // return;
        throw runtime_error("You need to have the same number of houses on all the streets to buy a house"); // in the main we'll catch it
    }

    // If the player has all the streets of the same color and the same number of houses on all the streets
    player.removeMoney(street.getHousePrice());
    street.addHouse();
}

// To buy a hotel the player should have 4 houses on the street, so we need to check that
// The price of a hotel is 4 times the price of a house + 100

void Monopoly::buyHotel(Player &player, Streets &street)
{
    if (street.getHouses() < 4)
    {
        // cout << "You need to have 4 houses on the street to buy a hotel" << endl;
        // return;
        throw runtime_error("You need to have 4 houses on the street to buy a hotel"); // in the main we'll catch it
    }
    if (player.getMoney() < street.getHousePrice() * 4 + 100)
    {
        // cout << "You don't have enough money to buy a hotel" << endl;
        // return;
        throw runtime_error("You don't have enough money to buy a hotel"); // in the main we'll catch it
    }
    player.removeMoney(street.getHousePrice() * 4 + 100);
    street.addHotel();
}

// helper function to check if the player has all the streets of a color
bool Monopoly::checkIfHasAllRoad(Player &player, Streets &street) const
{
    string color = street.getColor();
    int count = 0;

    // In dark blue the player should have 2 streets
    if (color == "Dark Blue" || color == "Brown")
    {
        for (auto asset : player.getAssets())
        {
            Streets *street = dynamic_cast<Streets *>(asset);
            if (street != nullptr && street->getColor() == color)
            {
                count++;
            }
        }
        if (count == 2)
        {
            return true;
        }
        return false;
    }
    else
    {
        for (auto asset : player.getAssets())
        {
            Streets *street = dynamic_cast<Streets *>(asset);
            if (street != nullptr && street->getColor() == color)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
        return false;
    }
}

// helper function to check if the player has the same number of houses on all the streets
bool Monopoly::checkSameNumberOfHouses(Player &player, Streets &street) const
{
    string color = street.getColor(); // getting the color of the street

    int houses = street.getHouses(); // getting the number of houses on the street

    for (auto asset : player.getAssets())
    {
        Streets *otherStreet = dynamic_cast<Streets *>(asset);
        if (otherStreet != nullptr && otherStreet->getColor() == color && street.getName() != otherStreet->getName()) // checking if the street has the same color
        {
            int otherHouses = otherStreet->getHouses();
            if (houses > otherHouses) // checking if the difference in houses is more than one, if the street has more houses than the other street, we can't build more
            {
                return false;
            }
        }
    }
    return true;
}

void Monopoly::initPlayers()
{
    int numPlayers;
    cout << "Enter the number of players (between 2 and 8): ";
    cin >> numPlayers;

    if (numPlayers < 2 || numPlayers > 8)
    {
        cout << "Invalid number of players" << endl;
        return;
    }

    for (int i = 0; i < numPlayers; i++)
    {
        string name;
        cout << "Enter the name of player " << i + 1 << ": ";
        cin >> name;
        players.push_back(new Player(name));
    }
}

void Monopoly::initSupriseCards()
{
    // Need to create the cards and add them to the vector
    supriseCards.push_back(new AdvancedToGo());
    supriseCards.push_back(new AdvancedToBoardWalk());
    supriseCards.push_back(new BankPays());
    supriseCards.push_back(new GoBack());
    supriseCards.push_back(new Loan());
    supriseCards.push_back(new GoToJail());
    supriseCards.push_back(new PayPlayer());
    supriseCards.push_back(new PayTax());
    supriseCards.push_back(new RepairPay());
    supriseCards.push_back(new TrainTrip());
    supriseCards.push_back(new FreeJail());
}

bool Monopoly::didLose(Player &player)
{
    if (player.getMoney() < 0)
    {
        cout << "Player " << player.getName() << " lost" << endl;
        // let's remove the player from the game
        // removing the player from the board
        board.getBoard()[player.getPosition()]->removePlayer(player);
        // removing the player from the players vector
        for (size_t i = 0; i < players.size(); i++)
        {
            if (players[i]->getName() == player.getName())
            {
                players.erase(players.begin() + i);
                return true;
            }
        }
    }
    return false;
}

bool Monopoly::isGameFinished() const
{
    return players.size() == 1;
}

void Monopoly::printWinner()
{
    if (isGameFinished())
    {
        cout << "The winner is: " << players[0]->getName() << endl;
    }
    else
    {
        return;
    }
}

// Getters

// getting the cards
const vector<supriseCard *> &Monopoly::getSupriseCards() const
{
    return supriseCards;
}

vector<supriseCard *> &Monopoly::getSupriseCards()
{
    return supriseCards;
}

// getting the players
const vector<Player *> &Monopoly::getPlayers() const
{
    return players;
}

vector<Player *> &Monopoly::getPlayers()
{
    return players;
}
