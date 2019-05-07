#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *nextRight;
};


  
class PopulateRightNeighbors 
{
  
     
     
    private 
     
    private void traverseUsingNeighbors(TreeNode root)
    {
        TreeNode currentNode = root;
        while (currentNode != null)
        {
            TreeNode temp = currentNode;
            currentNode = null;
             
            // print all the nodes in the current level
            while(temp != null)
            {
                // keep checking for the left-most node in the level below the current level
                // that is where traversal for next level is going to start
                if (currentNode == null)
                {
                    currentNode = (temp.left != null) ? temp.left : temp.right;
                }
                 
                System.out.print(temp.value + " ");
                temp = temp.neighbor;
            }
            System.out.print("\n\n");
        }
    }
 
    public void populateNeighbors()
    {
        populateNeighbors(root);
    }
     
    public void traverseUsingNeighbors()
    {
        traverseUsingNeighbors(root);
    }
     
     
    public static void main(String[] args)
    {
        PopulateRightNeighbors tree = new PopulateRightNeighbors();
 
        /*
                                0
                          1             2
                      3              5     6
                                          7  8
        */
        tree.createTree();
 
        tree.populateNeighbors();
 
        tree.traverseUsingNeighbors();
    }
}
     
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->nextRight = NULL;
 
    return(node);
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
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
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
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight? root->right->right->nextRight->data: -1);
 
    getchar();
    return 0;
}   