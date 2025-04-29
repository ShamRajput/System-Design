
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Header files (not compiled directly)
HEADERS = Card.hpp DebitCard.hpp CreditCard.hpp PaymentMethod.hpp PaymentService.hpp

# Source files
SRCS = Card.cxx DebitCard.cxx CreditCard.cxx PaymentService.cxx main.cxx

# Object files (one for each source file)
OBJS = $(SRCS:.cxx=.o)

# Output executable
TARGET = main

# Default target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile each .cxx file into an object file
%.o: %.cxx $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f *.o $(TARGET)
