CC:=gcc
CFLAGS:=
LDFLAGS:=

all: test

test: test.o ProductionCode.o
	$(CC) $(CFLAGS) test.o ProductionCode.o -o test $(LDFLAGS)

ProductionCode.o: src/ProductionCode.c
	$(CC) $(CFLAGS) -o ProductionCode.o -c src/ProductionCode.c

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.gcov
	rm -f *.gcda *.gcno
	rm -f *.o
#	rm -f test
