#include <iostream>
#include "BST.hpp"

using namespace std;

/*
    Basic BST Implementation
    Class designed for Inserting and Serching for data with tools accompanied for debugging purposes 
        ie: printing
    
*/

BST :: BST(){
    root = NULL;
}

BST :: ~BST(){
    destructo(root);
    root = NULL;
}

void BST :: destructo(Node* temp){
    if (temp != NULL){
        destructo(temp -> left);
        destructo(temp -> right);
        delete temp;
    }
}

void BST :: addNode(int key){
    root = addNodeHelper(root, key);
}
void BST :: treeTraversalPrint(){
       //write your code
   if (root == NULL){
     cout << "Tree is empty. Cannot print" << endl;
   }
   else{
     inOrderTraversal(root);
   }
}

Node* BST :: searchNode(int key){
    return searchNodeHelper(root, key);
}

Node* BST :: addNodeHelper(Node* currNode, int key){
    if(currNode == NULL){
        return createNode(key);
    }
    else if(currNode->key < key){
        currNode->right = addNodeHelper(currNode->right, key);
    }
    else if(currNode->key > key){
        currNode->left= addNodeHelper(currNode->left, key);
    }
    return currNode;
}

Node* BST :: createNode(int key){
    Node* newNode = new Node;
    newNode -> key = key;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

Node* BST :: searchNodeHelper(Node* currNode, int key){
    if (currNode == NULL)
        return currNode;
    else if(currNode->key == key)
        return currNode;
    else if (currNode->key > key)
        return searchNodeHelper(currNode->left, key);
    else
        return searchNodeHelper(currNode->right, key);
}

void BST :: inOrderTraversal(Node *temp){
  if (temp ->left != NULL){
    inOrderTraversal(temp -> left);
  }
  cout << "Identikey: " << temp -> key << endl;
  if (temp -> right != NULL){
    inOrderTraversal(temp -> right);
  }
}