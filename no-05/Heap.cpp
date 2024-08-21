#include "heap.h"

void SongMap::addSong(Song* newSong) {
    songs.push(newSong);
}

void SongMap::favorite() {
    if (songs.empty()) {
        std::cout << "No song found to add to favorites" << std::endl;
        return;
    }

    Song* maxSong = songs.top();
    songs.pop();

    if (maxSong->isFavorite) {
        std::cout << "Song " << maxSong->title << " is already a favorite." << std::endl;
        songs.push(maxSong); // Yine max heap'e geri ekleyin
    } else {
        maxSong->isFavorite = true;
        std::cout << "Song " << maxSong->title << " added to favorites (Listened for " << maxSong->listenTime << " seconds)." << std::endl;
        songs.push(maxSong); // Şarkıyı tekrar heap'e ekleyin
    }
}