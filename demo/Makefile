# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
DEMODIR = demo
ASSETDIR = $(DEMODIR)/assets

# SDL2 flags
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LDFLAGS := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf

# Source files for the main project & demo 
SRC = ../Soldiers.cpp ../SoldierFactory.cpp ../Infantry.cpp ../InfantryFactory.cpp ../Boatman.cpp ../BoatmanFactory.cpp ../ShieldBearer.cpp ../ShieldBearerFactory.cpp ../Memento.cpp ../CareTaker.cpp ../State.cpp Map.cpp
OBJ = $(SRC:.cpp=.o)

# Demo sources
DEMO_SRC = $(DEMODIR)/DemoMain.cpp $(DEMODIR)/Map.cpp
DEMO_OBJ = $(DEMO_SRC:.cpp=.o)

# Target executable names
TARGET = TestingMain
DEMO_TARGET = $(DEMODIR)/DemoMain

# Rules
all: $(TARGET)

# Rule to compile and link TestingMain
$(TARGET): $(OBJ) TestingMain.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile and link DemoMain
$(DEMO_TARGET): $(OBJ) $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL2_CFLAGS) $(SDL2_LDFLAGS)

# Compile DemoMain.o and Map.o
$(DEMODIR)/%.o: $(DEMODIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c $< -o $@

# Compile .o files for Soldiers-related classes
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean command
clean:
	rm -f $(OBJ) $(TARGET) $(DEMO_TARGET) $(DEMO_OBJ) *.o

# Run TestingMain
run: $(TARGET)
	./$(TARGET)

# Run DemoMain
demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

.PHONY: all clean run demo