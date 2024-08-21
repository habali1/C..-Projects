#include "SongMap.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

SongMap::SongMap() : root(nullptr), favoriteFlag(false) {}

void SongMap::rotateLeft(Song *node)
{
    Song *rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != nullptr)
        rightChild->left->parent = node;
    rightChild->parent = node->parent;
    if (node->parent == nullptr)
        root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;
    rightChild->left = node;
    node->parent = rightChild;
};

void SongMap::rotateRight(Song *node)
{
    Song *leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != nullptr)
        leftChild->right->parent = node;
    leftChild->parent = node->parent;
    if (node->parent == nullptr)
        root = leftChild;
    else if (node == node->parent->right)
        node->parent->right = leftChild;
    else
        node->parent->left = leftChild;
    leftChild->right = node;
    node->parent = leftChild;
};

void SongMap::insertFixup(Song *node)
{
    while (node != root && node->parent != nullptr && node->parent->color == true)
    {
        if (node->parent == node->parent->parent->left)
        {
            Song *uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == true)
            {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    rotateLeft(node);
                }
                if (node->parent != nullptr)
                {
                    node->parent->color = false;
                    if (node->parent->parent != nullptr)
                    {
                        node->parent->parent->color = true;
                        rotateRight(node->parent->parent);
                    }
                }
            }
        }
        else
        {
            Song *uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == true)
            {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rotateRight(node);
                }
                if (node->parent != nullptr)
                {
                    node->parent->color = false;
                    if (node->parent->parent != nullptr)
                    {
                        node->parent->parent->color = true;
                        rotateLeft(node->parent->parent);
                    }
                }
            }
        }
    }
    root->color = false;
}


Song *SongMap::minimumNode(Song *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
};

void SongMap::transplant(Song *u, Song *v)
{
    if (u->parent == nullptr)
      {
	root = v;
      }
        
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
};

void SongMap::deleteFixup(Song *x)
{
  if(x == nullptr){
    return;
      }
    while (x != root && x->color == false)
    {
        if (x == x->parent->left)
        {
            Song *w = x->parent->right;
            if (w->color == true)
            {
                w->color = false;
                x->parent->color = true;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == false && w->right->color == false)
            {
                w->color = true;
                x = x->parent;
            }
            else
            {
                if (w->right->color == false)
                {
                    w->left->color = false;
                    w->color = true;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->right->color = false;
                rotateLeft(x->parent);
                x = root;
            }
        }
        else
        {
            Song *w = x->parent->left;
            if (w->color == true)
            {
                w->color = false;
                x->parent->color = true;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == false && w->left->color == false)
            {
                w->color = true;
                x = x->parent;
            }
            else
            {
                if (w->left->color == false)
                {
                    w->right->color = false;
                    w->color = true;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = false;
                w->left->color = false;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = false;
};


void SongMap::addSong(int songId, std::string artist, int duration, std::string title)
{
    if (songId < 0)
    {
        std::cout << "Invalid song ID: " << songId << ". Song ID must be a positive integer." << std::endl;
        return;
    }
    
    if (duration <= 0)
    {
        std::cout << "Invalid duration: " << duration << ". Duration must be a positive integer." << std::endl;
        return;
    }
    
    Song *current = root;
    Song *newNode = nullptr; 
    while (current != nullptr)
    {
        if (title == current->title)
        {
            std::cout << "Song with title " << title << " already exists." << std::endl;
            delete newNode; 
            return;
        }
        else if (title < current->title)
            current = current->left;
        else
            current = current->right;
    }
    
    newNode = new Song(songId, title, artist, duration); 
    
    Song *parent = nullptr;
    current = root;

    
    while (current != nullptr)
    {
        parent = current;
        if (title < current->title)
            current = current->left;
        else if (title > current->title)
            current = current->right;
        else
        {
            std::cout << "This song already exists." << std::endl;
            delete newNode; 
            return;
        }
    }
    
    newNode->parent = parent;
    if (parent == nullptr)
        root = newNode;
    else if (title < parent->title)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    newNode->color = true;
    insertFixup(newNode);

    //smaller than .push back
    //otherwise do whatever is written
    if (vectorSortedById.size() < 1){
      
      newNode->vectorIndex = 1;
      vectorSortedById.push_back(newNode);

      }
    
    else {
      vectorSortedById.push_back(newNode);
      int i, j;
      Song* key;
      i = vectorSortedById.size() - 1;
      key = vectorSortedById[i];
        j = i - 1;
        while (j >= 0 && vectorSortedById.size()> key->id) {
            vectorSortedById[j + 1] = vectorSortedById[j];
	    vectorSortedById[j + 1]->vectorIndex = vectorSortedById[j]->vectorIndex;
            j = j - 1;
        }
        vectorSortedById[j + 1] = key;
        vectorSortedById[j + 1]->vectorIndex = key->vectorIndex;
    }

      
    std::stringstream durationStream;
    int minutes = duration / 60;
    int seconds = duration % 60;
    durationStream << minutes << ":" << setw(2) << setfill('0') << seconds;
    std::cout << "new song " << songId << " " << title << " by " << artist << " " << durationStream.str() << std::endl;
}





void SongMap::listen(std::string title, int seconds)
{
    Song *current = root;
    while (current != nullptr)
    {
        if (title == current->title)
        {
	  if (current->isFavorite == true)
            {
	       std::cout << "Song " << title << " is a favorite" << std::endl;
                return ;
            }
            current->listenTime += seconds;
            std::cout << "Listened to " << title << " for " << seconds << " seconds" << std::endl;
            return;
        }
        else if (title < current->title)
            current = current->left;
        else
            current = current->right;
    }
    std::cout << "Song " << title << " not found" << std::endl;
};

void SongMap::favoriteHelper(Song *node, Song **maxNode, int *maxListenTime)
{
    if (node == nullptr)
        return;
    if (node->listenTime > *maxListenTime && !node->isFavorite)
    {
        *maxNode = node;
        *maxListenTime = node->listenTime;
    }
    favoriteHelper(node->left, maxNode, maxListenTime);
    favoriteHelper(node->right, maxNode, maxListenTime);
}

void SongMap::favorite()
{
    Song *maxNode = nullptr;
    int maxListenTime = -1; 
    favoriteHelper(root, &maxNode, &maxListenTime);
    if (maxNode != nullptr)
    {
        if (maxNode->isFavorite)
        {
            std::cout << "Song " << maxNode->title << " is already a favorite." << std::endl;
            return;
        }
        maxNode->isFavorite = true;
        favoriteFlag = true;
        std::cout << "Song " << maxNode->title << " added to list of favorites (Listened for " << maxNode->listenTime << " seconds)" << std::endl;
    }
    else
        std::cout << "No song found to add to favorites" << std::endl;
}

void SongMap::remove(std::string title) {
    Song *current = root, *x, *y;
    while (current != nullptr) {
        if (title == current->title)
            break;
        else if (title < current->title)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr) {
        std::cout << "Song " << title << " not found" << std::endl;
        return;
    }

    if (current->isFavorite) {
        current->isFavorite = false;
        std::cout << "Removed " << title << " from your favorites" << std::endl;
        favoriteFlag = false;
        return;
    }

    y = current;
    bool yOriginalColor = y->color;
    if (current->left == nullptr) {
      //cout<< current->title << std::endl;
       x = current->right;
        transplant(current, current->right);
    } else if (current->right == nullptr) {
       x = current->left;
        transplant(current, current->left);
    } else {
        y = minimumNode(current->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent != current) {
            transplant(y, y->right);
            y->right = current->right;
            y->right->parent = y;
        }
        transplant(current, y);
        y->left = current->left;
        y->left->parent = y;
        y->color = current->color;
    }
    vectorSortedById[current->vectorIndex]->isRemoved = true;
    delete current;  // Assuming you handle memory deallocation if necessary

    if (yOriginalColor == false) {
        deleteFixup(x);
    }
    
    std::cout << "Removed " << title << " from your songs" << std::endl;
}


void SongMap::showListenTimeHelper(Song *node)
{
    std::vector<Song *> sortedNodes;

    inorderTraversal(node, sortedNodes);
    std::sort(sortedNodes.begin(), sortedNodes.end(), [](Song *a, Song *b) {
        return a->id < b->id;
    });
    for (Song *song : sortedNodes)
    {
        std::cout << song->id << " " << song->title << " has been listened to for " << song->listenTime << " seconds" << std::endl;
    }
}

void SongMap::inorderTraversal(Song *node, std::vector<Song *> &sortedNodes)
{
    if (node != nullptr)
    {
        inorderTraversal(node->left, sortedNodes);
        sortedNodes.push_back(node);
        inorderTraversal(node->right, sortedNodes);
    }
}

void SongMap::showListenTime()
{
  //showListenTimeHelper(root);
  
  for (int i = 0; i < vectorSortedById.size(); i++ ){
    if (vectorSortedById[i]->isRemoved == false){
      std::cout << vectorSortedById[i]->id << " " << vectorSortedById[i]->title << " has been listened to for " << vectorSortedById[i]->listenTime << " seconds" << std::endl;
    }
  }
    
};
