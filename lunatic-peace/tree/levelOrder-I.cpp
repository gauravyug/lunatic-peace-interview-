#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void levelOrder(TreeNode* root) {
    vector<int> res;
    if(root == NULL) // If tree is NULL return
        return ;
    queue<TreeNode*> cur;
    cur.push(root); // Push current Node in Queue
    cur.push(NULL);
    while(!cur.empty()) { 
        /* 
            * While queue is not empty, pop element from queue and push current node
            * in vector, check for node->left and node->right, if not NULL push to the queue.
        */
            TreeNode* node = cur.front();
            if (node == NULL) {
                if (cur.empty())
                    break;
                res.push_back(-1);
                continue;
            }
            res.push_back(node->val);
            cur.pop();
            if(node->left) cur.push(node->left);
            if(node->right) cur.push(node->right);
        }
        for(auto t=res.begin(); t!=res.end(); ++t)
	        std::cout << *t << '\n'; 
        //cur = next
}
        
int main()
{
  
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2); 
	root->right = new TreeNode(3); 
	root->left->left = new TreeNode(7); 
	root->left->right = new TreeNode(8); 
	root->right->right = new TreeNode(15); 
	root->right->left = new TreeNode(12); 
	root->right->right->left = new TreeNode(14);
    levelOrder(root);
}