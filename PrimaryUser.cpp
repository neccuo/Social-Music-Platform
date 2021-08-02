#include <iostream>
#include "PrimaryUser.h"

using namespace std;

PrimaryUser::PrimaryUser(): userName("Primary"), plibrary(){}

string PrimaryUser::getPrimaryName(){
    return userName;
}

void PrimaryUser::setPrimaryName(string name){
    userName = name;
}

bool PrimaryUser::addSong(string song_title){
    //Before add call extractTop in the terminal
    return plibrary.treeInsert(song_title);
}

Song* PrimaryUser::findSong(string song_title){
    return plibrary.treeSearch(song_title);
}

bool PrimaryUser::removeSong(string song_title){
    return plibrary.treeRemove(song_title);
}

void PrimaryUser::showLibrary(){
    plibrary.inOrderTraversal(plibrary.getRoot(), false);

}


/*BST Lib
bool addSong(int k) {
    for (int i = 0; i == k; i++) {
        --> topHits.heapExtactMax()
        --> treeInsert(Song& - what extract_max returns)
    }
}
bool findSong(string song_title) {
    --> BST::treeSearch()
}
bool removeSong(string song_title) {
    -->BST::treeRemove(song_title)
    insert back to system?
}
*/

