#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H

#include "Song.h"

class SongCollection {
public:
  SongCollection();
  SongCollection(const Song& song);
  void show();

 private:
  int numSongs;
  Song song;
};

#endif //SONGCOLLECTION_H
