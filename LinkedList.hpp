/*
    This is a header file for a linked list.
*/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct LL
{
    /* data */
    int key;
    LL* next;
};

class LinkedList
{
private:
    LL* head;
public:
    LinkedList();
    ~LinkedList();
    void addNode(int);
    void printLL();
    LL* searchLL(int);
};

#endif


