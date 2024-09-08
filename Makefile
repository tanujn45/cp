CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 
SRC = insertionSort.cpp
TARGET = insertionSort

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f ./$(TARGET)

.PHONY: all run clean
