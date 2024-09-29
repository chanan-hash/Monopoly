# Monoply Game

This project is a simple version of the famous game Monopoly

the rulse you can find in this repository:
[Monopoly final project rules](https://github.com/BenjaminSaldman/CPP_final_project_summer/tree/main)

## Classes
### Player
This represent the class of the player.
Each player has his own name, money, assets, etc.. (All detailed in the hpp and cpp files).  
In the begging of the game, the player has **1500$**, and standing on the **"GO"** Slot.  

### Card
If player lands on **"Chance" or "Community chest"** he draws a card
We have the Father class `supriseCard`, that all the cards inherits for it, so we can have a vector of cards no matter what is the card or what it's action.  
In that way we can allways add more cards as we want, as we've been told in the project.  

Here is the list of the cards we have in the game:
1. Advance to Go (Collect $200)
2. Bank pays you dividend of $50
3. Go back 3 spaces
4. Go directly to Jail – do not pass Go, do not collect $200
5. Make general repairs on all your property – For each house pay $25 – For each hotel $100
6. Pay poor tax of $15
7. Take a trip to Reading Railroad – If you pass Go collect $200
8. Take a walk on the Boardwalk – Advance token to Boardwalk
9. You have been elected Chairman of the Board – Pay each player $50
10. Your building loan matures – Collect $150
11. Get out of Jail Free – This card may be kept until needed

Each card work in it's own way according to what it's doing

### Slots
The slots assmeble the board:
We have the father class `Slots`
The rest of the slot or Slots of themselves, ot inherits from this class and work in there own special way.  
Every slot has its:
* name
* type
* The players that on the slot

Here is the list of the Slots:

1. ***Slot*** - Pay Taxes, Jail, In/Visit the jail, are all regular slots. They don't have any special thing on themselves, they causing for all kind of actions but not on themselves

2. ***Street*** - The street type, is most of the board.
Each street, has it name, color, price, rent, rent with house and hotel, cost to build a house or hotel, and its owner

3. ***Station*** - We have 4 Train Stations in the game, one on each side of the board. The price to buy one is the same, and the rent is depends according to how many station the player own.

4. ***Utility*** - We have 2 utilities: electic company, and water company.  
The price of them is the same, and the rent depends on how many utilities the playwer has, and the result of the dice roll.

5. ***GO*** - The statrt of the board, if player passes it, he gets 200$, and if he lands on it he get 400$

6. ***Free Parking*** - Any time a player needs to pay the bank the money goes there.  
If player lands on this slot, he misses the next turn, and if there is money there he takes it.

### Board
The board is assembled from the slots.  
It is a vector of slots, so we can always add more if we want to increase the board, or add new slots to our game.
In the regular case we have 40 slots, each slots is placed according to the regular monopoly board.  
We also have outside of the `Board` class **gui** fucntions, that if we want we can chage it and implement it everyone in it's own way, more details on the gui furthre in this file.  
For now we can say we've put it in the `Board.hpp` and `Board.cpp` files (outside of the class) for **faster compilation time**

### Monopoly - game logic

## Run the game
## Test
## Valgrind
## GUI