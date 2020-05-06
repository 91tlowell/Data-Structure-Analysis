#include <iostream>
#include "hashTableChaining.hpp"

using namespace std;


HashChain :: HashChain(int tSize){
    numberOfCollisions = 0;
    tableSize = tSize;
    table = new hashNode *[tSize];
    for (int i = 0; i < tableSize; i++){
        table[i] = NULL;
    }
}


HashChain :: ~HashChain(){
    for (int i = 0; i < tableSize; i++) {
        hashNode* temp = table[i];
        while (temp != 0) {
            hashNode* curr = temp;
            temp = temp->next;
            delete curr;
        }
    }
    delete[] table;
}

int HashChain ::  hashCode(int key){
    return key % tableSize;
}

int HashChain :: getNumCollisions(){
    return numberOfCollisions;
}

void HashChain :: insert(int key){
    hashNode* node = new hashNode(key);
    int index = hashCode(key);

    if (table[index] == 0){
        table[index] = node;
    }
    else{
        node->next = table[index];
        table[index] = node;
        numberOfCollisions++;
    }
}

hashNode* HashChain :: search(int key){
    int index = hashCode(key);

    if (table[index] == 0)  return 0;
    else {
        hashNode* curr = table[index];
        while (curr != 0) {
            if (curr->key == key){
                return curr;
            }
            else curr = curr->next;
        }
        return 0;
    }
}

void HashChain :: printHashTable(){
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != 0) {
            cout << "[" << i << "] ";
            hashNode* curr = table[i];
            while (curr != 0) {
                cout << "-> Key: " << curr->key << " (#" << hashCode(curr->key)<< ") Value: " << curr->key; 	  
                curr = curr->next;
            }
            cout << endl;
        }
        else{
        cout << "[" << i << "] -> Empty" << endl;
        }
    }
}