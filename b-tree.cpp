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
    std::pair <int,std::string> junk (-1, "test");
    this->root->keys.push_back(junk);
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
Node::Node(int data, bool leaf){

}
void insertNotFull(int data){

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

void splitChild(int index, Node *child){

}

Node *Node::search(int data){

  //Find the key that is greater >= to the data we are inserting
    int i = 0;


    while ((i < this->current) && (data > this->keys[i].first)){
        i++;


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
}
