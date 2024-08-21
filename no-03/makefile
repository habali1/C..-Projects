# Compiler settings - Can change to clang++ if preferred
CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++14

# Build target executable:
TARGET = SongCollection

# Object files
OBJS = Song.o Playlist.o main.o

# Rule for making the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule for making object files
Song.o: Song.cpp Song.h
	$(CC) $(CFLAGS) -c Song.cpp

Playlist.o: Playlist.cpp Playlist.h Song.h
	$(CC) $(CFLAGS) -c Playlist.cpp

main.o: main.cpp Song.h Playlist.h
	$(CC) $(CFLAGS) -c main.cpp

# Clean old builds
clean:
	rm -f $(TARGET) $(OBJS)
