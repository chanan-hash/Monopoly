/**
 * This class will be an abstract class that represents a suprise card.
 * All the game card will inherit from this class.
 */

#ifndef SUPRISECARD_HPP
#define SUPRISECARD_HPP
#include <iostream>
#include <string>

class supriseCard
{
private:
    string name;

public:
    supriseCard(); // An empty constructor
    supriseCard(string name);
    virtual ~supriseCard() = default; // A virtual destructor
    string getName() const; // A getter for the name
    virtual void action() = 0; // This is a pure virtual function, it will be implemented by the child classes
                               // For each card the action will be different
};

using namespace std;

#endif // SUPRISECARD_HPP
