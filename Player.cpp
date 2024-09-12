#include "Player.hpp"
using namespace std;

Player::Player(string name) : name(name), money(0) {}

// void Player::addMoney(int amount) {
//     money += amount;
// }

// void Player::removeMoney(int amount) {
//     money -= amount;
// }

// void Player::addCard(supriseCard card) {
//     // Implementation needed
// }

// void Player::removeCard(supriseCard card) {
//     // Implementation needed
// }

// void Player::addAsset(assets asset) {
//     // Implementation needed
// }

// void Player::removeAsset(assets asset) {
//     // Implementation needed
// }

// const string& Player::getName() const {
//     return name;
// }

// int Player::getMoney() const {
//     return money;
// }

// vector<supriseCard> Player::getCard() {
//     // Implementation needed
//     return card;
// }

// vector<assets> Player::getAssets() {
//     // Implementation needed
//     return assets;
// }

// void Player::printPlayer() {
//     // Implementation needed
// }

// ostream& operator<<(ostream& os, const Player& player) {
//     os << "Player Name: " << player.name << ", Money: " << player.money;
//     return os;
// }

bool Player::operator==(const Player& other) const {
    return name == other.name;
}

bool Player::operator!=(const Player& other) const {
    return name != other.name;
}