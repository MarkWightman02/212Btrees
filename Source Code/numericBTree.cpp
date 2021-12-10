// Searching a key on a B-tree in c++

#include <iostream>
#include <fstream>

class Node {
  std::pair <std::string, int> *keys;
  int t;
  Node **kids;
  int numKeys;
  bool leaf;

   public:
  Node(int temp, bool bool_leaf);

  void insertNonFull(std::pair <std::string, int> k);
  void splitChild(int i, Node *y);
  void traverse();
  void makeDot(std::ofstream &dotFile);

  Node *search(int k);

  friend class BTree;
};

class BTree {
  Node *root;
  int t;

   public:
  BTree(int temp) {
    root = NULL;
    t = temp;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  Node *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }
  
  void makeDot(std::ofstream &dotFile) {
    root->makeDot(dotFile);
  }
  
  void insert(std::pair <std::string, int> k);
};

Node::Node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new std::pair <std::string, int> [2 * t - 1];
  kids = new Node *[2 * t];

  numKeys = 0;
}

// void Node::traverse() {
//   int i;
//   for (i = 0; i < numKeys; i++) {
//     if (leaf == false)
//       kids[i]->traverse();
//     std::cout << " " << keys[i].first;
//   }

//   if (leaf == false)
//     kids[i]->traverse();
// }

void Node::traverse() {
  
  for (int i = 0; i < numKeys + 1; i++) {
    if (leaf == false)
      kids[i]->traverse();
    if(i != numKeys)
      std::cout << " " << keys[i].first;
  }

}

Node *Node::search(int k) {
  int i = 0;
  while (i < numKeys && k > keys[i].second)
    i++;

  if (keys[i].second == k) {
    std::cout << char(34) << keys[i].first << char(34) << " was found and appears " << k << " times!!!\n";
    return this;
  }
  
  if (leaf == true) {
    return NULL;
  }
  
  return kids[i]->search(k);
}

void BTree::insert(std::pair <std::string, int> k) {
  if (root == NULL) {
    root = new Node(t, true);
    root->keys[0] = k;
    root->numKeys = 1;
  } 
  else {
    if (root->numKeys == 2 * t - 1) {
      Node *s = new Node(t, false);

      s->kids[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0].second < k.second)
        i++;
      s->kids[i]->insertNonFull(k);

      root = s;
    } else
      root->insertNonFull(k);
  }
}

void Node::insertNonFull(std::pair <std::string, int> k) {
  int i = numKeys - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i].second > k.second) {
      keys[i + 1] = keys[i];
      i--;
    }
    
    keys[i + 1] = k;
    numKeys = numKeys + 1;
  } 
  else {
    while (i >= 0 && keys[i].second > k.second)
      i--;

    if (kids[i + 1]->numKeys == 2 * t - 1) {
      splitChild(i + 1, kids[i + 1]);

      if (keys[i + 1].second < k.second)
        i++;
    }
    kids[i + 1]->insertNonFull(k);
  }
}

void Node::splitChild(int i, Node *y) {
  
  Node *z = new Node(y->t, y->leaf);
  z->numKeys = t - 1;

  for (int j = 0; j < t - 1; j++) //copies keys from the ROOT node except the left key
    z->keys[j] = y->keys[j + t];  

  if (y->leaf == false) { 
    for (int j = 0; j < t; j++)
      z->kids[j] = y->kids[j + t];
  }

  y->numKeys = t - 1;
  
  for (int j = numKeys; j >= i + 1; j--)
    kids[j + 1] = kids[j];

  kids[i + 1] = z;

  for (int j = numKeys - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  keys[i] = y->keys[t - 1];
  numKeys = numKeys + 1;
}

void Node::makeDot(std::ofstream &myDot) {
  
  
  int i;
  for (i = 0; i < numKeys + 1; i++) {
    
    
    if (leaf == false){
      
      kids[i]->makeDot(myDot);
      
      
      for (int j = 0; j < numKeys; j++) {
        if (j == 0) {
            myDot << char(34) << "| (" << keys[j].first << ": " << keys[j].second << ')' << " | ";
        }
        else {
            myDot << '(' << keys[j].first << ": " << keys[j].second << ')' << " | ";
        }
      }
      
      myDot << char(34) << " -> " << char(34);
      
      for (int j = 0; j < kids[i]->numKeys; j++) {
        if (j == 0) {
            myDot << "| (" << ( kids[i]->keys[j] ).first << ": " << ( kids[i]->keys[j] ).second << ')' << " | ";
        }
        else {
            myDot << '(' << ( kids[i]->keys[j] ).first << ": " << ( kids[i]->keys[j] ).second << ')' << " | ";
        }
        
      }
      myDot << char(34) << '\n';
      
      
    }
    
    
  }
    
}

// int main() {
//   BTree t(3);
//   t.insert(8);
//   t.insert(9);
//   t.insert(10);
//   t.insert(11);
//   t.insert(15);
//   t.insert(16);
//   t.insert(17);
//   t.insert(18);
//   t.insert(20);
//   t.insert(23);

//   // cout << "The B-tree is: ";
//   // t.traverse();

//   // int k = 10;
//   // (t.search(k) != NULL) ? cout << endl
//   //               << k << " is found"
//   //             : cout << endl
//   //               << k << " is not Found";

//   // k = 2;
//   // (t.search(k) != NULL) ? cout << endl
//   //               << k << " is found"
//   //             : cout << endl
//   //               << k << " is not Found\n";
// }