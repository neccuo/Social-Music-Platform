#include "Terminal.h"
#include <sstream>

Terminal::Terminal(): system(), graph(), primary(), radius(1)
{
    fill_system();
    fill_graph();
}

Terminal::~Terminal() {}

void Terminal::take_command(std::string command)
{
    Parser parse(command);
    std::string operation = parse.getOperation();
    std::string arg1 = parse.getArg1();
    std::string arg2 = parse.getArg2();

    if(operation == "help")     { help(); }
    //if(operation == "play")     { play(arg1, arg2); }
    else if(operation == "show")     { show(arg1, arg2); }
    //if(operation == "select")   { select_user(arg1); }
    else if(operation == "befriend") { befriend(arg1, arg2); }
    else if(operation == "unfriend") { unfriend(arg1, arg2); }
    else if(operation == "radius")   { set_radius(arg1);}
    else if(operation == "add")      { add(arg1, arg2);}
    else if(operation == "listen")   { listen(arg1, arg2);}
    else if(operation == "recommend") { recommend(arg1); }
    else if(operation == "remove")   {remove_song(arg1, arg2);}
    else if(operation == "exit" || operation == "e") {}
    else{ cout << "INVALID COMMAND" << endl; }

}

void Terminal::help()
{
    std::cout << "mjmj" << std::endl;
}

void Terminal::add(std::string arg1, std::string arg2)
{
    if(arg1.compare("song") == 0 && !arg2.empty()){
        system.addSong(arg2);
    }
    else if(arg1.compare("user") == 0 && !arg2.empty()){
        graph.addNode(arg2);
    }
    else{
        std::cout << "Invalid use of add " << std::endl;
        return;
    }
}

/* void Terminal::play(std::string arg1, std::string arg2) // Radyasyon
{
    void* song = system.findSong(arg2);
    if(song)
    {
        size_t num = std::stoi(arg1);
        if( !((Song*) song)->is_in_heap() )
        {
            system.insertTopHits(arg2);
        }
        ((Song*) song)->play(num);
        system.increaseListens(arg2, ((Song*) song)->get_count());
        return;
    }
    else
    {
        std::cout << "Song not found..." << std::endl;
    }
    return;
} */


void Terminal::listen(std::string arg1, std::string arg2){
    //listen userName(arg1) <n> <song title>
    int n = 0;
    std::string song_title = ""; 
    std::stringstream ss(arg2);
    if (ss >> n) {
        getline(ss, song_title);
    }
    song_title.erase(0, song_title.find_first_not_of(WHITESPACE));
    //std::cout << song_title << " " << n << std::endl;
    std::string pName = primary.getPrimaryName();
    cout << "LISTEN: " << arg1 << " listens " << song_title << " " << n << " times..." << endl;
    //if((arg1.compare(pName) != 0) && (graph.inRadius(pName, arg1, radius))){
    if(arg1.compare(pName) != 0){
        if(graph.inRadius(pName, arg1, radius)){
            Song* song = system.findSong(song_title);
            if(song != nullptr){
                if(song->is_in_heap()){
                    song->play(n);
                    system.increaseListens(song, song->get_count()); // DON'T TOUCH
                    return;
                }
                else{
                    
                    if(!(song->is_in_primary())){
                        song->play(n);
                        song->set_in_heap(true);
                        system.insertTopHits(song);
                        return;
                    }
                    else
                    {
                        cout << song->get_title() << " IS ALREADY IN THE PRIMARY USER'S LIST, WE DON'T CARE!!!!!" << endl;
                        return;
                    }
                }  
            }
            else
            {
                //std::cout << "Couldn't find the song" << std::endl;
                return;
            }
        }
        else
        {
            cout << arg1 << " IS NOT IN THE RADIUS, WE DON'T CARE WHAT THEY ARE LISTENING!!!" << endl;
        }
    }
    //else{ We don't care other users listening to a song}
}

void Terminal::recommend(std::string arg1){
    cout << "RECOMMEND: " << arg1 << " songs..." << endl;
    size_t n = stoi(arg1);
    if(n < 1 || n > system.topHitsSize()){
        std::cout << "Cannot recommend " << n << " songs" << std::endl;
        return;
    } 
    for(size_t i = 0; i < n; i++){
        Song* e = system.extractTop();
        e->set_in_heap(false);
        if(e != nullptr){
            //Check if it's in primary's library already?
            Song* f = primary.findSong(e->get_title());
            if(f == nullptr){
                primary.addSong(e->get_title());
                e->set_in_primary(true);
                std::cout << "Recommended: " << e->get_title() << std::endl;
            }
            else{
                std::cout << "Song is already in primary user's library" << endl;
            }        
        }
        else{
            std::cout << "Couldn't recommend" << std::endl;
            return; 
        }      
    }
}

void Terminal::remove_song(std::string arg1, std::string arg2){
    if(arg1.compare("song") == 0 && !arg2.empty()){
        std::cout << "REMOVE SONG: " << arg2 << std:: endl;
        //void* song = primary.findSong(arg2);
        Song* song = primary.findSong(arg2);
        if(song != nullptr){
            if(primary.removeSong((song)->get_title())){
                //song->set_in_primary(false);
                Song* sys = system.findSong(arg2);
                if(sys){sys->set_in_primary(false);}
                std::cout << "Removed song: " << arg2 << std:: endl;
                return;
            }
            else
            {
                std::cout << "SOMETHING BAD HAPPENED..." << std::endl;
            }
        }
        else{
            std::cout << "Couldn't find song " << arg2 << std::endl;
            return;
        }
    }
    else{
        std::cout << "Invalid use of remove song" << std::endl;
        return;
    }
}

void Terminal::show(std::string arg1, std::string arg2)
{
    if(arg1 == "system" || arg1 == "sys")
    {
        std::cout << "Showing System" << std::endl;
        system.showSystemLibrary();
        return;
    }
    else if(arg1 == "library" || arg1 == "primary")
    {
        std::cout << "Showing Library" << std::endl;
        primary.showLibrary();
        return;
    }
    else if(arg1 == "hits" || arg1 == "heap")
    {
        std::cout << "Showing Heap" << std::endl;
        system.showTopHits();
        return;
    }
    else if(arg1 == "user" && arg2 != "")
    {
        std::cout << "Showing Friends of " << arg2 << std::endl;
        graph.printFriendsOf(arg2);
        return;
    }
    else if(arg1 == "users") 
    {
        //graph.printAdjList();
        std::cout << "Showing all users..." << std::endl;
        graph.showUsers();
        return;
    }
    else if(arg1 == "graph"){
        std::cout << "Showing adjacency list of graph " << std::endl;
        graph.printAdjList();
        return;
    }
    std::cout << "invalid command..." << std::endl;
    return;
}

/* void Terminal::select_user(std::string arg1)
{
    // if( findUser(arg1) )
} */

void Terminal::befriend(std::string arg1, std::string arg2)
{
    std::cout << "BEFRIEND: " << arg1 << " and " << arg2 << "..." << endl;

    if(graph.addEdge(arg1, arg2)){ 
        std::cout << arg1 << " and " << arg2 << " are friends now" << endl;
        return; 
    }
    else{ return; } //std::cout << "There is something wrong..." << std::endl; 
}

void Terminal::unfriend(std::string arg1, std::string arg2)
{
    std::cout << "UNFRIEND: " << arg1 << " and " << arg2 << "..." << endl;
    if(graph.removeEdge(arg1, arg2)){
        std::cout << arg1 << " and " << arg2 << " are NOT friends now" << endl;
    }
    else
    {
        std::cout << "Cannot unfriend "<< arg1 << " and " << arg2 << std::endl;
        return; 
    }
}

void Terminal::set_radius(std::string arg1)
{
    std::cout << "RADIUS: " << radius << " to " << arg1 << "..." << endl;
    unsigned int r = (unsigned int) std::stoi(arg1);
    radius = r;
    std::cout << "Set the radius " << r << std::endl;
}

void Terminal::main_loop()
{
    std::string cmd = "";
    help();
    while(cmd != "e" && cmd != "exit")
    {
        std::cout << ">> ";
        getline(std::cin, cmd);
        take_command(cmd);
    }
}

void Terminal::fill_system()
{
    std::ifstream infile("songs.txt");
    std::string line;
    while(std::getline(infile, line))
    {
        system.addSong(line);
    }
    infile.close();
}

void Terminal::fill_graph()
{
    std::ifstream infile("users.txt");
    std::string line;
    graph.addNode(primary.getPrimaryName());
    while(std::getline(infile, line))
    {
        graph.addNode(line);
    }
    infile.close();
}

void Terminal::debug_realm(Song* song)
{
    cout << "DEBUG REALM....................................................................." << endl;
    cout << "title: " << song->get_title() << endl;
    cout << "count: " << song->get_count() << endl;
    cout << "index: " << song->get_index() << endl;
    cout << "is_in_heap? : " << song->is_in_heap() << endl;
    cout << "is_in_primary? : " << song->is_in_primary() << endl;
}

int main()
{
    Terminal term;
    term.main_loop();
}