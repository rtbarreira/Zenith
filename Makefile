CC=gcc
SRC=main.c function.c
INCLUDE=.
BYNARY=main
LIBRARIES=-lm

all:
	@$(CC) -O $(BINARY) $(SRC) -I$(INCLUDE) $(LIBRARIES)

run:
	@./$(BINARY)
