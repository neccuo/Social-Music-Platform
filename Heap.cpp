#include "Heap.h"
#include "Song.h"
#include <iostream>

Heap::Heap()
{
    size = 0;
}

void Heap::insert(Song* song)
{
    song->set_index(size);
    song->set_in_heap(true);
    arr.push_back(song);
    increase_key(song->get_index(), song->get_count());
    size++;
}

Song* Heap::show(int index)
{
    return arr[index];
}

//Song* Heap::parent(int index)
int Heap::parent(int index)
{
    // if(index >= size || 0 > index ){ return nullptr; }
    //if(index == 0){ return arr[0]; }
    //return arr[(index-1)/2];
    if(index == 0){ return 0;}
    return (index-1)/2;
}

Song* Heap::right(int index)
{
    return arr[(2*index)+1];
}
Song* Heap::left(int index)
{
    return arr[(2*index)+2];
}

void Heap::swap(int i, int j)
{
    int i_index = arr[i]->get_index();
    int j_index = arr[j]->get_index();
    void* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = (Song*) temp;
    arr[i]->set_index(i_index);
    arr[j]->set_index(j_index);
}

void Heap::heapify(int index)
{
    int largest = index;
    int l = (2*index)+1;
    int r = (2*index)+2;

    if(l < size && arr[l]->get_count() > arr[largest]->get_count()){largest = l;}
    if(r < size && arr[r]->get_count() > arr[largest]->get_count()){largest = r;}
    if(largest != index)
    {
        swap(index, largest);
        heapify(largest);
    }
}

Song* Heap::extract_max() // Might cause problems if size < 1
{// not 100% sure
    void *temp = arr[0];
    ((Song*) temp)->extracted();
    size--;
    arr[0] = arr[size];
    arr[0]->set_index(0);
    arr.erase(arr.begin()+size);
    heapify(0);
    return (Song*) temp;
}

/* <<ONLY USE AFTER PLAYING A SONG!!!>> */
void Heap::increase_key(int index, int key) // increase_key(song->get_index(), song->get_count())
{
    if(key < arr[index]->get_count()){std::cout << "New key is smaller than current key" << std::endl;}
    arr[index]->set_count(key);
    while(index > 0 && arr[parent(index)]->get_count() < arr[index]->get_count())
    {
        swap(index, parent(index));
        index = parent(index);
    }
}

int Heap::get_size()
{
    return size;
}

std::vector<Song*> Heap::recommend_hits(int rcm_count)
{
    std::vector<Song*> hits;
    if(rcm_count > size || 1 > rcm_count ){ return hits; }
    
    for(int i = 0; i < rcm_count; i++)
    {
        hits.push_back(extract_max());
    }
    return hits;
}

void Heap::print(){
    std::cout << "--- Size of the heap: " << arr.size() << " ---" << std::endl;
    for( size_t i = 0; i < arr.size(); i++){
        std::cout << arr[i]->get_title() << " count: " << arr[i]->get_count() <<  " index: " << arr[i]->get_index() << std::endl;
    }
}

/* int main()
{
    #define SONG_LIMIT 10

    Song s1("Bad");
    Song s2("Billie Jean");
    Song s3("Thriller");
    Song s4("Beat it");
    Song s5("DSTYGE");
    Song s6("s6");
    Song s7("s7");
    Song s8("s8");
    Song s9("s9");
    Song s10("s10");
    
    Song* song_arr[SONG_LIMIT] = {&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8,&s9,&s10};
    int play_arr[SONG_LIMIT] = {16,4,10,14,7,9,3,2,8,1};

    Heap heap;
    for(int i = 0; i < SONG_LIMIT; i++)
    {
        heap.insert(song_arr[i]);
    }
    for(int i = 0; i < SONG_LIMIT; i++)
    {
        song_arr[i]->play(play_arr[i]);
        heap.increase_key(song_arr[i]->get_index(), song_arr[i]->get_count());
    }

    for(int i = 0; heap.get_size() > i; i++)
    {
        std::cout << "index " << i << " -> " << *(heap.show(i));
        std::cout << " count: " << (*(heap.show(i))).get_count()  << std::endl;
        std::cout << "index in song: " << (*(heap.show(i))).get_index() << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    //heap.extract_max();
    heap.recommend_hits(3);

    Song s11("s11");
    for(int i = 0; heap.get_size() > i; i++)
    {
        heap.heapify(i);
    }

    for(int i = 0; heap.get_size() > i; i++)
    {
        std::cout << "index " << i << " -> " << *(heap.show(i));
        std::cout << " count: " << (*(heap.show(i))).get_count() << std::endl;
        std::cout << "index in song: " << (*(heap.show(i))).get_index() << std::endl;
    } 

} */