#include "SongCollection.h"
#include <iostream>
using namespace std;

SongCollection::SongCollection() : numSongs(0), song(Song()){
}

SongCollection::SongCollection(const Song& song) : numSongs(1), song(song){
}

void SongCollection::show(){
  cout << "Number of songs in collection: " << numSongs << endl;
  if (numSongs > 0) {
    song.show();
  }
}
