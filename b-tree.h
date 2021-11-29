#include <iostream>

class BTree{

private:

    int t;

public:

    BTree():
    ~BTree();
    BTree(int t);
    void insert(int data);
    void search(int data);


friend class Node;
};


class Node{

private:

   bool leaf;

public:

    Node();
    Node(bool leaf);
    void traverse();
    void splitChild();

};
