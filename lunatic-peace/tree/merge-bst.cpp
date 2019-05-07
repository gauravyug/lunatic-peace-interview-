#include <bits/stdc++.h>
using namespace std;  
// Structure of a BST Node 
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 

  
  
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data) 
{ 
    struct node *temp = new struct node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to print Inoder traversal of a Binary Tree */
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
  
// The function to print data of two BSTs in sorted order 
void  merge(struct node *root1, struct node *root2) 
{ 
    stack<node*> s1;// = NULL;
    struct node  *current1 = root1; 
  
    stack<node*> s2;// = NULL;
    struct node  *current2 = root2; 
  
    if (root1 == NULL) { 
        inorder(root2); 
        return; 
    } 
    if (root2 == NULL) { 
        inorder(root1); 
        return ; 
    } 
  
   while (current1 != NULL || !s1.empty() || 
          current2 != NULL || !s2.empty()) { 
        if (current1 != NULL || current2 != NULL ) { 
            if (current1 != NULL) { 
                s1.push(current1); 
                current1 = current1->left; 
            } 
            if (current2 != NULL) 
            { 
                s2.push(current2); 
                current2 = current2->left; 
            } 
        } 
        else { 
            // If we reach a NULL node and either of the stacks is empty, 
            // then one tree is exhausted, ptint the other tree 
            if (s1.empty()) 
            { 
                while (!s2.empty()) 
                { 
                    current2 = s1.top();
                    s2.pop();  
                    current2->left = NULL; 
                    inorder(current2); 
                } 
                return ; 
            } 
            if (s2.empty()) 
            { 
                while (!s1.empty()) 
                { 
                    current1 = s1.top (); 
                    s1.pop (); 
                    current1->left = NULL; 
                    inorder(current1); 
                } 
                return ; 
            } 
  
            // Pop an element from both stacks and compare the 
            // popped elements 
            current1 = s1.top();
            s1.pop();
            current2 = s2.top(); 
            s2.pop(); 
  
            // If element of first tree is smaller, then print it 
            // and push the right subtree. If the element is larger, 
            // then we push it back to the corresponding stack. 
            if (current1->data < current2->data) 
            { 
                printf("%d ", current1->data); 
                current1 = current1->right; 
                s2.push(current2); 
                current2 = NULL; 
            } 
            else
            { 
                printf("%d ", current2->data); 
                current2 = current2->right; 
                s1.push(current1); 
                current1 = NULL; 
            } 
        } 
    } 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    struct node  *root1 = NULL, *root2 = NULL; 
  
    /* Let us create the following tree as first tree 
            3 
          /  \ 
         1    5 
     */
    root1 = newNode(3); 
    root1->left = newNode(1); 
    root1->right = newNode(5); 
  
    /* Let us create the following tree as second tree 
            4 
          /  \ 
         2    6 
     */
    root2 = newNode(4); 
    root2->left = newNode(2); 
    root2->right = newNode(6); 
  
    // Print sorted nodes of both trees 
    merge(root1, root2); 
  
    return 0; 
} 