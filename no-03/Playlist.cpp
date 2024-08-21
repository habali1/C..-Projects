#include "Playlist.h"
#include "Song.h"
#include <iostream>
#include <cstring> 

Playlist** Playlist::playlists = nullptr;
int Playlist::playlistCount = 0;
int Playlist::capacity = 10; 

Playlist::Playlist(int id, const std::string& name) : id(id), name(name) {
    songs = new Song*[10]; // 10 songs is the cap
    songCount = 0;
    songCapacity = 10;

    if (playlists == nullptr) {
        playlists = new Playlist*[capacity];
    }
}


Playlist::~Playlist() {
    for (int i = 0; i < songCount; ++i) {
        delete songs[i]; 
    }
    delete[] songs; 
}

void Playlist::resizeSongArray() {
    if (songCount >= songCapacity) {
        int newCapacity = songCapacity * 2;
        Song** newSongs = new Song*[newCapacity];
        for (int i = 0; i < songCount; ++i) {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
        songCapacity = newCapacity;
    }
}
void Playlist::addPlaylist(int id, const std::string& name) {
    if (playlistCount >= capacity) {
       
        int newCapacity = capacity * 2;
        Playlist** newPlaylists = new Playlist*[newCapacity];
        for (int i = 0; i < playlistCount; ++i) {
            newPlaylists[i] = playlists[i];
        }
        delete[] playlists;
        playlists = newPlaylists;
        capacity = newCapacity;
    }

    for (int i = 0; i < playlistCount; ++i) {
        if (playlists[i]->id == id) {
            std::cout << "Playlist ID " << id << " already exists." << std::endl;
            return;
        }
    }

    playlists[playlistCount] = new Playlist(id, name);
    std::cout << "new playlist " << id << " called " << name << std::endl; 
    playlistCount++;
}
void Playlist::deletePlaylist(int id) {
    int index = findPlaylistIndexById(id);
    if (index == -1) {
        std::cout << "Playlist " << id << " not found." << std::endl;
        return;
    }
    delete playlists[index]; 
    for (int i = index; i < playlistCount - 1; ++i) {
        playlists[i] = playlists[i + 1];
    }
    playlistCount--; 
    std::cout << "Playlist " << id << " successfully deleted." << std::endl;
}
void Playlist::copyPlaylist(int sourceId, int newId, const std::string& newName) {
    int sourceIndex = findPlaylistIndexById(sourceId);
    if (sourceIndex == -1) {
        std::cout << "Source playlist " << sourceId << " does not exist." << std::endl;
        return;
    }

    if (findPlaylistIndexById(newId) != -1) {
        std::cout << "New playlist ID " << newId << " already exists." << std::endl;
        return;
    }

    if (playlistCount >= capacity) {
        int newCapacity = capacity * 2;
        Playlist** newPlaylists = new Playlist*[newCapacity];
        for (int i = 0; i < playlistCount; ++i) {
            newPlaylists[i] = playlists[i];
        }
        delete[] playlists;
        playlists = newPlaylists;
        capacity = newCapacity;
    }

    // Create new playlist
    Playlist* newPlaylist = new Playlist(newId, newName);

    // Copy songs from source
    Playlist* sourcePlaylist = playlists[sourceIndex];
    for (int i = 0; i < sourcePlaylist->songCount; ++i) {
        Song* songToCopy = sourcePlaylist->songs[i];
        newPlaylist->addSongToPlaylist(songToCopy->id); 
    }
    playlists[playlistCount++] = newPlaylist;
    std::cout << "Playlist " << sourceId << " copied to " << newName << " with ID " << newId << "." << std::endl;
}
void Playlist::renamePlaylist(int id, const std::string& newName) {
    int index = findPlaylistIndexById(id);
    if (index == -1) {
        std::cout << "Playlist " << id << " not found." << std::endl;
        return;
    }

    playlists[index]->name = newName;
    std::cout << "Playlist " << id << " name changed to " << newName << "." << std::endl;
}
void Playlist::seePlaylist(int id) {
    Playlist* playlist = findPlaylistById(id); 
    if (playlist == nullptr) {
        std::cout << "playlist " << id << " does not exist" << std::endl;
        return;
    }

    std::cout << "Songs in playlist " << playlist->id << " " << playlist->name << std::endl;

    for (int i = 0; i < playlist->songCount; ++i) {
        Song* song = playlist->songs[i];
        int minutes = song->duration / 60;
        int seconds = song->duration % 60;
        std::cout << "song " << song->id << " " << song->title << " by " << song->artist 
                  << " " << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }
}
void Playlist::addSongToPlaylist(int songId) {
    // playlsit check
    

    Song* songToAdd = findSongById(songId); 
    if (songToAdd == nullptr) {
        std::cout << "song " << songId << " does not exist" << std::endl;
        return;
    }

    // if already in list
    for (int i = 0; i < songCount; ++i) {
        if (songs[i]->id == songId) {
            std::cout << "song " << songId << " is already in playlist " << id << std::endl;
            return;
        }
    }

    // add song
    if (songCount >= songCapacity) {
      resizeSongArray(); //check if capacity
    }
    songs[songCount++] = songToAdd;
    std::cout << "song " << songId << " added to playlist " << id << std::endl;
}
void Playlist::dropSongFromPlaylist(int songId) {
    //in global == or !=
    Song* songToDrop = findSongById(songId); 
    if (songToDrop == nullptr) {
        std::cout << "song " << songId << " does not exist" << std::endl;
        return;
    }

    // remove the song that found
    bool found = false;
    for (int i = 0; i < songCount; ++i) {
        if (songs[i]->id == songId) {
            found = true;
            for (int j = i; j < songCount - 1; ++j) {
                songs[j] = songs[j + 1];
            }
            songCount--;
            break;
        }
    }

    if (!found) {
        std::cout << "song " << songId << " not in playlist " << id << std::endl;
        return;
    }

    std::cout << "song " << songId << " dropped from playlist " << id << std::endl;
}
int Playlist::findPlaylistIndexById(int id) {
    for (int i = 0; i < playlistCount; i++) {
        if (playlists[i]->id == id) {
            return i;
        }
    }
    return -1; // playlist not found
}


Playlist* Playlist::findPlaylistById(int id) {
    int index = findPlaylistIndexById(id);
    if (index != -1) {
        return playlists[index];
    }
    return nullptr; 
}
