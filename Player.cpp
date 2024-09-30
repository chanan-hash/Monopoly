// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "Player.hpp"
#include "BoardsSlots/Slot.hpp"
#include "BoardsSlots/Streets.hpp"
#include "BoardsSlots/Station.hpp"
#include "BoardsSlots/Utility.hpp"

using namespace std;

// Player::Player() : money(1500), trains(0), utilities(0), position(0) {}
Player::Player(string name) : name(name), money(1500), trains(0), utilities(0), position(0) {}

void Player::addMoney(int amount)
{
    money += amount;
}

void Player::removeMoney(int amount)
{
    money -= amount;
    if (money < 0)
    {
        cout << "Warning: " << name << " has negative money balance!" << endl;
    }
}

void Player::addAsset(Streets &asset)
{
    // setting the owner of the asset to the player
    asset.setOwner(*this);
    assets.push_back(&asset);
}

void Player::addTrain(Station &train)
{
    train.setOwner(*this);
    trains++;
}

void Player::addUtility(Utility &utility)
{
    utility.setOwner(*this);
    utilities++;
}


const string &Player::getName() const
{
    return name;
}

int Player::getMoney() const
{
    // return const_cast<int&>(money);
    return money;
}

vector<Streets *> Player::getAssets()
{
    return assets;
}

int Player::getTrains() const
{
    return trains;
}

int Player::getUtilities() const
{
    return utilities;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(int position)
{
    this->position = position;
}

void Player::setIsInJail(bool isInJail)
{
    this->isInJail = isInJail;
}

bool Player::getIsInJail() const
{
    return isInJail;
}

int Player::getTurnsInJail() const
{
    return turnsInJail;
}

void Player::setTurnsInJail(int turnsInJail)
{
    this->turnsInJail = turnsInJail;
}

void Player::setFreeJailCard(bool FreeJailCard)
{
    this->FreeJailCard = FreeJailCard;
}

bool Player::getFreeJailCard() const
{
    return FreeJailCard;
}

void Player::setMissTurn(bool missTurn)
{
    this->missTurn = missTurn;
}

bool Player::getMissTurn() const
{
    return missTurn;
}

void Player::printPlayer()
{
    cout << "Player: " << name << std::endl;
    cout << "Money: $" << money << std::endl;
    cout << "Number of trains: " << trains << std::endl;
    cout << "Number of utilities: " << utilities << std::endl;
    cout << "Assets:" << std::endl;
    for (const auto &asset : assets)
    {
        cout << "  - " << asset->getName() << std::endl;
    }
}

bool Player::operator==(const Player &other) const
{
    return name == other.name;
}

bool Player::operator!=(const Player &other) const
{
    return !(*this == other);
}

string Player::toString()
{
    string res = "";
    res += name + ", $" + to_string(money) + ", trains: " + to_string(trains) + ", utilities: " + to_string(utilities) + ", position: " + to_string(position) + ", isInJail: " + to_string(isInJail) + ", FreeJailCard: " + to_string(FreeJailCard) + ", Assetes: ";
    for (const auto &asset : assets)
    {
        res += " " + asset->getName();
    }

    return res;
}