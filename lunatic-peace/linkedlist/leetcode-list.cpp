class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ReverseList {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(!head) 
           return NULL;
        ListNode *cur = head, *prev = NULL, *tmp = NULL;
        ListNode* next = head;
        for(int i = 0; i < k; i++){ // Find next pointer after k
            if(!next) 
                return head;
            next = next->next;
        }
     
        while(cur != next){ // while curr is not equals to next, reverse the nodes
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};



#include<stdio.h>
int main()
{
    int t,n;
    long i,b,ctr1;
    scanf("%d",&t);
    while(t--)
    {
        ctr1=0;
        scanf("%d %ld",&n,&b);
        for(i=1;i<=n;i++)
        {
            if((ctr1 + i)!= b)
            {
                ctr1=ctr1+i;
            }
            else
            if((ctr1 + i)== b && b!=1)
            {
                ctr1=ctr1-(i-1);
                ctr1=ctr1+i;
            }
        }
        printf("%ld\n",ctr1);
    }
    return 0;
}
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size=0;
    Node* head=new Node(0);
    MyLinkedList() {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) 
            return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) 
            temp=temp->next;
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) 
            return;
        Node* temp = head;
        for(int i=0;i<index;i++) 
            temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp1;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size) 
            return;
        Node* temp = head;
        for(int i = 0;i < index;i++) 
            temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
};