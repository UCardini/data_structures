COMPILER = g++
FLAGS = -Wall -g

# objDirectory:
# binDirectory:
	# @mkdir -p bin
	# @mkdir -p obj
OBJ:=obj
BIN:=bin
# Source files
SRCS = $(wildcard src/*.cpp)
# Object files
OBJS = $(patsubst src/%.cpp, obj/%.o, $(SRCS))

TARGET = $(BIN)/main

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(COMPILER) $(FLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
$(OBJ)/%.o: src/%.cpp
	mkdir -p $(@D)
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	-rm -rf obj bin $(TARGET)

