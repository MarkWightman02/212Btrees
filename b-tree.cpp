#include "b-tree.h"

//Tree Class
BTree::BTree(int degree){
  this->root = NULL;
  this->degree = degree;
}


void BTree::insert(int data){
    int i = 0;
    while ((i < current) && (data > keys[i])) {
        i++;
        // If the current key = input, return this node
        if (keys[i] == data) {
            return this;
        }
        // if this is a leaf node and the key is not here
        if (leaf == true) {
            return NULL;
        }
        // recursive call using children of i as the data parameter
        return children[i]->search(data);
    }
}

Node* BTree::search(int data){


}

void traverse(){

}

//Node Class
Node::Node(int data, bool leaf){

}
void insertNotFull(int data){

}

void Node::traverse(){

}

void splitChild(int index, Node *child){

}

Node* search(int data){

}