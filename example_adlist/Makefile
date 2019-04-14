# Makefile is a binary file
CFLAGS = -g3 -Wall -O0 -std=c99
CC = gcc

example_adlist:example_adlist.o adlist.o zmalloc.o
	${CC} ${CFLAGS} -o example_adlist example_adlist.o adlist.o zmalloc.o

example_adlist.o: example_adlist.c
	${CC} ${CFLAGS} -c example_adlist.c

adlist.o: adlist.c
	${CC} ${CFLAGS} -c adlist.c

zmalloc.o:zmalloc.c
	${CC} ${CFLAGS} -c zmalloc.c

clean:
	rm -f *.o example_adlist
