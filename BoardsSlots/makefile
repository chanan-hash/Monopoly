CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Source directories

.PHONY: all Clean

all: FreeParking.o Go.o Streets.o Slot.o Utility.o Station.o

%.o: %.cpp %.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o 