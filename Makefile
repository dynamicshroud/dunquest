# lol

CC = gcc
CFLAGS = -Wall -O3

default: build

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c
	
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

build: main.o game.o
	$(CC) $(CFLAGS) -o dunquest main.o game.o

clean:
	rm *.o dunquest

