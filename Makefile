CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

TARGET = $(BIN_DIR)/campusguard

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)/*

debug: $(TARGET)
	gdb ./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY: all run clean debug valgrind
