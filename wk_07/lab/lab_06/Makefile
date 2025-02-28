CXX = clang++
CXXFLAGS = -Wall -g -Iinclude

OBJ := obj
BIN := bin
SRC := src

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

TARGET = $(BIN)/main

# for clangd
clang:
	@if [ ! -f compile_commands.json ]; then \
		bear -- make clean all; \
	fi
	@make all

all: $(TARGET)
	@./$(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(OBJ)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(BIN) compile_commands.json .cache

rebuild: clean all

.PHONY: all clean rebuild clang
