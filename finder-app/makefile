# Default target
all: writer

# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra

# Source files
SRCS := writer.c

# Object files
OBJS := $(SRCS:.c=.o)

# Build the writer application
writer: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f writer $(OBJS)