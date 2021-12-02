// Function to search for a key 'data' in the tree
Node *Node::search(int data)
{
    int i = 0;
    while ((i < current) && (data > keys[i])){
        i++;
        // If the current key = input, return this node
        if (keys[i] == data)
            return this;
        // if this is a leaf node and the key is not here
        if (leaf == true)
            return NULL;
        // recursive call using children of i as the data parameter
        return children[i]->search(data);
    }
}