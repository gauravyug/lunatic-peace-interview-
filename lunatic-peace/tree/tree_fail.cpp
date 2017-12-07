// C program for iterative postorder traversal using one stack
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node
struct Node
{
	int data;
	struct Node *left, *right;
};
 
 
 
// A utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
 
 
 
 
 
// An iterative function to do postorder traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
	// Check for empty tree
	if (root == NULL)
		return;
	//Algorithm : 
	/*
 
	if current node has left and right child, push the children in right followed by left 
	and mark the current node as visited using a map stl
	if the current node is already visited then print the node data
	and remove the current node from stack.
 
	*/
	stack<Node*> s;
	map<int,bool> m;
	s.push(root);
	while(!s.empty()){
	    Node* curr=s.top();
	    if(!m[curr->data]){
	        if(curr->right!=NULL){
	            s.push(curr->right);
	        }
	        if(curr->left){
	            s.push(curr->left);
	        }
	        m[curr->data]=1;
	    }
	    else{
	        cout<<curr->data<<" ";
	        s.pop();
	    }
	}
}
 
// Driver program to test above functions
int main()
{
	// Let us construct the tree shown in above figure
	struct Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("Post order traversal of binary tree is :\n");
	printf("[");
	postOrderIterative(root);
	printf("]");
 
 
	return 0;
}
