# The compiler we're using
CC=g++

# Compiler flags
# -c: Compile source files without linking.
# -Wall: Enable most warning messages.
CFLAGS=-c -Wall

# The name of the executable to be created
TARGET=songmenu

# Object files that compile from the corresponding .cpp files
OBJS=songmenu.o

# The first rule is the one executed when no parameters are fed to the Makefile
all: $(TARGET)

# Rule for making the actual target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule for compiling .cpp to .o
songmenu.o: songmenu.cpp
	$(CC) $(CFLAGS) songmenu.cpp

# 'make clean' will remove intermediate & executable files
clean:
	rm -f $(OBJS) $(TARGET)
