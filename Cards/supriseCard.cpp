#include "supriseCard.hpp"

using namespace std;

supriseCard::supriseCard() {}

supriseCard::supriseCard(string name, string description) : name(name), description(description) {} // initialize list

// supriseCard::~supriseCard() = default;

string supriseCard::getName() const
{
    return this->name;
}

string supriseCard::getDescription() const
{
    return this->description;
}

void supriseCard::printCard()
{
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
}

// Will be for the gui maybe
ostream &operator<<(ostream &os, const supriseCard &card)
{
    os << card.getName();
    return os;
}