#ifndef PRIMARYUSER_H
#define PRIMARYUSER_H
#include <string>
#include "BST.h"
#include "Song.h"

using namespace std;

class PrimaryUser {
    public:
        PrimaryUser();
        string getPrimaryName();
        void setPrimaryName(string name);
        bool addSong(string song_title);
        Song* findSong(string song_title);
        bool removeSong(string song_title);
        void showLibrary();
        
    private:
        string userName;
        BST plibrary;
};

#endif