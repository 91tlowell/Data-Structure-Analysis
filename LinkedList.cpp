#include <iostream>
#include "LinkedList.hpp"

using namespace std;

LinkedList :: LinkedList(){
    head = NULL;
}

LinkedList :: ~LinkedList(){
    LL* temp = head;
    LL* prev = temp;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
}

void LinkedList :: addNode(int key){
    if (head == NULL){
        head = new LL;
        head -> key = key;
        head -> next = NULL;
    }
    else{
        LL* newNode = new LL;
        newNode->key = key;
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList :: printLL(){
    if (head == NULL){
        cout << "List is empty. Make sure you entered the keys correctly." << endl;
    }

    else{
        LL* temp = head;
        cout << "==========Identikey value starting from head of list.===========" << endl;
        while(temp->next != NULL){
            cout << temp->key << " -> ";
            temp = temp -> next;
        }
        cout<< temp -> key << " -> NULL" << endl;
        cout << "===" << endl;
    }
}

LL* LinkedList :: searchLL(int key){
    LL* temp = head;
    while (temp != NULL && temp->key != key)
    {
        temp = temp->next;
    }
    return temp;
}