#include <iostream>
#include "System.h"

System::System(): systemLibrary(), topHits(){}

bool System::addSong(string songTitle){
    Song* s = findSong(songTitle);
    if(s != nullptr) { 
        cout << "Duplicate song " << s->get_title() << endl;
        return false;
    }
    return systemLibrary.treeInsert(songTitle);
}

Song* System::findSong(string songTitle){
    return systemLibrary.treeSearch(songTitle);
}

bool System::increaseListens(Song* song, int count){
    int i = systemLibrary.treeSearchIndex(song->get_title());
    if(i == -1){
        cout << "Song not in heap or not found" << endl;
        return false;
    }
    //cout << "index found " << i << endl;
    topHits.increase_key(i, count);
    return true;
}

void System::insertTopHits(Song* song){
    if(song == nullptr){
        return;
    }
    topHits.insert(song);
}

Song* System::extractTop(){
    return topHits.extract_max();
}

size_t System::topHitsSize(){
    return (size_t)topHits.get_size();
}

Song* System::getRoot(){
    return systemLibrary.getRoot();
}

void System::showSystemLibrary(){
    //cout << "Showing library" << endl;
    Song* root = getRoot();
    systemLibrary.inOrderTraversal(root, true);
}

void System::showTopHits(){
    //cout << "Showing heap" << endl;
    topHits.print();
}

/* int main(){
    System system;
    system.addSong("Billie Jean");
    system.addSong("Beat it");
    system.addSong("Thriller");
    Song* song1 = system.findSong("Billie Jean");
    if(song1 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song1->get_title() << endl;}
    system.showSystemLibrary();
    song1->play(30);
    Song* song2 = system.findSong("Beat it");
    song2->play(10);
    Song* song3 = system.findSong("Thriller");
    song3->play(40);
    system.insertTopHits("Thriller");
    system.insertTopHits("Billie Jean");
    system.insertTopHits("Beat it"); 
    //system.insertTopHits("Dangerous"); 
    system.showTopHits();
    song1 = system.findSong("Thriller");
    if(song1 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song1->get_title() << endl;}
    song2 = system.findSong("Dangerous");
    if(song2 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song2->get_title() << endl;}   
    system.increaseListens("Beat it", 50);
    system.showTopHits();
    system.increaseListens("Billie Jean", 60);
    system.showTopHits();
    song1 = system.findSong("Beat it");
    if(song1 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song1->get_title() << endl;} 
    song2 = system.findSong("Billie Jean");
    if(song2 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song2->get_title() << endl;} 
    song3 = system.findSong("Thriller");
    if(song3 == nullptr){ cout << "Nullptr" << endl;}
    else{cout << "Song found: " << song3->get_title() << endl;}
      
} 
 */