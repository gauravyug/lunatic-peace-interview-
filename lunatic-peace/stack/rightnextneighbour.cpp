
#include <stdio.h>
#include <stdlib.h>
 
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *nextRight;
};
 
/* This function returns the leftmost child of nodes at the same level as p.
   This function is used to getNExt right of p's right child
   If right child of is NULL then this can also be sued for the left child */
struct TreeNode *getNextRight(struct TreeNode *p)
{
    struct TreeNode *temp = p->nextRight;
 
    /* Traverse nodes at p's level and find and return
       the first node's first child */
    while (temp != NULL)
    {
        if (temp->left != NULL)
            return temp->left;
        if (temp->right != NULL)
            return temp->right;
        temp = temp->nextRight;
    }
 
    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}
 
void connect(TreeNode *root) {
		if(!root || !root->left) 
			return;
		TreeNode * cur = root;
		TreeNode * level = root->left;
		while(cur->left) {
			cur->left->nextRight= cur->right;
			if(cur->nextRight)  { 
				cur->right->nextRight = cur->nextRight->left;
				cur= cur->nextRight;
		}
		else { 
			 cur = level ; 
			 level = level->left;
		}
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode* newnode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                        malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->nextRight = NULL;
 
    return(node);
}
 
 
 /* Sets nextRight of all nodes of a tree with root as p */
void connect2(struct TreeNode* p)
{
    struct TreeNode *temp;
 
    if (!p)
      return;
 
    // Set nextRight for root
    p->nextRight = NULL;
 
    // set nextRight of all levels one by one
    while (p != NULL)
    {
        struct TreeNode *q = p;
 
        /* Connect all childrem nodes of p and children nodes of all other nodes
          at same level as p */
        while (q != NULL)
        {
            // Set the nextRight pointer for p's left child
            if (q->left)
            {
                // If q has right child, then right child is nextRight of
                // p and we also need to set nextRight of right child
                if (q->right)
                    q->left->nextRight = q->right;
                else
                    q->left->nextRight = getNextRight(q);
            }
 
            if (q->right)
                q->right->nextRight = getNextRight(q);
 
            // Set nextRight for other nodes in pre order fashion
            q = q->nextRight;
        }
 
        // start from the first node of next level
        if (p->left)
           p = p->left;
        else if (p->right)
           p = p->right;
        else
           p = getNextRight(p);
    }
}

void connect3(TreeNode *root) {
         if (!root) {
            return;
        }
        
        TreeNode *dummy = newnode(0);
        TreeNode *prev = dummy;
        while (root) {
            if (!root->left) {
                // reach the bottom level
                return;
            }
            
            // link left and right children of this node
            root->left->nextRight = root->right;
            prev->nextRight = root->left;
            prev = prev->nextRight->nextRight;
            // next node
            root = root->nextRight;
            if (!root) {
                root = dummy->nextRight;
                prev = dummy;
                dummy->nextRight = NULL;
            }
        }
        
        delete dummy;
    }
/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct TreeNode *root = newnode(10);
    root->left        = newnode(8);
	root->left->right        = newnode(6);
    root->right       = newnode(2);
	root->right->left      = newnode(4);
    root->left->left  = newnode(3);
	root->left->left->left  = newnode(13);
	root->left->right->left        = newnode(16);
	root->right->left->right      = newnode(14);
    root->right->right       = newnode(90);
 
    // Populates nextRight pointer in all nodes
    connect(root);
 
    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight? root->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight? root->left->left->nextRight->data: -1);

	printf("nextRight of %d is %d \n", root->left->right->data,
          root->left->right->nextRight? root->left->right->nextRight->data: -1);
		  
    printf("nextRight of %d is %d \n", root->right->left->data,
          root->right->left->nextRight? root->right->left->nextRight->data: -1);
		   
	printf("nextRight of %d is %d \n", root->left->left->left->data,
           root->left->left->left->nextRight? root->left->left->left->nextRight->data: -1);

	printf("nextRight of %d is %d \n", root->left->right->left->data,
           root->left->right->left->nextRight? root->left->right->left->nextRight->data: -1);   
   // getchar();
    return 0;
}
