CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

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