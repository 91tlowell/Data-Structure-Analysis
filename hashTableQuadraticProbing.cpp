#include <iostream>
#include "hashTableQuadraticProbing.hpp"



HashQuadProbe :: HashQuadProbe(){

}

HashQuadProbe :: HashQuadProbe(int tSize){
    numberOfCollisions = 0;
    tableSize = tSize;
    table = new hashNode *[tSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = 0;
}

HashQuadProbe :: ~HashQuadProbe(){
    delete [] table;
}

int HashQuadProbe :: hashCode(int key){
    return key % tableSize;
}

void HashQuadProbe :: insert(int key){
    hashNode *node = new hashNode(key);
    int index = hashCode(key);

    if (table[index] == 0)
        table[index] = node;
    else
    {
        int i = 1;
        int original_index = index;
        while(index < tableSize){
            numberOfCollisions++;
            index = (original_index + (i * i)) % tableSize;
            if(table[index] == 0){
                table[index] = node;
                return;
            }
            if(i >= tableSize){
                break;
            }
            i++;
        }
    }
}
hashNode* HashQuadProbe :: search(int key){
    int index = hashCode(key);
    if (table[index] == 0)
        return 0;
    else if (table[index]->key == key)
        return table[index];
    else
    {
        int i = 0;
        while(index < tableSize){
            index = (index + (i * i)) % tableSize;
            if(table[index]==0)
            return 0;
            
            if(table[index]->key == key){
                 return table[index];
            }
            i++;
        }
        //return 0;
    }
    return 0;
}

int HashQuadProbe :: getNumCollisions(){
    return numberOfCollisions;
}

void HashQuadProbe :: printHashTable(){
    for (int i = 0; i < tableSize; i++){
        if (table[i] != 0){
            std::cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key) << ") Value: " << table[i]->key << std::endl;
        }
        else{
            std::cout << "[" << i << "] -> Empty" << std::endl;
        }
    }
}