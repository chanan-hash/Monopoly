/*
* Here we're creating the board for the game.
* It will be initialized with 40 slots, like the monopoly board.
*/

#include"Board.hpp"

using namespace std;
// Iinitialize list
Board::Board () : slots(40) {
    // Create the slots
    // slots[0] = new Go();
    // slots[1] = new Streets("Old Kent Road", 60, 2, 10, 30, 90, 160, 250, 50);
    // slots[2] = new FreeParking();
    // slots[3] = new Streets("Whitechapel Road", 60, 4, 20, 60, 180, 320, 450, 50);
    // slots[4] = new Tax("Income Tax", 200);
    // slots[5] = new Station("Kings Cross Station", 200);
    // slots[6] = new Streets("The Angel Islington", 100, 6, 30, 90, 270, 400, 550, 50);
    // slots[7] = new Utility("Electric Company", 150);
    // slots[8] = new Streets("Euston Road", 100, 6, 30, 90, 270, 400, 550, 50);
    // slots[9] = new Streets("Pentonville Road", 120, 8, 40, 100, 300, 450, 600, 50);
    // slots[10] = new Jail();
    // slots[11] = new Streets("Pall Mall", 140, 10, 50, 150, 450, 625, 750, 100);
    // slots[12] = new Streets("Electric Company", 150, 0, 0, 0, 0, 0, 0, 0);
    // slots[13] = new Streets("Whitehall", 140, 10, 50, 150, 450, 625, 750, 100);
    // slots[14] = new Streets("Northumberland Avenue", 160, 12, 60, 180, 500, 700, 900, 100);
    // slots[15] = new Station("Marylebone Station", 200);
    // slots[16] = new Streets("Bow Street", 180, 14, 70, 200, 550, 750, 950, 100);
    // slots[17] = new FreeParking();
    // slots[18] = new Streets("Marlborough Street",
    //                         180, 14, 70, 200, 550, 750, 950, 100);
    // slots[19] = new Streets("Vine Street", 200, 16, 80, 220, 600, 800, 1000, 100);
    // slots[20] = new GoToJail();
    // slots[21] = new Streets("Strand", 220, 18, 90, 250, 700, 875, 1050, 150);
    // slots[22] = new Streets("Fleet Street", 220, 18, 90, 250, 700, 875, 1050, 150);
    // slots[23] = new Streets("Trafalgar Square", 240, 20, 100, 300, 750, 925, 1100, 150);
    // slots[24] = new Streets("Fenchurch Street Station", 200);
    // slots[25] = new Streets("Leicester Square", 260, 22, 110, 330, 800, 975, 1150, 150);
    // slots[26] = new Streets("Coventry Street", 260, 22, 110, 330, 800, 975, 1150, 150);
    // slots[27] = new Utility("Water Works", 150);
    // slots[28] = new Streets("Piccadilly", 280, 24, 120, 360, 850, 1025, 1200, 150);
    // slots[29] = new Streets("Regent Street", 300, 26, 130, 390, 900, 1100, 1275, 200);
    // slots[30] = new FreeParking();
    // slots[31] = new Streets("Oxford Street", 300, 26, 130, 390, 900, 1100, 1275, 200);
    // slots[32] = new Streets("Bond Street", 320, 28, 150, 450, 1000, 1200, 1400, 200);
    // slots[33] = new Station("Liverpool Street Station", 200);
    // slots[34] = new Streets("Park Lane", 350, 35, 175, 500, 1100, 1300, 1500, 200);
    // slots[35] = new Tax("Super Tax", 100);
    // slots[36] = new Streets("Mayfair", 400, 50, 200, 600, 1400, 1700, 2000, 200);
    // slots[37] = new FreeParking();
    // slots[38] = new Streets("Kings Cross Station", 200);
    // slots[39] = new Streets("Old Kent Road", 60, 2, 10, 30, 90, 160, 250, 50);
}

// Board::~Board() {
//     // Delete the slots
//     for (int i = 0; i < 40; i++) {
//         delete slots[i];
//     }
// }

// vector<Slot *> Board::getBoard() {
//     return slots;
// }

// void Board::printBoard() {
//     for (int i = 0; i < 40; i++) {
//         cout << *slots[i] << endl;
//     }
// }

// friend operator << printing with gui
