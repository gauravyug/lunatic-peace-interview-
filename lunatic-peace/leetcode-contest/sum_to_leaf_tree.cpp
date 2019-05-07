#include <bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumRootToLeaf(TreeNode* root) {
        return roottoleaf(root, 0);
}

int roottoleaf(TreeNode *root, int val) {
    if (root == NULL)
        return 0;
    
    val = (val << 1) + root->val;
    val %= 1000000007;
    if (root->right == NULL && root->left == NULL) {
        return val;
    }
    return roottoleaf(root->left, val) + roottoleaf(root->right, val) % 1000000007;
    
}

int roottoleafsum(TreeNode *root, int val) {
    if (!root) 
    return 0;
    val = (val * 2) + root->val;
    if (root->left == NULL && root->right == NULL)
    return val;
    return  roottoleafsum(root->left, val) + roottoleafsum(root->right, val);
}

int main() {
    
    ret 0;
}