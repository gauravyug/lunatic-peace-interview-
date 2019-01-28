#include <iostream>
#include <stdexcept> 
#include "queue_adt.h"
using namespace std;


/*
    Constructor for QNode class
*/
QNode::QNode(int value)
{
    this->data = value;
    this->next = NULL;
}

Queue::Queue()
{
    this->length = 0;
    this->front = NULL;
    this->rear = NULL; 
}
Queue::~Queue()
{
    
}

bool Queue::empty() const
{
   return(this->length == 0);
}

void Queue::push(int value)
{
    QNode *new_node = new QNode(value);
    if (this->length != 0) {
        this->rear->next = new_node;
        this->rear = new_node;
    }
    else {
        this->front =  new_node;
        this->rear = new_node;
    }
    this->length++;
}

void Queue::pop()
{
	if (this->front == NULL)
	{
		cout << " Queue is Empty. " << endl;
	}
	else
	{
		QNode *temp = this->front;
		this->front = this->front->next;
		cout << endl << temp->data<< " was dequeued." << endl;
		delete temp;
	}
    this->length--;
}

QNode* Queue::head()
{
    if (this->front != NULL) {
            return this->front;
     }
    else
        throw out_of_range("index out of bounds");  
}


QNode* Queue::tail()
{
    if (this->rear != NULL) {
         return this->rear;
     }
    else
        throw out_of_range("index out of bounds");  
}
int Queue::size() const
{
    return(this->length);
}

int main()
{
    Queue* queue = new Queue();
    cout << "Empty = " << boolalpha << queue->empty() << endl;
    for(int i=0; i < 6; i++) {
        queue->push(i);
        cout << "Queue size = " << queue->size() << endl;
     }

     for(int i=0; i < 4; i++) {
        queue->pop();
        cout << "Queue front = " << queue->head()->data << " Queue rear = " << queue->tail()->data << endl;
        cout << "Queue size = " << queue->size() << endl;
        cout << "Queue front = " << queue->head()->data << " Queue rear = " << queue->tail()->data << endl;
     }
}
