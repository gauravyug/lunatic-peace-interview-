/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
Set the next pointer starting from the left of each level, 
then you can use the next pointer to progress from left to 
right to complete the level. Once a level is finshed, 
advance down the left branch and do it again
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return; //Edge Case
        
        queue<TreeLinkNode*> q;
        
        //Trick: Push NULL to maintain depth information
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeLinkNode* curr = q.front(); 
            q.pop();

            if (curr==NULL) 
            {
                if (q.size() > 0) 
                    q.push(NULL);
            }
            else
            {
                curr->next = q.front();
                
                if(curr->left!=NULL) 
                    q.push(curr->left);
                if(curr->right!=NULL) 
                    q.push(curr->right);
            }
        }
    }
};
