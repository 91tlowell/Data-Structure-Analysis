#ifndef HASHTABLEQUADRATIC_HPP
#define HASHTABLEQUADRATIC_HPP

struct hashNode{
    int key;

  // hashNode()
  // {
  //   key = 0;
  // }
  hashNode(int k)
  {
    key = k;
  }
};

class HashQuadProbe{

    hashNode** table;
    int tableSize;
    int numberOfCollisions;

public:
    HashQuadProbe();
    HashQuadProbe(int tSize);
    ~HashQuadProbe();

    int hashCode(int);
    void insert(int);
    hashNode* search(int);
    int getNumCollisions();

    void printHashTable();

};

#endif