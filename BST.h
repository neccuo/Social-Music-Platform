#pragma once
#include <string>
#include "Song.h"
using namespace std;

class BST{
    private:
        /* class TreeNode{
        public:
            Song* song;
            TreeNode* left;
            TreeNode* right;
            TreeNode(): song(nullptr), left(nullptr), right(nullptr) {}
            TreeNode(Song* s): song(s), left(nullptr), right(nullptr) {} //requires Song copy constructor
            TreeNode(Song* s, TreeNode* left, TreeNode* right) : song(s), left(left), right(right) {}
        }; */
        Song* root;
        bool treeInsertHelper(Song*& root, string songTitle);
        bool treeInsertNodeHelper(Song*& root, Song* node);
        Song* treeSearchHelper(Song* root, string songTitle);
        bool treeRemoveHelper(Song*& root, string songTitle);
        int treeSearchIndexHelper(Song* root, string songTitle);
        void findMinSwap(Song*& prev, Song*& local);
        void clearAll(Song* root);
    public:
        BST();
        BST(Song* r);
        ~BST();
        Song* treeSearch(string songTitle);
        int treeSearchIndex(string songTitle);
        bool treeInsert(string songTitle);
        bool treeInsertNode(Song* node);
        bool treeRemove(string songTitle);
        void inOrderTraversal(Song* root, bool count);
        Song* getRoot();    

};
