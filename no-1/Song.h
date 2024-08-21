#include <iostream>
#include <stdlib.h>
using namespace std;
#ifndef SONG_H
#define SONG_H
#include <string>

class Song {
public:
  Song();
  Song(string title, unsigned int year, string artist_p);
  void show();
private:
    string songTitle;
    unsigned int releaseYear;
    string artist;
    
};

#endif //songh
