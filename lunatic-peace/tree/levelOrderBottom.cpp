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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) 
            return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL); //Marker to track level in tree
        vector<int> temp_vec;
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == NULL) {
                if (q.empty()) 
                    break;
                q.push(NULL);// add next level marker once current level is processed
                res.insert(res.begin(), temp_vec);
                temp_vec.clear();
                continue;
            }
            temp_vec.push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);

        }
        res.insert(res.begin(), temp_vec);
        return res;
        
    }
};
