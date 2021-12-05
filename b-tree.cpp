#include "b-tree.h"

//Tree Class
BTree::BTree(int degree){
  this->root = NULL;
  this->degree = degree;
}


void BTree::insert(int data){
  if (this->root == NULL){
    this->root = new Node(degree, true);
    this->root->keys[0] = data;
    this->root->current = 1;
  }else{
    if (this->root->current == 2*degree-1){
      Node *tmp = new Node(degree, false);

      tmp->children[0] = this->root;

      tmp->splitChild(0,this->root);

      int zeroOrNot = 0;
      if (tmp->keys[0] < data){
        zeroOrNot = 1;
      }

      tmp->children[zeroOrNOt]->insertNonFull(data);

      this->root = tmp;
    }
    else{
      this->root->insertNonFull(data);
    }
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
