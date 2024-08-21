#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
    int id;
    std::string artist;
    int duration; 
    std::string title;
    
    Song(int id, const std::string& artist, int duration, const std::string& title);
    static void addSong(int id, const std::string& artist, int duration, const std::string& title);
    static void removeSong(int id);
    static void seeSong(int id);
};
 Song* findSongById(int songId);
#endif 
