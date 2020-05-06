#ifndef HASHTABLELINEARPROBING_HPP
#define HASHTABLELINEARPROBING_HPP

struct hashNode{
    int key;

  hashNode()
  {
    key = 0;
  }
  hashNode(int k)
  {
    key = k;
  }
  ~hashNode() {}
};

class HashLinProbe{

    hashNode** table;
    int tableSize;
    int numberOfCollisions;

public:
    HashLinProbe();
    HashLinProbe(int tSize);
    ~HashLinProbe();

    int hashCode(int);
    void insert(int);
    hashNode* search(int);
    int getNumCollisions();

    void printHashTable();

};

#endif