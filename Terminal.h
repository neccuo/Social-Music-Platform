#ifndef TERMINAL_H
#define TERMINAL_H
#include "Song.h"
#include "System.h"
#include "Graph.h"
#include "Parser.h"
#include "PrimaryUser.h"
#include <fstream>
#include <string>
#include <sstream>

class Terminal
{
    public:
        Terminal();
        ~Terminal();
        void main_loop();

    private:
        System system;
        Graph graph;
        PrimaryUser primary;
        unsigned int radius;
        void take_command(std::string);
        void help();
        void add(std::string, std::string);
        //void play(std::string, std::string);
        void show(std::string, std::string);
        //void select_user(std::string);
        void befriend(std::string, std::string);
        void unfriend(std::string, std::string);
        void listen(std::string, std::string);
        void set_radius(std::string);
        void recommend(std::string);
        void remove_song(std::string, std::string);
        void fill_system();
        void fill_graph();

        void debug_realm(Song* song);

    
};


#endif