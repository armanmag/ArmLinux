CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
SRC := manual-append.cpp
TARGET := manual-append

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
