#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

BST::BST(): root(nullptr) {}

BST::BST(Song* r): root(r) {}

BST::~BST(){
    clearAll(root);
}

void BST::clearAll(Song* root){
    if(root != nullptr){
        clearAll(root->left);
        clearAll(root->right);
        delete root;
    }
    
}

Song* BST::treeSearch(string songTitle){
    return treeSearchHelper(root, songTitle);
}

Song* BST::treeSearchHelper(Song* root, string songTitle){
    if(root == nullptr){
        return root;
    }
    else if(root->get_title() == songTitle){
        return root;
    }
    else{
        if(songTitle.compare(root->get_title()) < 0){
            return treeSearchHelper(root->left, songTitle);
        }
        else{
            return treeSearchHelper(root->right, songTitle);
        }
    }
}

int BST::treeSearchIndex(string songTitle){
    return treeSearchIndexHelper(root, songTitle);
}

int BST::treeSearchIndexHelper(Song* root, string songTitle){
    if(root == nullptr){
        return -1;
    }
    if(root->get_title() == songTitle){
        return root->get_index();
    }
    else{
        if(songTitle.compare(root->get_title()) < 0){
            return treeSearchIndexHelper(root->left, songTitle);
        }
        else{
            return treeSearchIndexHelper(root->right, songTitle);
        }
    }
}

bool BST::treeInsert(string songTitle){
    return treeInsertHelper(root, songTitle);
}

bool BST::treeInsertHelper(Song*& root, string songTitle){
    if(root == nullptr){
        root = new Song(songTitle);  //Destructor??
        return true;
    } 
    else{
        if(songTitle.compare(root->get_title()) < 0){
            return treeInsertHelper(root->left, songTitle);
        }
        else if(songTitle.compare(root->get_title()) > 0){
            return treeInsertHelper(root->right, songTitle);
        }
        else{
            return false;
        }
    }
}

bool BST::treeInsertNode(Song* node){
    return treeInsertNodeHelper(root, node);
}

bool BST::treeInsertNodeHelper(Song*& root, Song* node){
    if(root == nullptr){
        root = node;  
        return true;
    } 
    else{
        if(node->get_title().compare(root->get_title()) < 0){
            return treeInsertNodeHelper(root->left, node);
        }
        else if(node->get_title().compare(root->get_title()) > 0){
            return treeInsertNodeHelper(root->right, node);
        }
        else{
            return false;
        }
    }
}

bool BST::treeRemove(string songTitle){
    return treeRemoveHelper(root, songTitle);
}

void BST::findMinSwap(Song*& prev, Song*& local){
    if(local->left != nullptr){
        findMinSwap(prev, local->left);
    }
    else{
        prev->set_title(local->get_title());
        prev = local;
        local = local->right;
    }
}

bool BST::treeRemoveHelper(Song*& root, string songTitle){
    if(root == nullptr ){
        return false;
    }
    else{
        if(songTitle.compare(root->get_title()) < 0){
            return treeRemoveHelper(root->left, songTitle);
        }
        else if(songTitle.compare(root->get_title()) > 0){
            return treeRemoveHelper(root->right, songTitle);
        }
        else{
            // Found the node consider 3 cases
            Song* previous = root;
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

void BST::inOrderTraversal(Song* root, bool count){
    if(root == nullptr){
        return;
    }
    else {
        if(root->left != nullptr){
            inOrderTraversal(root->left, count);
        }
        cout << root->get_title() << " ";
        (count) ? cout << root->get_count() << endl : cout << endl; 
        if(root->right != nullptr){
            inOrderTraversal(root->right, count);
        }
    }
}

Song* BST::getRoot(){
    return root;
}

/* 
int main(){
    BST bst;
    bst.treeInsert("Billie Jean");
    bst.treeInsert("Dangerous");
    bst.treeInsert("Thriller");
    bst.treeInsert("Beat it");
    bst.inOrderTraversal(bst.getRoot());
    Song* ret = bst.treeSearch("Dangerous");
    cout << ret->get_title() << endl;
    ret = bst.treeSearch("Billie Jean");
    cout << ret->get_title() << endl;
    ret = bst.treeSearch("BB");
    if(ret == nullptr) cout << "Nullptr" << endl;

    cout << "Removing Billie Jean" << endl;
    bst.treeRemove("Billie Jean");
    bst.inOrderTraversal(bst.getRoot());

    cout << "Removing Thriller" << endl;
    bst.treeRemove("Thriller");
    bst.inOrderTraversal(bst.getRoot());

    cout << "Removing Beat it" << endl;
    bst.treeRemove("Beat it");
    bst.inOrderTraversal(bst.getRoot()); 

    cout << "Removing Dangerous" << endl;
    bst.treeRemove("Dangerous");
    bst.inOrderTraversal(bst.getRoot()); 

   
}  */