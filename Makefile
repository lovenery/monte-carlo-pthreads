CC=g++
CFLAGS=-O3 -Wall
LIBS=-pthread

all: pi.out
pi.out: a.o
	$(CC) $(CFLAGS) $(LIBS) -o pi a.o
a.o: pi.cpp
	$(CC) $(CFLAGS) -o a.o -c pi.cpp

.PHONY: clean
clean:
	rm -f *.o *.out pi
