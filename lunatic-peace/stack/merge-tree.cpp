#include <bits/stdc++.h>
using namespace std;
/*Structure of each node in the tree*/
struct node
{
   int data;
   node *left;
   node *right;
};
/*This function is used to create and
initialise new nodes*/
node *newNode(int key)
{
   node *temp=new node;
   temp->left=NULL;
   temp->right=NULL;
   temp->data=key;
   return temp;
}
/*This funciton is used to Insert
 new values in BST*/
node *Insert(node *root,int key)
{
   if(!root)
      return newNode(key);
   if(key<root->data)   
      root->left=Insert(root->left,key);
   else
      root->right=Insert(root->right,key);
   return root;
}
/*This function is used to
print Inorder traversal*/
void Inorder(node *root)
{
   if(!root)
      return;
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);
}
/* The function to print data of two BSTs in sorted order*/
void  merge( node *root1,  node *root2)
{
    /* s1 and s2 are stacks to hold elements of
    first and second BST respectively*/
     stack<node *> s1,s2;
 
    /* Current node of first BST*/
     node  *current1 = root1;
    /* Current node of second BST*/
     node  *current2 = root2;
 
    /* If first BST is empty, then print second BST*/
    if (root1 == NULL)
    {
        Inorder(root2);
        return;
    }
    /* If second BST is empty, then print first BST*/
    if (root2 == NULL)
    {
        Inorder(root1);
        return ;
    }
 
    /* while elements are not printed*/
    while (current1 != NULL || !s1.empty() 
    || current2 != NULL || !s2.empty())
    {
        if (current1 != NULL || current2 != NULL )
        {
            if (current1 != NULL)
            {
                s1.push(current1);
                current1 = current1->left;
            }
            
            if (current2 != NULL)
            {
                s2.push(current2);
                current2 = current2->left;
            }
 
        }
        else
        {
            /*If either tree is empty*/
            if (s1.empty())
            {
                while (!s2.empty())
                {
                    current2 = s2.top();
                    s2.pop();
                    current2->left = NULL;
                    Inorder(current2);
                }
                return ;
            }
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    current1 = s1.top();
                    s1.pop();
                    current1->left = NULL;
                    Inorder(current1);
                }
                return ;
            }
 
            /* Pop an element from both stacks and compare the
             popped elements*/
            current1 = s1.top();
            s1.pop();
            current2 = s2.top();
            s2.pop();
 
            if (current1->data < current2->data)
            {
                cout<< current1->data<<" ";
                current1 = current1->right;
                s2.push(current2);
                current2 = NULL;
            }
            else
            {
                cout<<current2->data<<" ";
                current2 = current2->right;
                s1.push(current1);
                current1 = NULL;
            }
        }
    }
}
int main() {
   /* Let us create first BST
              4
            /   \
           1     6*/
    node *root1 = NULL;
    root1 = Insert(root1, 4);
    Insert(root1, 1);
    Insert(root1, 6);
    
   /* Let us create second BST
              3
            /   \
           2     5*/
    node *root2 = NULL;
    root2 = Insert(root2, 3);
    Insert(root2, 2);
    Insert(root2, 5);
    
   merge(root1, root2);
   return 0;
}