/*  
    @Gaurav YadavCS-11 Asn 2, linkedlist_adt.h
    Purpose: Implements Queue class

    @author Gaurav Yadav
    @email gauravyug@gmai.com
    @version 1.1 
    @date 13-Oct-18 
*/

#ifndef ADT_QUEUE_H_
#define ADT_QUEUE_H_

/*
    Linked List Node
*/
class QNode
{
    public:
        int data;
        QNode* next;
    public:
        QNode(int value);
};

class Queue
{
    private:
        QNode *front;
        QNode *rear;
        int length;
    public:
        Queue();
        ~Queue();
        int size() const;
        void push(int value); //enqueue
        void pop(); //dequeue
        QNode* head();
        QNode* tail();
        bool empty() const;
        
};

#endif