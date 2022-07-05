CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o BranchChecker_avl.o BranchChecker_rb.o
	$(CC) $(CFLAGS) test.o BranchChecker_avl.o BranchChecker_rb.o -o test $(LDFLAGS)

BranchChecker_avl.o: src/BranchChecker_avl.c
	$(CC) $(CFLAGS) -o BranchChecker_avl.o -c src/BranchChecker_avl.c

BranchChecker_rb.o: src/BranchChecker_rb.c
	$(CC) $(CFLAGS) -o BranchChecker_rb.o -c src/BranchChecker_rb.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f test
