#include "b-tree.h"

//Tree Class
BTree::BTree(int degree){
  this->root = NULL;
  this->degree = degree;
}

//Fxn to insert data into the tree
void BTree::insert(int data, std::string word){

  //Create a pair of the data we want to insert
  std::pair <int,std::string> dataToInsert (data, word);

  //If the tree is empty
  if (this->root == NULL){

    //Make a new node and make it the root
    this->root = new Node(this->degree, true);
    //Give the new root a key of the data we are inserting
    this->root->keys[0] = dataToInsert;
    //Change the roots current keys to 1
    this->root->current = 1;

  //If the tree is not empty
  }else{
    //If the root is full
    if (this->root->current == 2*degree-1){

      //Make a new node
      Node *tmp = new Node(this->degree, false);

      //make the root node a child of the new node
      tmp->children[0] = this->root;

      //call splitchild on the new node
      tmp->splitChild(0,this->root);

      //Keep an iterator
      //Figure out where the data is going
      int zeroOrNot = 0;
      if (tmp->keys[0].first < data){
        zeroOrNot++;
      }

      //Insert the data into the node at the correct spot
      tmp->children[zeroOrNot]->insertNotFull(data);

      //Make the root the new node
      this->root = tmp;
    }

    //If root is not full
    else{
      //Insert the key into the root
      this->root->insertNotFull(data);
    }
  }
}

Node* BTree::search(int data){
  if (this->root == NULL){
    return NULL;
  }else{
    return this->root->search(data);
  }

}

//Node Class
Node::Node(int degree, bool leaf){

  //Setters
  this->degree = degree;
  this->leaf = leaf;

  //Give the array space for the degree
  this->keys = new std::pair<int,std::string>[2*degree-1];
  //Give the children array enough space
  this->children = new Node *[2*(this->degree)];

  //Default 0 keys;
  this->current = 0;


}
void Node::insertNotFull(int data){

  //Make an iterator, start it at the last element in the current node's keys
  int i = this->current-1;

  //Check if leaf
  if (this->leaf == true){

    //Move keys over to insert new key
    while (i >= 0 && this->keys[i].first > data){
      this->keys[i+1] = keys[i];
      i--;
    }

    //Add the new key
    this->keys[i+1].first = data;
    this->current = this->current+1;
  }else{
    //Decrement i until the child is found
    while(i>=0 && this->keys[i].first > data){
      i--;
    }

    //Find if found child is full
    if(this->children[i+1]->current = 2*(this->degree)-1){
      //If so, split it
      this->splitChild(i+1, this->children[i+1]);

      //Then, rotate
      if(this->keys[i+1].first < data){
        i++;
      }
    }
      //finish by recursively calling again
    this->children[i+1]->insertNotFull(data);
  }
}

void Node::traverse() {
    //for loop runs through 'current' children
    int i = 0;
    for (i = 0; i < this->current; i++) {
        // If the current node is not a leaf, traverse the subtree rooted with children[i] then print key[i],
        if (this->leaf == false) {
            children[i]->traverse();
        }
        std::cout << " " << this->keys[i].second;
    }

    //If the node is not a leaf, go to its child and print
    if (leaf == false) {
        children[i]->traverse();
    }
}

void Node::splitChild(int index, Node *child){
  //New node will store keys = to degree -1

  Node *tmp = new Node(child->degree, child->leaf);
  tmp->current = this->degree-1;

  //Copy over the last keys from the child to the new node
  for(int i = 0; i < this->degree-1; i++){
    tmp->keys[i] = child->keys[i + this->degree];
  }

  //Copy over last children from child to new node
  if(!child->leaf){
    for(int i = 0; i < this->degree; i++){
      tmp->children[i] = child->children[i+this->degree];
    }
  }

  //-1 from keys in child
  child->current= this->degree-1;

  //Allocate space for new child
  for (int i = this->current; i>= i+1; i--){
    this->children[i+1] = this->children[i];
  }

  //Set child to new node
  this->children[index+1] = tmp;

  //Find new node, move values
  for (int i = this->current; i >= index; i--){
    this->keys[i+1] = this->keys[i];
  }

  //Copy key to new node
  this->keys[index] = tmp->keys[this->degree-1];
  //+1 to current keys
  this->current++;

}

Node *Node::search(int data){

  //Find the key that is greater >= to the data we are inserting
    int i = 0;


    while ((i < this->current) && (data > this->keys[i].first)){
        i++;
    }


    // If the current key = input,we found the node, return it, base case
    if (this->keys[i].first == data) {
        return this;
    }
    // if this is a leaf node and the key is not here
    if (leaf == true) {
        return NULL;
    }

    // recursive call using children of i as the data parameter
    return children[i]->search(data);
}
