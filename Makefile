CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o MethodInsertion.o
	$(CC) $(CFLAGS) test.o MethodInsertion.o -o test $(LDFLAGS) -DGCOV=1

MethodInsertion.o: src/MethodInsertion.c
	$(CC) $(CFLAGS) -o MethodInsertion.o -c src/MethodInsertion.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f test
