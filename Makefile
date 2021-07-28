CXX = g++

BIN = trailing_space_remover
OBJS = trailing_space_remover.cpp
CFLAGS = -std=c++11 -O3 -static -Wall

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(BIN)

clean:
	rm -f $(BIN)

