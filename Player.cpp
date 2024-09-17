#include "BoardsSlots/Streets.hpp"
#include "Player.hpp"
using namespace std;

// Player::Player(string name) : name(name), money(1500) {} // Default money is 1500
Player::Player(string name) : name(name), money(1500), trains(0), utilities(0) {}

void Player::addMoney(int amount) {
    money += amount;
}

void Player::removeMoney(int amount) {
    money -= amount;
    if (money < 0) {
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

void Player::addAsset(Streets& asset) {
    assets.push_back(asset);
}

// void Player::removeAsset(Streets& asset) {
//     auto it = find(assets.begin(), assets.end(), asset);
//     if (it != assets.end()) {
//         assets.erase(it);
//     }
// }


void Player::addTrain(Station& train) {
    assets.push_back(train);
    trains++;
}

// void Player::removeTrain(Station& train) {
//     auto it = find(assets.begin(), assets.end(), train);
//     if (it != assets.end()) {
//         assets.erase(it);
//         trains--;
//     }
// }

void Player::addUtility(Utility& utility) {
    assets.push_back(utility);
    utilities++;
}

// void Player::removeUtility(Utility& utility) {
//     auto it = std::find(assets.begin(), assets.end(), utility);
//     if (it != assets.end()) {
//         assets.erase(it);
//         utilities--;
//     }
// }

string& Player::getName() const {
    return const_cast<string&>(name);
}

int Player::getMoney() const {
    // return const_cast<int&>(money);
    return money;
}

vector<supriseCard> Player::getCard() {
    return card;
}

vector<Slot> Player::getAssets() {
    return assets;
}

int Player::getTrains() const {
    return trains;
}

int Player::getUtilities() const {
    return utilities;
}

int Player::getPosition() const {
    return position;
}

void Player::setPosition(int position) {
    this->position = position;
}


void Player::printPlayer() {
    std::cout << "Player: " << name << std::endl;
    std::cout << "Money: $" << money << std::endl;
    std::cout << "Number of trains: " << trains << std::endl;
    std::cout << "Number of utilities: " << utilities << std::endl;
    std::cout << "Assets:" << std::endl;
    for (const auto& asset : assets) {
        std::cout << "  - " << asset.getName() << std::endl;
    }
    // std::cout << "Cards:" << std::endl;
    // for (const auto& c : card) {
    //     std::cout << "  - " << c.getDescription() << std::endl;
    // }
}

bool Player::operator==(const Player& other) const {
    return name == other.name;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}