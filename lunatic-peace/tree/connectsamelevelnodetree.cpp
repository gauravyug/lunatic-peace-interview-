#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue> 

using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *nextRight;
};
 
/* This function returns the leftmost child of nodes at the same level as p.
   This function is used to getNExt right of p's right child
   If right child of is NULL then this can also be sued for the left child */
struct node *getNextRight(struct node *p)
{
    struct node *temp = p->nextRight;
 
    /* Traverse nodes at p's level and find and return
       the first node's first child */
    while (temp != NULL)
    {
        if (temp->left != NULL)
            return temp->left;
        if (temp->right != NULL)
            return temp->right;
        temp = temp->nextRight;
    }
 
    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}
 
/* Sets nextRight of all nodes of a tree with root as p */
void connect(struct node* p)
{
    struct node *temp;
 
    if (!p)
      return;
   queue <node*> q; 
   q.push(p);
        q.push(NULL);   
    // Set nextRight for root
    p->nextRight = NULL;
 
    // set nextRight of all levels one by one
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp!=NULL) {
                temp->nextRight = q.front();
                if (temp->left)
                        q.push(temp->left);
                if (temp->right)
                        q.push(temp->right);
        }
        else if (!q.empty())
                q.push(NULL);
 
    }
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->nextRight = NULL;
 
    return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->left->right        = newnode(11);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->right->right       = newnode(90);
 
    // Populates nextRight pointer in all nodes
    connect(root);
 
    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight? root->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight? root->left->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->right->data,
           root->left->right->nextRight? root->left->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight? root->right->right->nextRight->data: -1);
 
    getchar();
    return 0;
}
