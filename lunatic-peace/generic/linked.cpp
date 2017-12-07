#include <stdio.h>


/* Linked list node */
struct Node
{
    int data;
    Node* next;
};
// A utility function to print a linked list
void printList(Node *node);
Node* addOne(Node* head) ;
/* Function to create a new node with given data */
Node *createNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add1tolist()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(9);
    head->next->next->next = createNode(9);
     head->next->next->next->next = createNode(9);
   // Insert(head, 15);
    
    printf("List is ");
    printList(head);
    
    head = addOne(head);
    
    printf("\nResultant list is ");
    printList(head);
}

// A utility function to print a linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* addOne(Node* head)
{
    Node* first_non_9 = NULL;
    Node* cur = head;
    while(cur)
    {
        if(cur->data != 9)
            first_non_9 = cur;
        cur = cur->next;
    }
    Node* newHead = head;
    if(first_non_9 == NULL)
    {
        newHead = createNode(1);
        newHead->next = head;
    }
    else
    {
        first_non_9->data++;
    }
   cur = first_non_9 ? first_non_9->next : head;
    while(cur)	
    {
        cur->data = 0;
        cur = cur->next;
    }
    return newHead;
}

int main()
{
        add1tolist();
        return 0;
}
