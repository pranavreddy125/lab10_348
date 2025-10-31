CC = g++
CFLAGS = -c -Wall -std=c++11

OBJECTS = main.o valid.o add.o

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

valid.o: valid.cpp
	$(CC) $(CFLAGS) valid.cpp

add.o: add.cpp
	$(CC) $(CFLAGS) add.cpp

clean:
	rm -rf *.o prog