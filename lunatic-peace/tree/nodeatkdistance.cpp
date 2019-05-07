/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    Algorithm:
    1. Find left distance
    2.   
*/
class Solution {
public:
     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> solution;
        getDistanceToTarget(root, target, K, solution);
        return solution;
    }
    
    /* return distance left to be searched, -1 if target not in this subtree */
    int getDistanceToTarget(TreeNode* root, TreeNode* target, int K, vector<int>& solution) {
        if (!root)  // Base case..
            return -1;
        if (root == target) {// If root == target node, problem reduce to node at k distance from node. 
            emplaceDepthKNodes(root, solution, K);
            return 0;
        } else {
            int leftDistance = getDistanceToTarget(root->left, target, K, solution);
            if (leftDistance >= 0) {
                int distance = leftDistance + 1;
                if (K == distance) solution.push_back(root->val);
                emplaceDepthKNodes(root->right, solution, K - distance - 1);
                return distance;
            }
            else { //if (leftDistance == -1)
                int rightDistance = getDistanceToTarget(root->right, target, K, solution);
                if (rightDistance >= 0) {
                    int distance = rightDistance + 1;
                    if (K == distance) solution.push_back(root->val);
                    emplaceDepthKNodes(root->left, solution, K - distance - 1);
                    return distance;
                } 
                return -1;
            }
        }
    }
    
    void emplaceDepthKNodes(TreeNode* root, vector<int>& solution, int K) {
        if (!root) 
            return;
        if (K == 0) {
            solution.push_back(root->val);
            return;
        } else {
            emplaceDepthKNodes(root->left, solution, K-1);
            emplaceDepthKNodes(root->right, solution, K-1);
        }
    }
};


