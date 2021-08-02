#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "BST.h"
#include "UBST.h"

using namespace std;

class Graph{
        UBST users;
        map<string, vector<string>> adjList;
    public:
        Graph();
        ~Graph();
        bool addNode(string userName);
        bool contains(string userName);
        bool addEdge(string src, string dest);
        bool removeEdge(string src, string dest);
        bool inRadius(string source, string userName, unsigned int radius);
        //void loadEdgesFromFile(string filename);
        void printAdjList();
        void printFriendsOf(string source);
        void showUsers();

};
