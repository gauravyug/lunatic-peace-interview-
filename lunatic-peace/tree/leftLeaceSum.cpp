/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !node->left->left && !node->left->right) {
                    sum += node->left->val;
            } 
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }   
        } 
        return sum;
    }
};