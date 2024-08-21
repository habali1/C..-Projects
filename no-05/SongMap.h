#ifndef SOMGMAP_H
#define SOMGMAP_H

#include "Song.h"
#include <vector>
#include <queue>
using namespace std;

class SongMap
{
private:
    Song *root;

    bool favoriteFlag;

    void rotateLeft(Song *node);
    void rotateRight(Song *node);
    void insertFixup(Song *node);
    Song *minimumNode(Song *node);
    void transplant(Song *u, Song *v);
    void deleteFixup(Song *x);
    void favoriteHelper(Song *node, Song **maxNode, int *maxListenTime);
    void showListenTimeHelper(Song *node);
    void inorderTraversal(Song *node, std::vector<Song *> &sortedNodes);
    void PrintInorder(Song* node);

public:
    SongMap();
    void addSong(int songId, std::string artist, int duration, std::string title);
    void listen(std::string title, int seconds);
    void favorite();
    void remove(std::string title);
    void showListenTime();
    vector<Song*> vectorSortedById;
    void addSong(Song *newSong);
};

#endif
