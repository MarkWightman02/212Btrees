#include <iostream>

class BTree{

private:

    int t;

public:

    BTree():
    BTree(int t);
    void insert;
    void search;
    ~BTree();

friend class Node;
};


class Node{

private:

   bool leaf;

public:

    Node();
    Node(bool leaf)
    void traverse;
    void splitChild;

};