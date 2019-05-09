#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void KGreatestNode(TreeNode *root, int &k, int &count, int &result) {
        if (root == NULL) {
            return;
        }
        KGreatestNode(root->right, k, count, result);
        count++;
        if( k == count) {
            result = root->val;
            return;
        } 
        KGreatestNode(root->left, k, count, result);   
}
int main()
2
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    //root->right = new TreeNode(16);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    //root->right->left = new TreeNode(12);
    //root->right->right = new TreeNode(20);
    //root->right->right->right = new TreeNode(22);
    int res = -1;
    int k =2;
    int count = 0;
    KGreatestNode(root, k, count, res);
    cout << "k th highest node is " << res;
    return 0;
}