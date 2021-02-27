############################# Makefile ##########################
CFLAGS= -Wall -Wextra -pedantic -O2

all: readln
readln: readln.o myreadln.o
		gcc -o readln readln.o myreadln.o
readln.o: readln.c
		gcc -o readln.o -c readln.c
myreadln.o: myreadln.c readln.h
		gcc -o myreadln.o -c myreadln.c
clean:
		rm -rf *.o
mrproper: clean
		rm -rf readln