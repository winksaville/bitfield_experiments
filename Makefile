CC = clang
CFLAGS = -m64 -O3 -Wall -std=c11

all: test

test.o: test.c
	$(CC) -x c $(CFLAGS) -o test.o -c test.c
	objdump -d test.o > test.txt

test: test.o
	$(CC) $(CFLAGS) test.o -o test

clean:
	rm -f test test.o test.txt
