export TEMP := $(USERPROFILE)\AppData\Local\Temp
export TMP  := $(USERPROFILE)\AppData\Local\Temp

CXX      := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O2 -I.. -MMD -MP
LDLIBS   := -lws2_32

TARGET   := server.exe

LOCAL_SRC := $(wildcard *.cpp)
LOCAL_OBJ := $(LOCAL_SRC:.cpp=.o)

SHARED_SRC := ../utils.cpp
SHARED_OBJ := utils_shared.o

OBJ := $(LOCAL_OBJ) $(SHARED_OBJ)
DEP := $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SHARED_OBJ): $(SHARED_SRC) ../utils.hpp
	$(CXX) $(CXXFLAGS) -c $(SHARED_SRC) -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)

.PHONY: all clean
