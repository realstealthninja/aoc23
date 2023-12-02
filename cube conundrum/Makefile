CFLAGS= -std=c++17 -O2 -Wall -Wextra

cube: main.cpp
	g++ $(CFLAGS) -o cube main.cpp 

all:
	make cube

.PHONY: test clean

test: cube
	make clean
	make all
	./cube

clean:
	rm -f cube
