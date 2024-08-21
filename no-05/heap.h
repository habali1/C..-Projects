#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Song {
    bool isFavorite;

    Song(const std::string &title, int listenTime) : title(title), listenTime(listenTime), isFavorite(false) {}
};

// Karşılaştırıcı fonksiyon listenTime'a göre max-heap oluşturur
struct CompareListenTime {
    bool operator()(const Song* lhs, const Song* rhs) const {
        return lhs->listenTime < rhs->listenTime;
    }
};

class SongMap {
private:
    std::priority_queue<Song*, std::vector<Song*>, CompareListenTime> songs;

public:
    void addSong(Song* newSong);
    void favorite();
};

#endif // HEAP_H
