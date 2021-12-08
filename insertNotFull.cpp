// ? = unknown universal variable for code
void Node::insertNotfull(int data) {
    int i = n - 1;
    
    if(leaf == true){
        while (i >= 0 && key[i] > data){
            keys[i + 1] = keys[i];
            i --;
        }
        keys [i + 1] = k;
        n = n + 1;
    } else {
        while( i >= 0 && keys[i] > data)
            i --;
        
        if(C[i + 1] -> n == 2 * ? - 1){
            splitChild(i + 1, C[i + 1]);
            
            if(keys[i + 1] < data)
                i ++;
        }
        C[i + 1] -> insertNotFull(data);
    }
}
