#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector <int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *>q; 
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(q.front()==NULL && root)
            res.push_back(root->val);
                //cout<<root->val<<" ";
            
        if(root==NULL && !q.empty()) {
                q.push(NULL);
        }
        else if(root) {
            if(root->left)
                    q.push(root->left);
            if(root->right)
                    q.push(root->right);
            }
    }
    reverse(res.begin(), res.end());
    for(auto t=res.begin(); t!=res.end(); ++t)
	std::cout << *t << '\n'; 
    return res;
}
vector<int> levelorder(TreeNode *root) {
    if (root == NULL) return;
    queue <TreeNode *> q;
    vector <int> vec;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        int count = q.size();
        while (count > 0) {
            root = q.front();
            q.pop();
            if (root != NULL)
                vec.push_back(root->val);

            if (root) {
                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
            }
            count--;
        }
        vec.push_back(-1);
    }
    //for(auto t=vec.begin(); t!=vec.end(); ++t)
	//std::cout << *t << '\n';
    return vec;
}
vector<int> leftSideView(TreeNode* root) {
    vector <int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *>q; 
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(q.front()==NULL && root)
            res.push_back(root->val);
                //cout<<root->val<<" ";
            
        if(root==NULL && !q.empty()) {
                q.push(NULL);
        }
        else if(root) {
            if(root->right != NULL)
                    q.push(root->right);
            if(root->left != NULL)
                    q.push(root->left);
            }
    }
    for(auto t=res.begin(); t!=res.end(); ++t)
	std::cout << *t << '\n';
    return res;
}
vector <int> leafNodes(TreeNode *root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp->left && !temp->right) {
            cout << temp->val << "\n";
        }
        if (temp->left != NULL) 
            q.push(temp->left);
        if (temp->right != NULL) 
            q.push(temp->right);
    }
    return res;
}
vector<int> boundry_traversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    /*vector<int> right = leftSideView(root->left);
    leafNodes(root->left);
    leafNodes(root->right);
    vector<int> left = rightSideView(root->right);*/

}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2); 
	root->right = new TreeNode(3); 
	root->left->left = new TreeNode(7); 
	root->left->right = new TreeNode(8); 
	root->right->right = new TreeNode(15); 
	root->right->left = new TreeNode(12); 
	root->right->right->left = new TreeNode(14);
    levelorder(root); 
    //boundry_traversal(root);
    return 0;
}