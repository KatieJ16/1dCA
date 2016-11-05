#
# CS 11: Makefile for C track, assignment 3.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

sorter: version1.o
	$(CC) version1.o -o version1

sorter.o: version1.c
	$(CC) $(CFLAGS) -c version1.c

test:
	./run_test

check:
	c_style_check version1.c

clean:
	rm -f version1 *.o

