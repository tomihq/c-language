CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = 21-callbacks
VPATH = $(shell find . -type d | tr '\n' ':')

all: $(TARGET)

$(TARGET): $(TARGET).o
	     $(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	     $(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean
