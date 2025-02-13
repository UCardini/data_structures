# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Iinclude

# Directories
OBJ := obj
BIN := bin

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(patsubst src/%.cpp, $(OBJ)/%.o, $(SRCS))

compile_commands.json:
	bear -- make all

# Debug prints
$(info SRCS = $(SRCS))
$(info OBJS = $(OBJS))

# Target executable
TARGET = $(BIN)/main

# Default rule to build and run the executable
all: $(TARGET)
	./$(TARGET)

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
$(OBJ)/%.o: src/%.cpp
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -rf $(OBJ) $(BIN) $(TARGET) compile_commands.json .cache
