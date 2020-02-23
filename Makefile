CC=gcc
CFLAGS=-std=c99 -W -Wall -pedantic

all: main

main: $(FILE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) main *.o