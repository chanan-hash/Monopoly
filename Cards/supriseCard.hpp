// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

/**
 * This class will be an abstract class that represents a suprise card.
 * All the game card will inherit from this class.
 */

#ifndef SUPRISECARD_HPP
#define SUPRISECARD_HPP
#include <iostream>
#include <string>
using namespace std;

class supriseCard
{
private:
    string name;
    string description;

public:
    supriseCard(); // An empty constructor
    supriseCard(string name, string description); // A constructor with parameters
    virtual ~supriseCard() = default; // A virtual destructor
    string getName() const; // A getter for the name
    string getDescription() const; // A getter for the description
    void printCard(); // A function to print the card

};

using namespace std;

#endif // SUPRISECARD_HPP
