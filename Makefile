CC = g++
#CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: walsh.o statistics.o prinel.o crypto.o regele.o

run-p1:
	./walsh

run-p2:
	./statistics

run-p3:
	./prinel

run-p4:
	./crypto

run-p5:
	./regele


walsh.o: walsh.cpp
	g++ walsh.cpp -o walsh

statistics.o: statistics.cpp
	g++ statistics.cpp -o statistics

prinel.o: prinel.cpp
	g++ prinel.cpp -o prinel

crypto.o: crypto.cpp
	g++ crypto.cpp -o crypto

regele.o: regele.cpp
	g++ regele.cpp -o regele

.PHONY: clean

clean:
	rm -rf *.o walsh statistics prinel crypto regele