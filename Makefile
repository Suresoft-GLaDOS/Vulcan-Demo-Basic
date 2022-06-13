CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o MissedStatements.o
	$(CC) $(CFLAGS) test.o MissedStatements.o -o test $(LDFLAGS)

MissedStatements.o: src/MissedStatements.c
	$(CC) $(CFLAGS) -o MissedStatements.o -c src/MissedStatements.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
	rm -f test
