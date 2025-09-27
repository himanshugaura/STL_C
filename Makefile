CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Istl/include 
SRC = $(wildcard stl/src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = stl_demo

$(TARGET): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) main.o $(TARGET)
