CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source directories

.PHONY: all Clean

all: supriseCard.o Loan.o GoToJail.o BankPays.o PayPlayer.o AdvancedToGo.o RepairPay.o TrainTrip.o AdvancedToBoardWalk.o PayTax.o GoBack.o

%.o: %.cpp %.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o 