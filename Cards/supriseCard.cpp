#include "supriseCard.hpp"

using namespace std;

supriseCard::supriseCard(){}

supriseCard::supriseCard(string name, string description) : name (name), description(description) {} // initialize list

supriseCard::~supriseCard() = default;

string supriseCard::getName() const
{
    return this->name;
}

// Will be for the gui maybe
ostream& operator<<(ostream& os, const supriseCard& card)
{
    os << card.getName();
    return os;
}