CFLAGS= -std=c++17 -O2 -Wall -Wextra

gear: main.cpp
	g++ $(CFLAGS) -o gear main.cpp 

all:
	make gear

.PHONY: test gear

test: gear
	make gear
	make all
	./gear

clean:
	rm -f gear
