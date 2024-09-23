#include "Player.hpp"
#include "BoardsSlots/Slot.hpp"
#include "BoardsSlots/Streets.hpp"
#include "BoardsSlots/Station.hpp"
#include "BoardsSlots/Utility.hpp"

using namespace std;

// Player::Player(string name) : name(name), money(1500) {} // Default money is 1500
Player::Player(string name) : name(name), money(1500), trains(0), utilities(0) {}

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

// need to handle the abstration of the card
// void Player::addCard(supriseCard card) {
//     this->card.push_back(card);
// }

// void Player::removeCard(supriseCard card) {
//     auto it = std::find(this->card.begin(), this->card.end(), card);
//     if (it != this->card.end()) {
//         this->card.erase(it);
//     }
// }

void Player::addAsset(Streets &asset)
{
    // setting the owner of the asset to the player
    asset.setOwner(*this);
    assets.push_back(&asset);
}

// void Player::removeAsset(Streets& asset) {
//     auto it = find(assets.begin(), assets.end(), asset);
//     if (it != assets.end()) {
//         assets.erase(it);
//     }
// }

void Player::addTrain(Station &train)
{
    train.setOwner(*this);
    trains++;
}

// void Player::removeTrain(Station& train) {
//     auto it = find(assets.begin(), assets.end(), train);
//     if (it != assets.end()) {
//         assets.erase(it);
//         trains--;
//     }
// }

void Player::addUtility(Utility &utility)
{
    utility.setOwner(*this);
    utilities++;
}

// void Player::removeUtility(Utility& utility) {
//     auto it = std::find(assets.begin(), assets.end(), utility);
//     if (it != assets.end()) {
//         assets.erase(it);
//         utilities--;
//     }
// }

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