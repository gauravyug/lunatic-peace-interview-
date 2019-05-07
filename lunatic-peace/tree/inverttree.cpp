/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
class InvertTree {
public:
/*
    Recursive Solution:
    recursive traverse right and left subtree and alter root->left = right, rooot->right = left;
*/
    TreeNode* invertTreeRecursive(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode *right = invertTreeRecursive(root->right);
        TreeNode *left = invertTreeRecursive(root->left);
        root->left = right;
        root->right = left;
        return root;
    }
 /*
    Iterative Solution:
    Take a queue and add root in the queue.
    while queue us not empty
    pop from queue and and alter current nodes left and right
 */ 

    TreeNode* invertTreeIterative(TreeNode* root) {
        if (root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *current = q.front();
            q.pop();
            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;
            
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
            
        }
        return root;
    }
};