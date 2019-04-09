# Makefile is a binary file
CFLAGS = -g3 -Wall -O0 -std=c99
CC = gcc

example_sds:example_sds.o sds.o zmalloc.o
	${CC} ${CFLAGS} -o example_sds example_sds.o sds.o zmalloc.o

example_sds.o: example_sds.c
	${CC} ${CFLAGS} -c example_sds.c

sds.o: sds.c
	${CC} ${CFLAGS} -c sds.c

zmalloc.o:zmalloc.c
	${CC} ${CFLAGS} -c zmalloc.c

clean:
	rm -f *.o example_sds
