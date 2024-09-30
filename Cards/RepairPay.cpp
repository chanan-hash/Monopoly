// Author: Chanan-Helman
// mail: chanan.Helman@msmail.ariel.ac.il

#include "RepairPay.hpp"
#include "../BoardsSlots/Slot.hpp"
#include "../Player.hpp"
#include "../Board.hpp"
#include "../BoardsSlots/Streets.hpp"

RepairPay::RepairPay() : supriseCard("RepairPay", "Make general repairs on all your property: For each house pay $25, For each hotel $100")
{
}

void RepairPay::action(Player &player)
{
    int houseCount = 0;
    int hotelCount = 0;
    for (auto &property : player.getAssets())
    {
        // Use dynamic_cast to check if the property is of type Streets
        Streets *street = dynamic_cast<Streets *>(property);
        if (street != nullptr)
        {
            houseCount += street->getHouses();
            if (street->getHotel())
            {
                hotelCount++;
            }
        }
    }

    // Now you can use houseCount and hotelCount as needed
    int totalRepairCost = houseCount * 25 + hotelCount * 100;
    player.removeMoney(totalRepairCost);
}