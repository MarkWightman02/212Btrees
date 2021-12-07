#include "b-tree.h"

//Tree Class
BTree::BTree(int degree){
  this->root = NULL;
  this->degree = degree;
}

void BTree::insert(int data){
  if (this->root == NULL){
    this->root = new Node(this->degree, true);
    this->root->keys[0] = data;
    this->root->current = 1;
  }else{
    if (this->root->current == 2*degree-1){
      Node *tmp = new Node(this->degree, false);

      tmp->children[0] = this->root;

      tmp->splitChild(0,this->root);

      int zeroOrNot = 0;
      if (tmp->keys[0] < data){
        zeroOrNot = 1;
      }

      tmp->children[zeroOrNot]->insertNotFull(data);

      this->root = tmp;
    }
    else{
      this->root->insertNotFull(data);
    }
  }
}

Node *Node::search(int data)
{
    int i = 0;
    while ((i < current) && (data > keys[i])){
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

void Node::traverse() {
    //for loop runs through 'current' children
    for (int i = 0; i < current; i++) {
        // If the current node is not a leaf, traverse the subtree rooted with children[i] then print key[i],
        if (leaf == false) {
            chidren[i]->traverse();
        }
        cout << " " << keys[i];
    }
    // Print the subtree rooted with last child
    if (leaf == false) {
        children[i]->traverse();
    }
}

//Node Class
Node::Node(int data, bool leaf){

}
void insertNotFull(int data){

}

void splitChild(int index, Node *child){

}