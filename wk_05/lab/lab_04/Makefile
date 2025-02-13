# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Iinclude

OBJ := obj
BIN := bin

SRCS = $(wildcard src/*.cpp)

OBJS = $(patsubst src/%.cpp, $(OBJ)/%.o, $(SRCS))

compile_commands.json:
	bear -- make all

$(info SRCS = $(SRCS))
$(info OBJS = $(OBJS))

TARGET = $(BIN)/main

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ)/%.o: src/%.cpp
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Plz use <3
clean:
	rm -rf $(OBJ) $(BIN) $(TARGET) compile_commands.json .cache
