###
## Makefile skeleton
## INFO0030: Projet 2
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -Wextra -Wmissing-prototypes
LD=gcc

# Files
EXEC_TRI=main
MODULES_TRI=main.c analyseCombinatoire.c rechercheExhaustive.c simulation.c
OBJECTS_TRI=main.o analyseCombinatoire.o rechercheExhaustive.o simulation.o


EXEC_ALL=main

## Rules

############# TRI #############

main: $(OBJECTS_TRI)
	$(LD) -o $(EXEC_TRI) $(OBJECTS_TRI)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

analyseCombinatoire.o: analyseCombinatoire.c
	$(CC) -c analyseCombinatoire.c -o analyseCombinatoire.o $(CFLAGS)

rechercheExhaustive.o: rechercheExhaustive.c
	$(CC) -c rechercheExhaustive.c -o rechercheExhaustive.o $(CFLAGS)

simulation.o: simulation.c
	$(CC) -c simulation.c -o simulation.o $(CFLAGS)



clean:
	rm -f *.o $(EXEC_ALL) *~
