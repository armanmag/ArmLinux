CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
SRC := do-command.cpp
TARGET := do-command

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
