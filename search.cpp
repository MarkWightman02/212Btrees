#include <iostream>

void search(int k){
    
}

//--------------------------------------

// Define int n in private as number of keys in *keys
// define in *keys in private as an array of keys


// Function to search key k in subtree rooted with this node
int search(int k, int n, int *keys) {
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i]) {
        i++;
 
        // If the found key is equal to k, return this node
        if (keys[i] == k) {
            return this;
        }
        
        // If the key is not found here and this is a leaf node
        if (leaf == true) {
            return NULL;
        {
    }
    // Go to the appropriate child
    return C[i]->search(k);
}

//-------------------------------------

int search(int k, int n, int *keys) {
    for (int i = 0; i < n; i++) {
        if (keys[i] == k) {
            return k;
        }
        if (leaf == true) {
            return NULL;
        {
    }
}

int search(int k) {
    for (int i = 0; i < n; i++) {
        
    }
}

// ---------------------------------------

//priv
bool BSTree::search(int data, BSTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

//pub
bool BSTree::search(int data){
    return this->search(data, this->root);
}

//----------------

bool BTree::search(int k, int root){
    if root == k
        return true
    if root < k
        return this search(k, root->left)
    if root > k
        return this search(k, root->right)
}

vector<vector<int>>btree;


bool BTree::search() {
/*
btree[node][key]

if root equals k
    return true
if root < k
    
if root > k

if !root
    


*/

TreeNode *TreeNode::search(int k) {
  int i = 0;
  while (i < n && k > keys[i])
    i++;

  if (keys[i] == k)
    return this;

  if (leaf == true)
    return NULL;

  return C[i]->search(k);
}
}
//------------------

1.  Starting from the root node, compare k with the first key of the node.
        If k = the first key of the node, return the node and the index.
2.  If k.leaf = true, return NULL (i.e. not found).
3.  If k < the first key of the root node, search the left child of this key recursively.
4.  If there is more than one key in the current node and k > the first key, compare k with the next key in the node.
        If k < next key, search the left child of this key (ie. k lies in between the first and the second keys).
        Else, search the right child of the key.
5.  Repeat steps 1 to 4 until the leaf is reached.