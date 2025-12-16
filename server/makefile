export TEMP := $(USERPROFILE)\AppData\Local\Temp
export TMP  := $(USERPROFILE)\AppData\Local\Temp
CXX      := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O2
TARGET   := app
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
