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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) // If tree is NULL return
            return res;
        queue<TreeNode*> cur;
        cur.push(root); // Push current Node in Queue

        while(!cur.empty()) { 
            /* 
             * While queue is not empty, pop element from queue and push current node
             * in vector, check for node->left and node->right, if not NULL push to the queue.
            */
            vector<int> v;
            queue<TreeNode*> next;
            while(!cur.empty()) {
                TreeNode* node = cur.front();
                v.push_back(node->val);
                cur.pop();
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            res.push_back(v);
            cur = next;
        }

        return res;
        }
        
    };
