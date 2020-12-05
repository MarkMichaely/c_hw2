# -*- Makefile -*-

CC=gcc
CFLAGS= -Wall
FILES.h=myBank.h
FILES.o=myBank.o main.o
RM=-rm

all:	$(FILES.o)
	$(CC) $(CFLAGS) -o all $(FILES.o)


main.o: $(FILES.h) main.c
	$(CC) $(CFLAGS) -c main.c

myBank.o: $(FILES.h) myBank.c
	$(CC) $(CFLAGS) -c myBank.c

.PHONY : clean
clean:
	$(RM) $(FILES.o) all
