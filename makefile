# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -O3

# # List of .o files
# SRCS = main.cpp Player.cpp Board.cpp Streets.cpp FreeParking.cpp TrainTrip.cpp \
#        Cards/PayTax.cpp Cards/RepairPay.cpp Cards/TrainTrip.cpp \
#        Slots/Slot.cpp Slots/Streets.cpp Slots/FreeParking.cpp 

# TSRCS = test.cpp 

# OBJS = $(SRCS:.cpp=.o)

# TOBJS = $(TSRCS:.cpp=.o)

# #all: main

# test: $(TSRCS) $(TOBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) $(TSRCS) -o test


# # Rule for compiling .cpp files to .o files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@


# clear:
# 	rm -f *.o main test


CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -O3

# Source directories
SRC_DIRS = . Cards Slots BoardSlots

# Find all .cpp files in the source directories
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Generate a list of object files
OBJS := $(SRCS:.cpp=.o)

# Test source and object
TSRC = test.cpp
TOBJ = $(TSRC:.cpp=.o)

# Main target
all: main

# Test target
test: $(OBJS) $(TOBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Main program
main: $(filter-out $(TOBJ),$(OBJS))
	$(CXX) $(CXXFLAGS) $^ -o $@

# Generic rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TOBJ) main test

.PHONY: all clean test