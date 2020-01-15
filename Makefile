CXX = clang++
CXXFLAGS = -Wall
DEBUG = -g
SRC = ./src
BIN = ./bin


all: BIN TMA3Question1 TMA3Question2 TMA3Question3

debug: BIN TMA3Question1_debug TMA3Question2_debug

BIN: 
	mkdir bin



TMA3Question1: $(SRC)/TMA3Question1.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BIN)/$@

TMA3Question2: $(SRC)/TMA3Question2.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BIN)/$@

TMA3Question3: $(SRC)/TMA3Question3.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BIN)/$@




TMA3Question1_debug: $(SRC)/TMA3Question1.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) $< -o $(BIN)/$@

TMA3Question2_debug: $(SRC)/TMA3Question2.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) $< -o $(BIN)/$@

TMA3Question3_debug: $(SRC)/TMA3Question3.cpp
	$(CXX) $(CXXFLAGS) $(DEBUG) $< -o $(BIN)/$@



clean:
	rm -rf $(BIN)