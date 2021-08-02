#ifndef USER_H
#define USER_H
#include <string>
#include "Song.h"

using namespace std;

class User {
    private:
        string userName;
    public:
        User();
        User(string);
        ~User();
        string getUserName() ;
        void setUserName(string name);
        //void listenSong(Song& song, int k);
        //bool operator==(const User& u1, const User& u2);
        friend ostream& operator<<(ostream& os, const User& user);
        User* left;
        User* right;
};

#endif