# Compiler and flags
CXX       := g++
CXXFLAGS  := -std=c++20 -g

# Source files
SOURCES   := main.cpp bitboards.cpp
# Object files (same names as sources but with .o extension)
OBJECTS   := $(SOURCES:.cpp=.o)

# Target executable name
TARGET    := chess

# Default make target
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)
