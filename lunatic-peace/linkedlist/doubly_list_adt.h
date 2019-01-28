/*  
    @Gaurav YadavCS-11 Asn 2, linkedlist_adt.h
    Purpose: Implements DoublyLinkedlist class

    @author Gaurav Yadav
    @email gauravyug@gmai.com
    @version 1.1 
    @date 13-Oct-18 
*/

#ifndef ADT_DOUBLY_LINKEDLIST_H_
#define ADT_DOUBLY_LINKEDLIST_H_

/*
    Linked List Node
*/
class DNode
{
    public:
        int data;
        DNode* next;
        DNode* prev;
    public:
        DNode(int value);
};

class DoublyLinkedList
{
    private:
    DNode* head;
    DNode* tail;
    int length;
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int size() const;
    bool empty() const;
    void print() const;
    int& at(int index);
    DNode* find(int value) const;
    bool contains(int value) const;
    void append(int value);
    void prepend(int value);
    void remove(DNode* node_ptr); 
    void erase(int index);
    void moveToHead(DNode* node);
};
#endif