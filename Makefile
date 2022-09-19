CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o 3Dimension.o
	$(CC) $(CFLAGS) test.o 3Dimension.o -o test $(LDFLAGS) -DGCOV=1

3Dimension.o: src/3Dimension.c
	$(CC) $(CFLAGS) -o 3Dimension.o -c src/3Dimension.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f test
