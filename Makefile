CC = gcc
CFLAGS = -Wall -O3

default: build

build: main.o game.o
	$(CC) $(CFLAGS) -o dunquest main.o game.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm *.o dunquest

