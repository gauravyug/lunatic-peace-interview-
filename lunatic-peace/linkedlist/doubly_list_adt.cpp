  
#include <iostream>
#include <stdexcept> 
#include "doubly_list_adt.h"
using namespace std;

/*
    Constructor for Node class
*/
DNode::DNode(int value)
{
    this->data = value;
    this->next = NULL;
    this->prev = NULL;
}

/*
    Constructor for LinkedList Class
*/
DoublyLinkedList::DoublyLinkedList()
{
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

/*
    Destructor for LinkedList class
*/
DoublyLinkedList::~DoublyLinkedList()
{
   /* Node *next_node=NULL; 
    for (Node *node_ptr=this->head; node_ptr != NULL; node_ptr=next_node) { 
        next_node = node_ptr->next;
        delete node_ptr; 
    }*/
}

/*
    Returns curret size of linkedList
*/
int DoublyLinkedList::size() const
{
    return (this->length);
}

bool DoublyLinkedList::empty() const
{
    return (this->length == 0);
} 

/*  
    Prints content of Linked List
*/
void  DoublyLinkedList::print() const
{
    DNode *curr = this->head;
    if (empty())
        throw out_of_range("Empty List");
     
    while (curr != NULL) { 
        cout << curr->data << endl;
        curr = curr->next;
    }  
}

int& DoublyLinkedList::at(int index)
{
    if(index < 0 || index >= this->length) {
        throw out_of_range("index out of bounds"); }
    DNode *node_ptr; 
    for (node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next, index--) { 
        if (index == 0) {
            break;
        }
        //index--;
    }
    return node_ptr->data; 
}

/*
    Find the node with given value
*/
DNode* DoublyLinkedList::find(int value) const {
    DNode *node_ptr; 
    for (node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next) {
        if (value == node_ptr->data)
            return node_ptr;
    }
    return NULL;
}
 
bool DoublyLinkedList::contains(int value) const{
    DNode* node_ptr = find(value); 
    return node_ptr != NULL;
}

/*
    Add a node at last in list
*/
void DoublyLinkedList::append(int value) {
    DNode *new_node = NULL;
    if (this->length == 0) {
        new_node = new DNode(value);
        this->head = this->tail = new_node;
    }
    else {
        DNode *last_node = this->tail;
        new_node = new DNode(value);
        last_node->next = new_node;
        new_node->prev = last_node;
        this->tail = new_node;
    }
    this->length++;
}

/*
    Add a node in list from head
*/
void DoublyLinkedList::prepend(int value) {
        DNode *new_node = new DNode(value);;
        DNode *first_node = this->head;
        new_node->next = first_node;
        first_node->prev = new_node;
        this->head = new_node;
        this->length++;
}

/*
    Remove target node from linked list
*/
void DoublyLinkedList::remove(DNode* target_node_ptr) {
    DNode* prev_ptr=NULL; 
    DNode *node_ptr; 
    DNode *next_ptr; 
    for (node_ptr = this->head; node_ptr != NULL && node_ptr != target_node_ptr; node_ptr = node_ptr->next) {
        prev_ptr = node_ptr; 
    }
    if (node_ptr == NULL) { 
        throw target_node_ptr; 
    } 
    else if (prev_ptr == NULL) { 
        this->head = node_ptr->next; 
        this->head->prev = NULL;
        delete target_node_ptr;
    } 
    else {
        next_ptr = target_node_ptr->next;
        prev_ptr->next = target_node_ptr->next;
        next_ptr->prev = prev_ptr;  
        delete target_node_ptr; 
    }
    this->length--;
}

/*
    Erase node at index from List
*/
void DoublyLinkedList::erase(int index){
    if (index < 0 || index >= this->length)
        throw  out_of_range ("index out of bounds");
    DNode *prev_ptr = NULL;
    DNode *node_ptr; 
    DNode *next_ptr; 
    for (node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next) {
        if (index == 0)
            break;
        index--;
        prev_ptr = node_ptr; 
    } 
    if (prev_ptr == NULL) {
        this->head = node_ptr->next;
        this->head->prev = NULL;
        delete node_ptr;
    }
    else {
        next_ptr = node_ptr->next;
        prev_ptr->next = node_ptr->next;
        next_ptr->prev = prev_ptr;  
        delete node_ptr;
    }
    this->length--;
}

void DoublyLinkedList::moveToHead(DNode *node)
{
    if (this->head == node)
        return;
    node->prev->next = node->next;

    if (node->next != NULL){
        node->next->prev = node->prev;
    } else {
        this->tail = node->prev;
    }
    node->next = head;
    node->prev = NULL;
    this->head->prev = node;
    this->head = node;

}

void DoublyLinkedList::removeTail()
{
    this->length--;
    if (this->head == this->tail) {
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    } else {
        DNode* del = this->tail;
        this->tail = del->prev;
        this->tail->next = NULL;
        delete del;
    }
}

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    cout << "Empty = " << boolalpha << list->empty() << endl;
    for(int i=0; i < 6; i++) {
        list->append(i);
        cout << "List size = " << list->size() << endl;
        list->print();
    }
    for(int j=11; j > 6; j--) {
        list->prepend(j);
        cout << "List size = " << list->size() << endl;
        list->print();
    }
    cout << "Empty = " << boolalpha << list->empty() << endl;
    cout << "list->at(5) = " << list->at(5) << endl;
    cout << "list->at(1) = " << list->at(1) << endl;
    cout << "contains(55) = " << list->contains(55) << endl;
    cout << "contains(4) = " << list->contains(4) << endl;
    cout << "Eraising 0  from list i\n" ;
    list->erase(0) ;
    cout << "Print contents: " << endl;
    list->print();
    cout << "Eraising 5  from list " << endl;
    list->erase(5);
    list->print();
}