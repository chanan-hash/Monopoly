CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source directories
#SRC_DIRS = . Cards Slots BoardSlots
CARDS = Cards/AsupriseCard.o Cards/Loan.o Cards/GoToJail.o Cards/BankPays.o Cards/PayPlayer.o Cards/AdvancedToGo.o Cards/RepairPay.o Cards/TrainTrip.o Cards/AdvancedToBoardWalk.o Cards/PayTax.o Cards/GoBack.o
SLOTS = Slots/FreeParking.o Slots/Go.o Slots/Streets.o Slots/Slot.o Slots/Utility.o Slots/Station.o

# Find all .cpp files in the source directories
#SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Generate a list of object files
OBJS := $(SRCS:.cpp=.o)

# Test source and object
TSRC = test.cpp
TOBJ = $(TSRC:.cpp=.o)

# Main target
all: main

test:
	make -C Test

main: main.cpp $(CARDS) $(SLOTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Generic rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TOBJ) main test
	make -C Cards clean
	make -C BoardsSlots clean
	make -C Test clean

.PHONY: all clean test