/* C code version of the great Tree-List recursion problem.
 See http://cslibrary.stanford.edu/109/ for the full
 discussion and the Java solution.
 
 This code is free for any purpose.
 Feb 22, 2000
 Nick Parlante nick.parlante@cs.stanford.edu
*/
 
#include<bits/stdc++.h> 
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;
/* The node type from which both the tree and list are built */
struct node {
    int data;
    struct node* small;
    struct node* large;
};
typedef struct node* Node;

struct nodewithhd
{
    nodewithhd * left;
    nodewithhd* right;
    int data;
    int hd;
    
};

/* Create a new node with hd */
nodewithhd* newNodeWithHd(int x)
{
    nodewithhd* temp=new nodewithhd();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    temp->hd = INT_MIN;

    return temp;
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
void preorder(Node root)
{
        printf("Preorder Traversal using stack:\n");
        stack <Node> stk;
        while (1) {
                while (root) {
                        printf("%d\t",root->data);
                        stk.push(root);
                        root = root->small;
                }
                if (stk.empty())
                        break;
                root = stk.top();
                stk.pop();
                root = root->large;
        }

        printf("\n");
} 
void inorder(Node root)
{     
        printf("Inorder Traversal using stack:\n");
        stack <Node> stk;
        while (1) {
                while (root) {
                        stk.push(root);
                        root = root->small;
                }                                                                                                                                                                                                  
                if (stk.empty())
                        break;
                root = stk.top();
                stk.pop();
                printf("%d\t",root->data);
                root = root->large;
        }
      
        printf("\n");
}     
   
void postorder(Node root)
{        
        printf("Postorder Traversal using stack:\n");
        stack <Node> stk;
        while (1) {
                if (root) {
                        stk.push(root);
                        root = root->small;
                }
                else {
                        if (stk.empty()){
                                printf("Stack is empty: \n");
                                return;
                        }
                        else {
                                if (stk.top()->large == NULL) {
                                        root = stk.top();
                                        stk.pop();
                                        printf ("%d\t", root->data);
                                        if (root == stk.top()->large) {
                                                printf ("%d\t", stk.top()->data);
                                                stk.pop();
                                        }
                                }
                        }
                        if (!stk.empty()) {
                                root = stk.top()->large;
                        }
                        else {
                                root = NULL;
                        }
                }
        }
         
        printf("\n");
}

void rightViewIterative(Node root)
{
        printf("Right View Iterative using Queue:\n");
        if(root==NULL)
                return;
        queue<Node>q; 
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(q.front()==NULL && root)
                    cout<<root->data<<" ";
            if(root==NULL && !q.empty()) {
                    q.push(NULL);
            }
            else if(root) {
                if(root->small)
                        q.push(root->small);
                if(root->large)
                        q.push(root->large);
                }
        } 
        printf("\n");
}

void topViewIterative(Node root)
{
        printf("Top View Iterative using Queue:\n");
        if(root==NULL)
                return;
        queue<Node>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(q.front()==NULL && root)
                    cout<<root->data<<" ";
            if(root==NULL && !q.empty()) {
                    q.push(NULL);
            }
            else if(root) {
                if(root->small)
                        q.push(root->small);
                if(root->large)
                        q.push(root->large);
                }
        }
        printf("\n");
}

void leftViewIterative(Node root)
{
        printf("Left View Iterative using Queue:\n");
        if(root==NULL)
                return;
        queue<Node>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            if(q.front()==NULL && root)
                    cout<<root->data<<" ";
            if(root==NULL && !q.empty()) {
                    q.push(NULL);
            }
            else if(root) {
                if(root->large)
                        q.push(root->large);
                if(root->small)
                        q.push(root->small);
                }
        }
        printf("\n");
}

void rightLeaveSum(Node root)
{                                                                                                                                                                                                                  
    printf("Right Leave Sum using Queue:\n");
    if (root == NULL)  
        return;

    queue<Node> q;
    int sum = 0;                   
    q.push(root);      
    while(!q.empty())  
    {                  
        Node temp = q.front();
        q.pop();       
        if(temp->large){
                if (!temp->large->small && !temp->large->large)
                        sum = sum + temp->large->data;
        }              
        if(temp->small){
            q.push(temp->small);
        }              
        if(temp->large){
            q.push(temp->large);
        }              
    }                  
                       
        cout << "Sum of right leaves nodes is :" << sum << " ";
        printf("\n");  
}                      
  
void leftLeaveSum(Node root)                  
{                                              
    printf("Left Leave Sum using Queue:\n");  
    if (root == NULL)                          
        return;                                
                                               
    queue<Node> q;                             
    int sum = 0;                               
    q.push(root);                              
    while(!q.empty())                          
    {                                          
        Node temp = q.front();                 
        q.pop();                               
        if(temp->small){                       
                if (!temp->small->large && !temp->small->small)
                        sum = sum + temp->small->data;                                                                                                                                                             
        }                                      
        if(temp->small){                       
            q.push(temp->small);               
        }                                      
        if(temp->large){                       
            q.push(temp->large);               
        }                                      
    }                                          
                                               
        cout << "Sum of Left leaves nodes is :" << sum << " ";
        printf("\n");                          
} 

void printleafnodes(Node root)                  
{                                              
    printf("Leaf Nodes from Left to Right  using Queue:\n");  
    if (root == NULL)                          
        return;                                
                                               
    queue<Node> q;                             
    q.push(root);                              
    while(!q.empty())                          
    {                                          
        Node temp = q.front();                 
        q.pop();                               
        if (!temp->small && !temp->large)
                cout << temp->data << " " ; 
        if(temp->small){                       
            q.push(temp->small);               
        }                                      
        if(temp->large){                       
            q.push(temp->large);               
        }                                      
    }                                          
                                               
        printf("\n");                          
}                       
  

void bottomView(nodewithhd *root)
{
        printf("Bottom View Iterative using Queue:\n");
    if (root == NULL)
        return;
    int hd = 0;
    map <int, int> m;
    queue<nodewithhd*> q;

    q.push(root);
    root->hd = hd;
    while(!q.empty())
    {
        nodewithhd *temp = q.front();
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;
        if(temp->left !=NULL){
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if(temp->right !=NULL){
            temp->right->hd = hd + 1;
            q.push(temp->right);

        }
    }

    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
        printf("\n");
}

void topView(nodewithhd *root)
{
        printf("Top View Iterative using Queue:\n");
    if (root == NULL)
        return;
    int hd = 0;
    map <int, int> m;
    queue<nodewithhd*> q;

    q.push(root);
    root->hd = hd;
    while(!q.empty())
    {
        nodewithhd *temp = q.front();
        q.pop();
        hd = temp->hd;
        /* Put the dequeued tree node to TreeMap
	   having key as horizontal distance. Every
	   time we find a node having same horizontal
	   distance we need to replace the data in
	   the map.*/

        if (m.find(hd) == m.end()) {
                m[hd] = temp->data;
                cout << temp->data <<" " ;
                
        }
        if(temp->left !=NULL){
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if(temp->right !=NULL){
            temp->right->hd = hd + 1;
            q.push(temp->right);

        }
    }
        printf("\n");
}
int treeWithHd()
{
   /*
    *           20
    *         /    \
    *       8       22
    *      / \     /  \
    *     5   3   4    25 
    *        / \
    *      10  14
    *
    * */
    struct nodewithhd *root = newNodeWithHd(20);
    root->left = newNodeWithHd(8);
    root->right = newNodeWithHd(22);
    root->left->left = newNodeWithHd(5);
    root->left->right = newNodeWithHd(3);
    root->right->left = newNodeWithHd(4);
    root->right->right = newNodeWithHd(25);
    root->right->right = newNodeWithHd(21);
    root->left->right->left = newNodeWithHd(10);
    root->left->right->right = newNodeWithHd(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    topView(root);
    return 0;
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
    treeInsert(&root, 9);
    treeInsert(&root, 16);
 
    preorder(root);
    inorder(root);
 //   postorder(root);
    rightViewIterative(root);
    leftViewIterative(root);
    rightLeaveSum(root);
     leftLeaveSum(root);
    printleafnodes(root); 
    treeWithHd();
    //printList(head);    /* prints: 1 2 3 4 5  */
 
    return(0);
}

