# Monoply Game

This project is a simple version of the famous game Monopoly

the rulse you can find in this repository:
[https://github.com/BenjaminSaldman/CPP_final_project_summer/tree/main](URL)

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

### Slots
### Board

### Monopoly - game logic

## Run the game
## Test
## Valgrind
## GUI