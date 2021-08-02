#ifndef SONG_H
#define SONG_H
#include <string>

class Song
{
    public:
        Song();
        Song(std::string);
        ~Song();
        friend std::ostream& operator<<(std::ostream&, const Song&);
        friend bool operator==(const Song&, const Song&);
        // Song& operator=(const Song&); // Only for emergency
        void play();
        void play(int);
        void extracted();
        int get_count();
        void set_count(int new_count);
        void nullify_count();
        // Heap realm
        int get_index();
        void set_index(int);
        std::string get_title();
        void set_title(const std::string& new_title);
        bool is_in_heap();
        bool is_in_primary();
        void set_in_primary(bool value);
        void set_in_heap(bool value);

        Song* left;
        Song* right;

    private:
        std::string song_title;
        int count;
        int index;
        bool is_in_list;
        bool is_hit;
};

#endif