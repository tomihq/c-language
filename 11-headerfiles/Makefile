CC = gcc
CFLAGS = -Wall -Wextra -pedantic 
DEPFLAGS = -MMD -MP
TARGET = header-files

all: $(TARGET)

SRCS = worka.c workb.c main.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	rm *.o $(TARGET) *.d

.PHONY: all clean
