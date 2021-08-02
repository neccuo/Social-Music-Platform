#pragma once
#include <string>
#include "Heap.h"
#include "BST.h"

class System{
    private:
        BST systemLibrary;
        Heap topHits;
    public:
        System();
        bool addSong(string songTitle);
        Song* findSong(string songTitle);
        bool increaseListens(Song* song, int count);
        void insertTopHits(Song* song);
        Song* extractTop();
        size_t topHitsSize();
        void showSystemLibrary();
        void showTopHits();
        Song* getRoot();
        //void readSongsFromFile(string filename);
};