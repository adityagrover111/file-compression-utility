CC = gcc
CFLAGS = -Wall -std=c99

all: compressor

compressor: main.o rle.o
	$(CC) $(CFLAGS) -o compressor main.o rle.o

main.o: main.c rle.h
	$(CC) $(CFLAGS) -c main.c

rle.o: rle.c rle.h
	$(CC) $(CFLAGS) -c rle.c

clean:
	rm -f *.o compressor
