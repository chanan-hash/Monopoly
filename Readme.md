# Monopoly Game

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
This class is the **heart** of the project, manges all the game itself- rolling the dice, moving the players, buying streets, stations, utilities..., picking up cards, jail, buying houses, payingrent, checking if the game is finished and who is the winner, etc.  
The rationale on working on it, is to imagine the game and the moves, and according to that start building everything.   
The idea here that we have object that runs it all and using the board, slots and players, if we want we can create another gamelogic according to new rules that we want, and using the board slot and what we want.  
You can see all the details in the class itself.

## Prerequisites:
* Linux OS 
      (Tested on Ubuntu, might work on others)
* `⁠g++` compiler
```bash 
sudo apt-get update
sudo apt-get install build essential
```
* `⁠valgrind`
```bash
⁠sudo apt install valgrind)
```
* ⁠`For GUI: SFML`
```bash
sudo apt-get install libsfml-dev
```

## Installation:
First clone this repository
```bash
git clone https://github.com/chanan-hash/Monopoly.git
```
### Compiling:
```bash
make monopoly
```
### Running the game:
```bash
./monopoly
```
And then the game will start.

***IMPORTANT!***  
The gui causing a memory leak, somethig that is known, and not part of the code.  
To see that the code doesn't have a memory leak you can run `valgrind`on the test `valgrind ./test`  
or in the main don't press in the main-menu `5` to open the gui in `main.cpp` (Explaintion in the next head-line)

### The Game course: 
In the begining You'll be asked to enter number (between 2-8) of players, if the input isn't right, you'll be asked again till the input is correct:

1. **correct input:**
```txt
Welcome to Monopoly
Enter the number of players (between 2 and 8): 2
```
2. **Incorect input:**
```txt
Welcome to Monopoly
Enter the number of players (between 2 and 8): 1
Invalid input. Please enter a number between 2 and 8: -4
Invalid input. Please enter a number between 2 and 8: f
Invalid input. Please enter a number between 2 and 8: 3556
```
After this you will need to put the names of the players you can't use the same name twice, as before if you'll put name that is taken you'll be asked to put another name.  
example:
```txt
Enter the name of player 1: Alice
Enter the name of player 2: Bob
Enter the name of player 3: Bob
This name is already taken, please enter another name
Enter the name of player 3: Charlie
```
And now the game starts.  
In each turn the player hasseveral options what to do:
```txt
Player Alice turn
What is your move? Enter the corresponding number:
1. Roll dice
2. See your details
3. Buy a house
4. Buy a hotel
5. Print the board
6. End turn
7. For terminating and exit the game
```
You can't end turn without rolling the dice and move, and you can't of course roll the dice more than once.

```txt
6
You have to roll the dice before ending the turn

1
Player Alice rolled 2 and 5 for a total of 7
Player Alice landed on Chance
Player Alice picked a card: AdvancedToGo Advance to Go (Collect $200)

1
You have already rolled the dice, you can't roll again
```
Now for the rest try it by oyurself and enjoy :)

## GUI
As you see abvoe you have in option `5` in the player's turn to print the board, it will open a window that will show the board, you can scroll by the mouse to make it bigger or smaller, and use the keypad to move around it and see the whole board.
we can see on each slot, how standing there, and if there an owner of the asset also to see who owns it.
We're using the `SFML` library for building the gui

here is an example of how it looks:

![Board exapmle](BoardPrint.png)

## Test
Inside the **Test** folder we have the `test.cpp` file that uses `doctest.h` for all the test checkups
before the `main.cpp` was created we ran and checked each card and function in test format.
We have there 2 main *TEST_CASE*
1. Cards checkups, and each card in *SUBCASE*
2. The game logic, each function or situation that was written, was checked fisrt in the test cases before we lunched it to the main.  
For running the test file here's the command:
```bash
make test
```
Then it'll complie everything and run the tests.

## Valgrind
For memorycheck for the test and the game, you can run the command
```bash
make valgrind
```
and it will compile run the valgrind check
here is the output:
```txt
==60021== HEAP SUMMARY:
==60021==     in use at exit: 0 bytes in 0 blocks
==60021==   total heap usage: 5,004 allocs, 5,004 frees, 513,083 bytes allocated
==60021== 
==60021== All heap blocks were freed -- no leaks are possible
==60021== 
==60021== For lists of detected and suppressed errors, rerun with: -s
==60021== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./monopoly < valgrind_input.txt
==60067== Memcheck, a memory error detector
==60067== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==60067== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info


==56982== 
==56982== HEAP SUMMARY:
==56982==     in use at exit: 0 bytes in 0 blocks
==56982==   total heap usage: 185 allocs, 185 frees, 90,982 bytes allocated
==56982== 
==56982== All heap blocks were freed -- no leaks are possible
==56982== 
==56982== For lists of detected and suppressed errors, rerun with: -s
==56982== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
### Now go and play! have fun :)
