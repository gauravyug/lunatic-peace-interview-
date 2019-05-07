// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root) {
        /* Iterative approach..*/
       stack<TreeNode*>s;
        TreeNode* pre = NULL;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre && root->val <= pre->val) 
                return false;
            pre = root;
            root = root->right;
        }
        return true;
}
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
bool isBST(struct Node* root);
/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(10);
    root->left        = newNode(6);
    root->right       = newNode(14);
    root->left->left  = newNode(4);
    root->left->right = newNode(8);
 
    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}
bool isBST(struct Node* root )
{
    static int prev = INT_MIN;
   printf("Iprev val is %d\n",prev); 
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (root->data < prev )
          return false;
 
        prev = root->data;
 
        return isBST(root->right);
    }
 
    return true;
}
