# Specifiy the target
all: listen

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
listen: Listen.o Song.o SongCollection.o
	g++ Listen.o Song.o SongCollection.o -o listen

# Specify how the object files should be created from source files
Listen.o: Listen.cpp Song.h SongCollection.h
	g++ -c Listen.cpp

Song.o: SongCollection.cpp SongCollection.h Song.h
	g++ -c SongCollection.cpp

SongCollection.o: SongCollection.cpp SongCollection.h Song.h
	g++ -c SongCollection.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o listen
