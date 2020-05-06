#include <iostream>
#include "hashTableLinearProbing.hpp"



HashLinProbe :: HashLinProbe(){

}

HashLinProbe :: HashLinProbe(int tSize){
    numberOfCollisions = 0;
    tableSize = tSize;
    table = new hashNode *[tSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = 0;
}

HashLinProbe :: ~HashLinProbe(){
    delete [] table;
}

int HashLinProbe :: hashCode(int key){
    return key % tableSize;
}

void HashLinProbe :: insert(int key){
    hashNode *node = new hashNode(key);
    int index = hashCode(key);

    if (table[index] == 0)
        table[index] = node;
    else
    {
        for (int i = (index + 1) % tableSize; i != index; i = (i + 1) % tableSize){
            numberOfCollisions++;
            if (table[i] == 0){
                table[i] = node;
                return;
            }
        }
    }
}
hashNode* HashLinProbe :: search(int key){
    int index = hashCode(key);
    if (table[index] == 0)
        return 0;
    else if (table[index]->key == key)
        return table[index];
    else
    {
        for (int i = (index + 1) % tableSize; i != index; i = (i + 1) % tableSize)
        {
            if (table[i] == 0)
                return 0;
            else if (table[i]->key == key)
                return table[i];
        }
        return 0;
    }
}

int HashLinProbe :: getNumCollisions(){
    return numberOfCollisions;
}

void HashLinProbe :: printHashTable(){
    for (int i = 0; i < tableSize; i++){
        if (table[i] != 0){
            std::cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key) << ") Value: " << table[i]->key << std::endl;
        }
        else{
            std::cout << "[" << i << "] -> Empty" << std::endl;
        }
    }
}