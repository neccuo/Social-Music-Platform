#include <iostream>
#include <string>
#include "UBST.h"

using namespace std;

UBST::UBST(): root(nullptr) {}

UBST::UBST(User* r): root(r) {}

UBST::~UBST(){
    clearAll(root);
}

void UBST::clearAll(User* root){
    if(root != nullptr){
        clearAll(root->left);
        clearAll(root->right);
        delete root;
    }   
}

User* UBST::treeSearch(string UserName){
    return treeSearchHelper(root, UserName);
}

User* UBST::treeSearchHelper(User* root, string UserName){
    if(root == nullptr){
        return root;
    }
    else if(root->getUserName() == UserName){
        return root;
    }
    else{
        if(UserName.compare(root->getUserName()) < 0){
            return treeSearchHelper(root->left, UserName);
        }
        else{
            return treeSearchHelper(root->right, UserName);
        }
    }
}

bool UBST::treeInsert(string UserName){
    return treeInsertHelper(root, UserName);
}

bool UBST::treeInsertHelper(User*& root, string UserName){
    if(root == nullptr){
        root = new User(UserName);  //Destructor??
        return true;
    } 
    else{
        if(UserName.compare(root->getUserName()) < 0){
            return treeInsertHelper(root->left, UserName);
        }
        else if(UserName.compare(root->getUserName()) > 0){
            return treeInsertHelper(root->right, UserName);
        }
        else{
            return false;
        }
    }
}

bool UBST::treeRemove(string UserName){
    return treeRemoveHelper(root, UserName);
}

void UBST::findMinSwap(User*& prev, User*& local){
    if(local->left != nullptr){
        findMinSwap(prev, local->left);
    }
    else{
        prev->setUserName(local->getUserName());
        prev = local;
        local = local->right;
    }
}

bool UBST::treeRemoveHelper(User*& root, string UserName){
    if(root == nullptr ){
        return false;
    }
    else{
        if(UserName.compare(root->getUserName()) < 0){
            return treeRemoveHelper(root->left, UserName);
        }
        else if(UserName.compare(root->getUserName()) > 0){
            return treeRemoveHelper(root->right, UserName);
        }
        else{
            // Found the node consider 3 cases
            User* previous = root;
            if(root->left == nullptr){
                root = root->right;
            }
            else if(root->right == nullptr){
                root = root->left;
            }
            else{
                findMinSwap(previous, previous->right);
            }
            delete previous;
            return true;
        }
    }
}

void UBST::inOrderTraversal(User* root){
    if(root == nullptr){
        return;
    }
    else {
        if(root->left != nullptr){
            inOrderTraversal(root->left);
        }
        cout << root->getUserName() << endl;
        if(root->right != nullptr){
            inOrderTraversal(root->right);
        }
    }
}

User* UBST::getRoot(){
    return root;
}

/* int main()
{
    UBST UBST;
    UBST.treeInsert("Ahmet");
    UBST.treeInsert("Mehmet");
    UBST.treeInsert("Ayşe");
    UBST.treeInsert("Dilmeran");

    UBST.inOrderTraversal(UBST.getRoot());

    User* ret = UBST.treeSearch("Ayşe");
    cout << ret->getUserName() << endl;

    ret = UBST.treeSearch("Dilmeran");
    cout << ret->getUserName() << endl;
    ret = UBST.treeSearch("BB");
    if(ret == nullptr) cout << "Nullptr" << endl;

    cout << "Removing Mehmet" << endl;
    UBST.treeRemove("Mehmet");
    UBST.inOrderTraversal(UBST.getRoot());
    UBST.inOrderTraversal(UBST.getRoot());

    cout << "Removing Ayşe" << endl;
    UBST.treeRemove("Ayşe");
    UBST.inOrderTraversal(UBST.getRoot());

    cout << "Removing Dilmeran" << endl;
    UBST.treeRemove("Dilmeran");
    UBST.inOrderTraversal(UBST.getRoot());

    cout << "Removing Ahmet" << endl;
    UBST.treeRemove("Ahmet");
    UBST.inOrderTraversal(UBST.getRoot());
    UBST.inOrderTraversal(UBST.getRoot());
} */