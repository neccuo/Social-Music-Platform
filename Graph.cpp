#include <iostream>
#include <queue>
#include "Graph.h"

using namespace std;

Graph::Graph(): adjList() {}

Graph::~Graph() {}

bool Graph::contains(string userName){
    User* u = users.treeSearch(userName);
    if(u == nullptr) return false;
    return true;
}

bool Graph::addNode(string userName){
    if(userName.empty() || contains(userName)){
        cout << "Duplicate User " << userName << endl;
        return false;
    }  
    vector<string> v;
    users.treeInsert(userName);
    adjList[userName] = v;
    return true;
}

bool Graph::addEdge(string src, string dest){
    if(!(contains(src))){
        cout << src << " is not in the UBST..." << endl;
        return false;
    }
    if(!(contains(dest))){
        cout << dest << " is not in the UBST..." << endl;
        return false;
    }
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
    return true;
}

bool Graph::removeEdge(string src, string dest){
    if(!(contains(src) && contains(dest))){
        cout << src << " or " << dest << " are not in the UBST..." << endl;
        return false;
    }
    int i = 0;
    bool retVal = false;
    for(map<string, vector<string>>::iterator it = adjList.begin(); it != adjList.end(); ++it){
        if(it->first == src){
            for(size_t i = 0; i < adjList[src].size(); i++){
                if(adjList[src][i] == dest){
                    retVal = true;
                    adjList[src].erase(adjList[src].begin() + i);
                    break;
                }
            }
        }
        if(it->first == dest){
            for(size_t i = 0; i < adjList[dest].size(); i++){
                if(adjList[dest][i] == src){
                    retVal = true;
                    adjList[dest].erase(adjList[dest].begin() + i);
                    break;
                }
            }
        }
        ++i;      
    }
    return retVal;
}

bool Graph::inRadius(string source, string userName, unsigned int radius){
    queue<string> Q;
    map<string, bool> visited;
    Q.push(source);
    visited[source] = true;
    unsigned int step = 0;
    while(!Q.empty()){
        if(step > radius){
            break;
        }
        step++;
        int size = Q.size();
        for(int i = 0; i < size; i++){
            string curr = Q.front();
            //cout << curr << endl;
            if(curr == userName){
                return true;
            }
            for(string neighbor: adjList[curr]){
                if(!visited[neighbor]){
                    Q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            Q.pop();
            
        }
    }
    return false;
}

void Graph::printAdjList(){
    cout << "Adjacency List" << endl;
    for(map<string, vector<string>>::iterator it = adjList.begin(); it != adjList.end(); ++it){
        cout << it->first << ": ";
        for(string s: it->second) cout << s << " ";
        cout << endl;
    }

}

void Graph::showUsers(){
    cout << "All Users" << endl;
    users.inOrderTraversal(users.getRoot());
}


void Graph::printFriendsOf(string src){
    if(!contains(src)){
        cout << "No such node " << src << endl;
        return; 
    }
    cout << "Friends of " << src << " are ";
    for(size_t i = 0; i < adjList[src].size(); i++){
        cout << adjList[src][i] << " ";
    }
    cout << endl;
}


/* int main(){
    Graph g;
    g.addNode("A");
    g.addNode("B");
    g.addNode("C");
    g.addNode("D");
    g.addEdge("A", "B");
    g.addEdge("C", "B");
    g.addEdge("A", "C"); //cycle
    g.addEdge("C", "D");
    g.addEdge("G", "H") ? cout << "Yes" << endl : cout << "No such node" << endl;
    //g.removeEdge("C", "B");
    g.removeEdge("G", "H") ? cout << "Yes" << endl : cout << "No such edge" << endl;
    g.removeEdge("A", "D") ? cout << "Yes" << endl : cout << "No such edge" << endl;
    g.printAdjList();
    g.printFriendsOf("C");
    g.inRadius("A", "D", 3) ? cout << "In radius" << endl : cout << "Not in radius" << endl;
    g.inRadius("A", "D", 1) ? cout << "In radius" << endl : cout << "Not in radius" << endl;

} */