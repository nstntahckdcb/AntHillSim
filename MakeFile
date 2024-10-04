# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Executable name
TARGET = AntHillSim

# Source files
SRCS = main.cpp Ant.cpp AntHill.cpp LinkedList.cpp

# Object files (automatically generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the project
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# Rule to clean the project (remove object files and the executable)
clean:
	rm -f $(OBJS) $(TARGET)

# Automatically compile .o files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
