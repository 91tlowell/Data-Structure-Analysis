/*
    This is a header file for a Binary search tree
*/
#ifndef BST_HPP
#define BST_HPP

struct Node
{
    int key;
    Node* left = NULL;
    Node* right = NULL;
};

class BST
{
private:
    Node* root;
    Node* addNodeHelper(Node*, int);
    Node* createNode(int);
    Node* searchNodeHelper(Node*, int);
    void destructo(Node*);
    void inOrderTraversal(Node*);
public:
    BST(/* args */);
    ~BST();
    void addNode(int);
    void treeTraversalPrint();

    Node* searchNode(int);
};

#endif

