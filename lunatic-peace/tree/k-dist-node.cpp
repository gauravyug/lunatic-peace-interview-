/*
  All Nodes Distance K in Binary Tree - LeetCode: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
#include<bits/stdc++.h>

using namespace std;

                        
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void populateNodeToParentMap(map<TreeNode*, TreeNode*> &nodeToParentMap,
                                  TreeNode* root, TreeNode* parent);
vector<int> extractLayerFromQueue(queue<TreeNode *> q);

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    map<TreeNode*, TreeNode*> parent_map;
    populateNodeToParentMap(parent_map, root, NULL);
    /*map<TreeNode*, TreeNode*>::iterator it;
    for (it = parent_map.begin(); it != parent_map.end(); it++) {
        TreeNode *k = it->first;
        TreeNode *v = it->second;
        cout << "key " << k->val ;  
        if (v!= NULL)
            cout << " : val  " << v->val << endl;
        else
            cout << " : val NULL\n"; 
        
    }*/
    queue<TreeNode*> level_queue;
    level_queue.push(target);
    set<TreeNode*> seen_hash;
    seen_hash.insert(target);
     
    //When our search starts, we are standing at layer 0
    int currentLayer = 0;
    while (!level_queue.empty()) {
        cout << level_queue.front()->val << endl;
        if (currentLayer == K) {
            return extractLayerFromQueue(level_queue);
        }
        int layerSize = level_queue.size();
        cout << layerSize << endl;
        for (int i = 0; i < layerSize; i++) {
             TreeNode* currentNode = level_queue.front();
             level_queue.pop();
             if (currentNode->left != NULL && !(seen_hash.find(currentNode->left) != seen_hash.end())) {
                seen_hash.insert(currentNode->left);
                level_queue.push(currentNode->left);
            }

            if (currentNode->right != NULL && !(seen_hash.find(currentNode->right) != seen_hash.end())) {
                seen_hash.insert(currentNode->right);
                level_queue.push(currentNode->right);
            }
            TreeNode* parentOfCurrentNode = parent_map[currentNode];
            if (parentOfCurrentNode != NULL && !(seen_hash.find(parentOfCurrentNode) != seen_hash.end())) {
                seen_hash.insert(parentOfCurrentNode);
                level_queue.push(parentOfCurrentNode);
            }
            
      }
      currentLayer++;
    }
    return res;
}
vector<int> extractLayerFromQueue(queue<TreeNode *> q)
{
    vector<int> extractedList;
    while (!q.empty()) {
        extractedList.push_back(q.front()->val);
        q.pop();
    }
    return extractedList;
}
void populateNodeToParentMap(map<TreeNode*, TreeNode*> &nodeToParentMap,
                                  TreeNode* root, TreeNode* parent) {
    if (root == NULL)
        return;

    nodeToParentMap.insert(pair<TreeNode*, TreeNode*>(root, parent));
    populateNodeToParentMap(nodeToParentMap, root->left, root);
    populateNodeToParentMap(nodeToParentMap, root->right, root);

 }


int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2); 
	root->right = new TreeNode(3); 
	root->left->left = new TreeNode(7); 
	root->left->right = new TreeNode(8); 
	root->right->right = new TreeNode(15); 
	root->right->left = new TreeNode(12); 
	root->right->right->left = new TreeNode(14);

    vector<int> ans = distanceK(root, root->left, 3);
    for (auto res: ans) {
        cout << "haha " << res << endl;
    }
    return 0;
}