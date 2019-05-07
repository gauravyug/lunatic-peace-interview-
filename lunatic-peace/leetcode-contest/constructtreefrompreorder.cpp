/*
1028. Recover a Tree From Preorder Traversal
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  (If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.

Given the output S of this traversal, recover the tree and return its root.
*/

class Solution {
public:
    int itr = 0;
    TreeNode* recoverFromPreorder(string S, int d = 1) {
        int sum = 0;
        if (S.size() == 0 ) 
            return NULL;
        for (;itr < S.size(); itr++) {
            if (S[itr] == '-')
                break;
            sum = 10 * sum + S[itr] - '0';
        }
        TreeNode* root = new TreeNode(sum);
        if ( itr == S.size() )
            return root;

        setChildNode(S, root->left, d);
        setChildNode(S, root->right, d);
        return root;
    }
    
    void setChildNode(string &S, TreeNode* &childNode, int d) {
        int depth = 0;
        int i = itr;
        for (i = itr; i < S.size(); ++i) {
            if (S[i] != '-')
                break;
            ++depth;
        }
        if (depth == d) {
            itr = i;
            childNode = recoverFromPreorder(S, d+1);
        }
    }
};