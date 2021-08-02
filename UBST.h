#pragma once
#include <string>
#include "User.h"
using namespace std;

class UBST{
    private:
        User* root;
        bool treeInsertHelper(User*& root, string UserName);
        User* treeSearchHelper(User* root, string UserName);
        bool treeRemoveHelper(User*& root, string UserName);
        void findMinSwap(User*& prev, User*& local);
        void clearAll(User* root);

    public:
        UBST();
        UBST(User* r);
        ~UBST();
        User* treeSearch(string UserName);
        bool treeInsert(string UserName);
        bool treeRemove(string UserName);
        void inOrderTraversal(User* root);
        User* getRoot();    

};
