CFLAGS= -std=c++17 -O2 -Wall -Wextra

scratch: main.cpp
	g++ $(CFLAGS) -o scratch main.cpp 

all:
	make scratch

.PHONY: test clean

test: scratch
	make scratch
	./scratch

clean:
	rm -f scratch
