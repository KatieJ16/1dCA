#
# CS 11: Makefile for C track, assignment 5.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

all: 1dCA_array_version 1dCA_pointer_version

1dCA_array_version: 1dCA_array_version.o memcheck.o
	$(CC) 1dCA_array_version.o memcheck.o -o 1dCA_array_version

1dCA_pointer_version: 1dCA_pointer_version.o memcheck.o
	$(CC) 1dCA_pointer_version.o memcheck.o -o 1dCA_pointer_version

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

1dCA_array_version.o: 1dCA_array_version.c memcheck.h
	$(CC) $(CFLAGS) -c 1dCA_array_version.c

1dCA_pointer_version.o: 1dCA_pointer_version.c memcheck.h
	$(CC) $(CFLAGS) -c 1dCA_pointer_version.c

check:
	c_style_check 1dCA_array_version.c 1dCA_pointer_version.c

clean:
	rm -f *.o 1dCA_array_version 1dCA_pointer_version



