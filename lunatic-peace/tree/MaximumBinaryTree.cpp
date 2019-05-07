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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        int max_idx = get_max_index(nums);
        TreeNode* root = new TreeNode(nums[max_idx]);
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < nums.size(); i++){
            if(i == max_idx)
                continue;
            if(i < max_idx)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;      
    }
                               
    int get_max_index(vector<int> vec) {
       int max = INT_MIN;
        int idx = 0;
        for (int i = 0; i < vec.size(); i++) {
             cout << max;
            if (max < vec[i]) {
               
                idx = i;
                max = vec[i];
            }
        }
        return idx;
    }
};