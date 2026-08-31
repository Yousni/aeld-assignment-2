CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -std=c99

# Default target
all: writer

# Build writer application
writer: writer.c
	$(CC) $(CFLAGS) -o writer writer.c

# Clean target - remove writer executable and all object files
clean:
	rm -f writer *.o

.PHONY: all clean
