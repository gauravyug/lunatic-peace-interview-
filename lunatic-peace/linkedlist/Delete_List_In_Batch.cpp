#include<bits/stdc++.h>
/*  Delete nodes in batches
    One list which have millions of nodes and you are asked to delete
    nodes in batches. Thats means say batch request is 5 and nodes to be deleted is 3.
    So we have to delete 3 nodes in every batch
    Ex.
    Input:
        1->2->3->4->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19->NULL
    Output: 
        4->5->9->10->14->15->19->20->NULL

*/
using namespace std;
using namespace std::chrono;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

void delete_list_in_batch(ListNode **head, int batch, int kill) {
    ListNode *curr = *head;
    int m = batch;
    int n = kill;
    ListNode *prev = NULL;
    while (curr && curr->next && n > 0) { // delete first batch of nodes
        ListNode *temp = NULL;
        temp = curr;
        curr = curr->next;
        delete temp;
        *head = curr;
        n--;
    }
    int diff = batch - kill;
    m--;
    while (diff > 0) { // move current pointer to next batch.
        prev = curr;
        curr = curr->next;
        diff--;
    } 
    while (m > 0 && curr && curr->next) {
        n = kill;
        while (curr && n > 0) {
            ListNode *temp = NULL;
            temp = curr;
            if (prev)
                prev->next = curr->next;
            curr = curr->next;
            if (!prev)
                *head = curr;
            delete temp;
            n--;
        }
        diff = batch - kill;
        while (diff > 0 && curr) {
            prev = curr;
            curr = curr->next;
            diff--;
        }
        m--;
    }
    if (n > 0 && curr) {// Partial batch nodes.
        if (prev)
            prev->next = NULL;
        delete curr;
    }
    if (!prev )
        *head = NULL;
}

void print_list(ListNode *head) {
    if (!head) {
        cout << "Empty List";
    }
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
}

int append(ListNode **head_ref, int value)
{
    ListNode *node = new ListNode(value);
    ListNode *end = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = node;
    } else {
        while (end->next != NULL) {
            end = end->next;
        }
        end->next = node;
    }
}

int main()
{
    ListNode *head = NULL;
    for (int i = 1; i < 100001; i++) {
        append(&head, i);
    }
    print_list(head);
    //auto start = high_resolution_clock::now(); 
    clock_t startTime = clock();
    cout << "\n";
    delete_list_in_batch(&head, 1005,30);
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;    
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start); 
  
    //print_list(head); 
    return 0;
}