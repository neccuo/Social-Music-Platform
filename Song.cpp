#include "Song.h"
#include <iostream>

Song::Song()
{
    song_title = "";
    count = 0;
    index = -1; // FOR HEAP INDEX
    is_in_list = false;
    is_hit = false; 
    left = nullptr;
    right = nullptr; 
}

Song::Song(std::string name)
{
    song_title = name;
    count = 0;
    index = -1;
    is_in_list = false;
    is_hit = false;
    left = nullptr;
    right = nullptr; 
}

Song::~Song(){
    //std::cout << "Song deconstructor" << std::endl;
/*     if(left != nullptr){
        delete left;
    }
    if(right != nullptr){
        delete right;
    }   */
}

std::ostream& operator<<(std::ostream& out, const Song& song)
{
    out << song.song_title;
    return out;
}

bool operator==(const Song& s1, const Song& s2)
{
    if(s1.song_title == s2.song_title) { return true; }
    return false;
}

/* UNCOMMENT IF NEEDED
Song& Song::operator=(const Song& other) // Approach with caution
{
    song_title = other.song_title;
    count = other.count;
    index = other.index;
    is_in_list = other.is_in_list;
    is_hit = other.is_hit;
    return *this;
}*/

void Song::play()
{
    if(is_in_list){return;}
    if(!is_hit){is_hit = true;}
    count++;
}

void Song::play(int num)
{
    if(is_in_list || num < 1){return;}
    if(!is_hit){is_hit = true;}
    count += num;
}

void Song::extracted() // Only used after recommendation!!!
{
    nullify_count();
    index = -1;
    is_hit = false;
    is_in_list = true;
}


int Song::get_count()
{
    return count;
}

void Song::set_count(int new_count){
    count = new_count;
}

void Song::nullify_count()
{
    count = 0;
}

int Song::get_index()
{
    return index;
}

void Song::set_index(int new_index)
{
    if(new_index < -1){return;}
    /*if(new_index == -1) // Only set -1 when extracting from the leaderboard.
    { 
        is_hit=false; 
        is_in_list=true; 
        nullify_count();
    }*/
    index = new_index;
}

std::string Song::get_title()
{
    return song_title;
}

void Song::set_title(const std::string& new_title){
    song_title = new_title;
}

bool Song::is_in_heap()
{
    return is_hit;
}

void Song::set_in_heap(bool value){
    is_hit = value;
}

bool Song::is_in_primary(){
    return is_in_list;
}

void Song::set_in_primary(bool value){
    is_in_list = value;
}