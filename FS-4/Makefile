CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
SRC := redirect-cin.cpp
TARGET := redirect-cin

.PHONY: all clean
all: $(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -f $(TARGET)
