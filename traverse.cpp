void BTreeNode::traverse()
{
    //for loop runs through 'current' children
    for (int i = 0; i < current; i++) {
        // If the current node is not a leaf, traverse the subtree rooted with children[i] then print key[i],
        if (leaf == false)
            chidren[i]->traverse();
        cout << " " << keys[i];
    }
    // Print the subtree rooted with last child
    if (leaf == false)
        children[i]->traverse();
}