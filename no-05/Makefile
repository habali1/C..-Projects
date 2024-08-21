listen_up: main.o SongMap.o
	g++ main.o SongMap.o -o listen_up

main.o: main.cpp SongMap.h
	g++ -c main.cpp

SongMap.o: SongMap.cpp SongMap.h Song.h
	g++ -c SongMap.cpp

clean:
	rm -f *.o listen_up

