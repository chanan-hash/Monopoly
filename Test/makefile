CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Source directories
CARDS = ../Cards/supriseCard.o ../Cards/Loan.o ../Cards/GoToJail.o ../Cards/BankPays.o ../Cards/PayPlayer.o ../Cards/AdvancedToGo.o ../Cards/RepairPay.o ../Cards/TrainTrip.o ../Cards/AdvancedToBoardWalk.o ../Cards/PayTax.o ../Cards/GoBack.o
SLOTS = ../BoardsSlots/FreeParking.o ../BoardsSlots/Go.o ../BoardsSlots/Streets.o ../BoardsSlots/Slot.o ../BoardsSlots/Utility.o ../BoardsSlots/Station.o
PLAYR = ../Player.o
BOARD = ../Board.o

# Generate a list of object files

all: test

test: test.o $(CARDS) $(SLOTS)
#	make -C ../Cards
#	make -C ../BoardsSlots
	$(CXX) $(CXXFLAGS) $^ -o $@

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f test test.o *.o
	make -C ../Cards clean
	make -C ../BoardsSlots clean