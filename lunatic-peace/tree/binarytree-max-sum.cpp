/*
124. Binary Tree Maximum Path Sum
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;
//36 ms Colution
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root,maxSum);
        return maxSum;
    }

   int maxPathSumHelper(TreeNode* root, int& maxSum){
        if(!root) 
            return 0;
        int left = max(0, maxPathSumHelper(root->left, maxSum));
        int right = max(0, maxPathSumHelper(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};

// 12 ms slution

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxPathSubtree(root);
        return answer;
    }
private:
    int answer = INT_MIN;
    int maxPathSubtree(TreeNode* root) {
        if (!root) return 0;
        int l = maxPathSubtree(root->left);
        int r = maxPathSubtree(root->right);
        answer = max (answer, root->val + max(0, l) + max(0, r));
        return root->val + max(0, max(l, r));
    }
};