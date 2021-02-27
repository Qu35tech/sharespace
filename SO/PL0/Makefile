############################# Makefile ##########################
CFLAGS= -Wall -Wextra -pedantic -O2

all: vector
vector: vector.o main.o
		gcc -o vector vector.o main.o
vector.o: vector.c
		gcc -o vector.o -c vector.c
main.o: main.c vector.h
		gcc -o main.o -c main.c
clean:
		rm -rf *.o
mrproper: clean
		rm -rf vector