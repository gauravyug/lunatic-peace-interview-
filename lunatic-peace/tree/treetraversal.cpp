#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode *root){
    return root->left == NULL && root->right == NULL;
}
void rightboundaryandleaves(TreeNode *root, bool is_boundary){
    if (root != NULL) {
        rightboundaryandleaves(root->left, is_boundary && root->right == NULL);
        rightboundaryandleaves(root->right, is_boundary);
         if (is_boundary || isLeaf(root))
            cout << root->val << " ";
    }    
}

void leftboundaryandleaves(TreeNode *root, bool is_boundary){
    if (root != NULL) {
         if (is_boundary || isLeaf(root))
            cout << root->val << " ";
        leftboundaryandleaves(root->left, is_boundary);
        leftboundaryandleaves(root->right, is_boundary && root->left == NULL);
    }
}

void printBoundary(TreeNode *root)
{
     if (root != NULL) {
         cout << root->val << " ";
     }
     leftboundaryandleaves(root->left, true);
     rightboundaryandleaves(root->right, true);
}
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
    //if (root == NULL) return ;
    queue <TreeNode *> q;
    vector <int> vec;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        int count = q.size();
        while (count > 0) {
            root = q.front();
            q.pop();
            if (root != NULL) {
                vec.push_back(root->val);
                cout << "val =" << root->val;
            }

            if (root) {
                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
            }
            count--;
        }
        cout << "\n";
        vec.push_back(-1);
    }
    //for(auto t=vec.begin(); t!=vec.end(); ++t)
	//std::cout << *t << '\n';
    return vec;
}
vector<vector<int>> levelorderII(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        vector<int> level;
        int count = q.size();
        while (count > 0) {
            TreeNode *temp = q.front();
            q.pop() ;
            if (temp != NULL) {
                level.push_back(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            count--;
        }
        if (level.size() > 0) {
            result.push_back(level);
        }
    }
    return result;
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
    /*
                    10     ---------------------I
            2               3 ------------------II
        7       8       12        15------------III
                              14----------------IV
    */
    vector<vector<int>> ret = levelorderII(root);
    for(auto& row:ret){
        for(auto& col:row){
            cout << col << " "  ;
        }
        cout << endl;
    }
 
    boundry_traversal(root);
    return 0;
}