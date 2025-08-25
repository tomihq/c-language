CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = fixed-width-integers

all: $(TARGET)

$(TARGET): $(TARGET).o
	     $(CC) $(CFLAGS) $^ -o $@

fixed-width-integers.o: $(TARGET).c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean
