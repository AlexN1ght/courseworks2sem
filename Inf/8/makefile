CC = gcc
LD = gcc
CCFLAGS = -Wall -pedantic  -std=c99
LDFLAGS =

main.out: main.o lin-2-list-barrier.o
	$(LD) $(LDFLAGS) -o main.out main.o lin-2-list-barrier.o
main.o: main.c lin-2-list-barrier.h
	$(CC) $(CCFLAGS) -c main.c
lin-2-list-barrier.o: lin-2-list-barrier.c lin-2-list-barrier.h
	$(CC) $(CCFLAGS) -c lin-2-list-barrier.c
clean:
	rm *.o
