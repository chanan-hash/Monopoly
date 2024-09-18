#include "PayTax.hpp"

PayTax::PayTax() : supriseCard("Pay Tax", "Pay poor tax of $15") {}

void PayTax::action(Player &player, Board &board)
{
    player.removeMoney(15);
    // board.getBoard()[17]->addMoney(15);
    Slot *slot = board.getBoard()[20];
    // Slot *slot = board.getBoard()[17].get();

    // Use dynamic_cast to cast the Slot pointer to a FreeParking pointer
    FreeParking *freeParking = dynamic_cast<FreeParking *>(slot);

    // Check if the cast was successful
    if (freeParking != nullptr)
    {
        // Add money to the FreeParking slot
        freeParking->addMoney(15);
    }
    else
    {
        // Handle the case where the slot is not a FreeParking slot
        std::cerr << "The slot at index 17 is not a FreeParking slot." << std::endl;
    }
}