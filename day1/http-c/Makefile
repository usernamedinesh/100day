
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Output binary name
TARGET = server

# Source files
SRC = main.c

# Default target
all: $(TARGET)

# How to build the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	rm -f $(TARGET)
