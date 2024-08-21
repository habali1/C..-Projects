#include "Song.h"
#include <iostream>
#include <string>

const int INITIAL_CAPACITY = 10;
Song** songs = new Song*[INITIAL_CAPACITY];
int songCount = 0;
int capacity = INITIAL_CAPACITY;

Song* findSongById(int songId) {
    for (int i = 0; i < songCount; ++i) {
        if (songs[i]->id == songId) {
            return songs[i];
        }
    }
    // if there is no song w given Id return null

    
    return nullptr; 
}
// for resizing if needed. 
void resizeIfNeeded() {
    if (songCount >= capacity) {
        int newCapacity = capacity * 2;
        Song** newSongs = new Song*[newCapacity];
        for (int i = 0; i < songCount; ++i) {
            newSongs[i] = songs[i];
        }
	//to delete the array.
        delete[] songs; 
        songs = newSongs;
        capacity = newCapacity;
    }
}


Song::Song(int id, const std::string& artist, int duration, const std::string& title) 
    : id(id), artist(artist), duration(duration), title(title) {}

//adding song

void Song::addSong(int id, const std::string& artist, int duration, const std::string& title) {
    for (int i = 0; i < songCount; ++i) {

      if (songs[i]->id == id) {

	std::cout << "song ID " << id << " already used" << std::endl;
	return;
        }
    }
    resizeIfNeeded();
    songs[songCount++] = new Song(id, artist, duration, title);
    std::cout << "new song " << id << " " << title << " by " << artist << " " << duration / 60 << ":" << (duration % 60 < 10 ? "0" : "") << duration % 60 << std::endl;
}
//removing song 

void Song::removeSong(int id) {
    int indexToRemove = -1;
    for (int i = 0; i < songCount; ++i) {
        if (songs[i]->id == id) {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove != -1) {
      // delete the song 
        delete songs[indexToRemove]; 
        for (int i = indexToRemove; i < songCount - 1; ++i) {
            songs[i] = songs[i + 1];
        }
        songCount--;
        std::cout << "deleting song " << id << std::endl;
    } else {
        std::cout << "song " << id << " not found" << std::endl;
    }
}

void Song::seeSong(int id) {
    for (int i = 0; i < songCount; ++i) {

      if (songs[i]->id == id) {
	
            std::cout << "song " << songs[i]->id << " " << songs[i]->title << " by " << songs[i]->artist << " " << songs[i]->duration / 60 << ":" << (songs[i]->duration % 60 < 10 ? "0" : "") << songs[i]->duration % 60 << std::endl;

	    return;
        }
    }
    std::cout << "song " << id << " does not exist" << std::endl;
}
