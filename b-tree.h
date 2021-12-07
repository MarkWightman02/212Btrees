#include <iostream>
#include <vector>
#include <string>

class Node{

private:
    //Current # of keys in node
    int current;
    //True if node is a leaf
    bool leaf;
    //Vector of keys in the node
    std::vector<std::pair<std::string,int>> keys;
    //Vector of the node's children
    std::vector<Node*> children;
    //max degree of node
    int degree;


public:
    //Constructor
    Node(int data, bool leaf);
    //Insert when not full
    void insertNotFull(int data);
    //Traverse tree with this node as root
    void traverse();
    //When the child is full, this function will split it, index is the index of the child array
    void splitChild(int index, Node *child);
    //Find a key in a tree with this node as root
    Node* search(int data);

    //Make BTree a friend
    friend class BTree;

};


class BTree{

//Private class members of the tree include
//a pointer to the root node and the # of keys in a node
private:
    Node *root;
    int degree;

public:

    //Create an empty B Tree
    BTree(int degree);
    //Insert data into the Tree
    void insert(int data);
    //Search for a key within the tree and return the node it's at
    Node* search(int data);
    //Traverse the tree
    void traverse();


};
