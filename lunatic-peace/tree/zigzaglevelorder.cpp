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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) 
            return res;
        queue<TreeNode*> cur;
        cur.push(root);

        int switch_order = 0;
        while(!cur.empty()) {
            vector<int> v;
            queue<TreeNode*> next;
            while(!cur.empty()) {
                TreeNode* node = cur.front();
                v.push_back(node->val);
                cur.pop();
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            if(switch_order) 
                reverse(v.begin(), v.end());
            switch_order = 1 - switch_order;
            res.push_back(v);
            cur = next;
        }

        return res;
        }
    
};
