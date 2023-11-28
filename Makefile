CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

all: simulacao

simulacao: main.o
	$(CC) $(CFLAGS) -o simulacao main.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f simulacao main.o
