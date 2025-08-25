CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = data-types

all: $(TARGET)

$(TARGET): data-types.o
	     $(CC) $(CFLAGS) $^ -o $@

data-types.o: data-types.c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean
