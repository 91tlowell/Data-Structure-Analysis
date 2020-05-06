#ifndef HASHTABLECHAINING_HPP
#define HASHTABLECHAINING_HPP

struct hashNode{
    int key;
    hashNode* next;

    hashNode() {key = 0; next = 0;}
    hashNode(int k) {key = k; next = 0;}
    ~hashNode() {}
};

class HashChain{

    hashNode** table;
    int tableSize;
    int numberOfCollisions;

public:
    HashChain();
    HashChain(int tSize);
    ~HashChain();

    int hashCode(int);
    void insert(int);
    hashNode* search(int);
    int getNumCollisions();

    void printHashTable();

};

#endif