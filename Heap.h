#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include "Song.h"

class Heap
{
    public:
        Heap();
        void insert(Song*);
        Song* show(int);
        void swap(int, int);
        void heapify(int);
        Song* extract_max();
        void increase_key(int, int);
        int get_size();
        std::vector<Song*> recommend_hits(int);
        void print();
    private:
        //Song* parent(int);
        int parent(int);
        Song* right(int);
        Song* left(int);
        
        std::vector<Song*> arr;
        int size;


};

#endif