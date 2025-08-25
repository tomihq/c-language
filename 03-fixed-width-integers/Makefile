CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = fixed-width-integers

all: $(TARGET)

$(TARGET): fixed-width-integers.o
	     $(CC) $(CFLAGS) $^ -o $@

data-types.o: fixed-width-integers.c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean
