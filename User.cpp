#include <stdio.h>
#include <iostream>
#include <string>
#include "User.h"
#include "Song.h"

using namespace std;

User::User(): userName(""), left(nullptr), right(nullptr) {}

User::User(string name): userName(name), left(nullptr), right(nullptr) {}

User::~User(){}

string User::getUserName(){
    return userName;
}
        
void User::setUserName(string name){
    userName = name;
}
/*
void listenSong(Song& song, int k){
    song.play(k);
}*/

ostream& operator<<(ostream& os, const User& user){
    os << user.userName;
    return os;
}

/*void listenSong(string listen_song) {
    systemLibrary.findSong(listen_song);
    increaseListens(listen_song, 1);
    topHits.heapInsert()
}
bool operator==(const User& u1, const User& u2) {
    if(u1.name == u2.name) {
        return true;
    }return false;
}
bool operator<() 
}
bool operator>=() 
}*/

