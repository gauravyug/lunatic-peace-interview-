/*
 TreeList.c
 
 C code version of the great Tree-List recursion problem.
 See http://cslibrary.stanford.edu/109/ for the full
 discussion and the Java solution.
 
 This code is free for any purpose.
 Feb 22, 2000
 Nick Parlante nick.parlante@cs.stanford.edu
*/


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* The node type from which both the tree and list are built */
struct node {
    int data;
    struct node* small;
    struct node* large;
};
typedef struct node* Node;

void printList(Node head); 

/*
 helper function -- given two list nodes, join them
 together so the second immediately follow the first.
 Sets the .next of the first and the .previous of the second.
*/
void join(Node a, Node b) {
    a->large = b;
    b->small = a;
}


/*
 helper function -- given two circular doubly linked
 lists, append them and return the new list.
*/
 Node append(Node a, Node b) {
    Node aLast, bLast;
    
    if (a==NULL) return(b);
    if (b==NULL) return(a);
    
    aLast = a->small;
    bLast = b->small;
    
    join(aLast, b);
    join(bLast, a);
    
    return(a);
}


/*
 --Recursion--
 Given an ordered binary tree, recursively change it into
 a circular doubly linked list which is returned.
*/
Node treeToList(Node root) {
    Node aList, bList;
   static int i = 0; 
   if (root !=NULL)
           printf("GAURAV : %d \n",root->data);
    if (root==NULL) return(NULL);

    /* recursively solve subtrees -- leap of faith! */
    aList = treeToList(root->small);
    bList = treeToList(root->large);
    
    /* Make a length-1 list ouf of the root */
    root->small = root;
    root->large = root;

    /* Append everything together in sorted order */
    printf("before appending :\n");
    printList(bList);
    aList = append(aList, root);
    aList = append(aList, bList);
    printf("Iteration :%d\n",i++);    
    printList(aList);
    printList(bList);
    return(aList);

}

/* Create a new node */
Node newNode(int data) {
    Node node = (Node) malloc(sizeof(struct node));
    node->data = data;
    node->small = NULL;
    node->large = NULL;
    return(node);
}


/* Add a new node into a tree */
void treeInsert(Node* rootRef, int data) {
    Node root = *rootRef;
    if (root == NULL) *rootRef = newNode(data);
    else {
        if (data <= root->data) treeInsert(&(root->small), data);
        else treeInsert(&(root->large), data);
    }
}


 void printList(Node head) {
    Node current = head;
    
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->large;
        if (current == head) break;
    }
    printf("\n");
}


/* Demo that the code works */
int main() {
    Node root = NULL;
    Node head;
/*
 *              4
 *          2         5
 *      1      3 
 * */    
    treeInsert(&root, 10);
    treeInsert(&root, 6);
    treeInsert(&root, 4);
    treeInsert(&root, 8);
    treeInsert(&root, 14);
    treeInsert(&root, 12);
    treeInsert(&root, 16);
    
    head = treeToList(root);
    
    printList(head);    /* prints: 1 2 3 4 5  */
    
    return(0);
}

