CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o BranchChecker.o
	$(CC) $(CFLAGS) test.o BranchChecker.o -o test $(LDFLAGS)

BranchChecker.o: src/BranchChecker.c
	$(CC) $(CFLAGS) -o BranchChecker.o -c src/BranchChecker.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f test
