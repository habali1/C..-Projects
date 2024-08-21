#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <string>

class Playlist {
private:
    static Playlist** playlists; 
    static int playlistCount; 
    static int capacity; 
    Song** songs; 
    int songCount;
    int songCapacity; 
    int id;
    std::string name;

   
    void resizeSongArray();

public:
    Playlist(int id, const std::string& name);
    ~Playlist();

   
    static void addPlaylist(int id, const std::string& name);
    static void deletePlaylist(int id);
    static void copyPlaylist(int sourceId, int newId, const std::string& newName);
    static void renamePlaylist(int id, const std::string& newName);
    static void seePlaylist(int id);

  
    void addSongToPlaylist(int songId);
    void dropSongFromPlaylist(int songId);

   
    static int findPlaylistIndexById(int id);
    static Playlist* findPlaylistById(int id);
};

#endif
