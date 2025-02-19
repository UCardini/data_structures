# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Iinclude

# Directories
OBJ := obj
BIN := bin

# source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, $(OBJ)/%.o, $(SRCS))

#$(info SRCS = $(SRCS))
#$(info OBJS = $(OBJS))

# main function
TARGET = $(BIN)/main

all: $(TARGET) 
	./$(TARGET)

# rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# rule to compile .cpp files into .o files
$(OBJ)/%.o: src/%.cpp
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

find: $(TARGET)
	bear -- make all

clean:
	rm -rf $(OBJ) $(BIN) $(TARGET) 
