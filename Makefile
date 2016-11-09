#
# CS 11: Makefile for C track, assignment 4.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

version1: version1.o memcheck.o
	$(CC) version1.o memcheck.o -o version1

version2: version2.o memcheck.o
	$(CC) version2.o memcheck.o -o version2

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

version1.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c version1.c

version2.o: version2.c memcheck.h
	$(CC) $(CFLAGS) -c version2.c

test:
	./triangle_game < test_input | more

check:
	c_style_check version1.c

clean:
	rm -f *.o version1 version2



