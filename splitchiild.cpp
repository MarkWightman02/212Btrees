// ? = variable i am not sure what we ae using throughout code

void splitChild(int index, Node *child){
    Node *z = new Node (child -> ?, child -> leaf);
    z -> n = ? - 1

    for(int j = 0;  j < ? - 1; j++){
        z -> keys[j] = child -> keys [j + ?];
    }
    if (child -> leaf == false){
        for(int j = 0; j < ?; j++){
            z -> C[j] = child -> C [j + ?];
        }
    }
     child -> n = ? - 1;
     
     for(int j = n - 1; j >= i; j--){
         keys[j + 1] = keys[j];
     }
     
     keys[i] = y -> keys[? - 1];
     
     n = n + 1;
}
