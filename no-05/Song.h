#ifndef SONG_H
# define SONG_H

#include <iostream>
#include <string>
#include <map>

class Song
{
public:
    int id;
    std::string title;
    int duration;
    std::string artist;
    int listenTime;
    bool isFavorite;
    Song *left;
    Song *right;
    Song *parent;
    bool color; // true = red, false = black
    int vectorIndex;
    bool isRemoved;

    Song(const std::string &title, int listenTime);
  
    Song(int _id, std::string _title, std::string _artist, int _duration)
        : id(_id), title(_title), artist(_artist), duration(_duration), listenTime(0), isFavorite(false), left(nullptr), right(nullptr), parent(nullptr), color(true) {}
};

#endif
