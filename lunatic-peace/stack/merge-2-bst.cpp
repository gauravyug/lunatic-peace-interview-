#include<iostream>
#include<stack>
#include<climits>
using namespace std;

// Structure of a BST Node
struct node{
	int data;
	node *left;
	node *right;
};

/* Utility function to create a new Binary Tree node */
node *newnode(int data){
	node * nnode=new node;
	nnode->data=data;
	nnode->left=NULL;
	nnode->right=NULL;
	return nnode;
}

/* A utility function to print Inoder traversal of a Binary Tree */
void printInorder(node *root){
	if(root==NULL)	{return;}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

// The function to print data of two BSTs in sorted order
void printMergedBSTs(node *bst1, node *bst2){
	
	// done1, val1, curr1 and pre1 are used for Morris inorder traversal of bst1
	// done2, val2, curr2 and pre2 are used for Morris inorder traversal of bst2
	bool done1=false;
	bool done2=false;
	node *curr1=bst1;
	node *curr2=bst2;
	node *pre1,*pre2;
	int val1,val2;
	
	//If any of the BST is NULL print the other one
	if(bst1==NULL && bst2==NULL){
			return;
	}
	if(bst1==NULL){
		printInorder(bst2);
		return;
	}
	
	if(bst2==NULL){
		printInorder(bst1);
		return;
	}
	while(1){
		while(done1==false){
			//if curr1 is NULL, then bst1 is exhausted 
		    if(curr1==NULL){
		        val1=INT_MAX;
		        done1=true;
		    }
		    else{
		        if(curr1->left==NULL){
			        val1=curr1->data;
			        curr1=curr1->right;
			        done1=true;
			    }
			    else{
			        pre1=curr1->left;
				    /* Find the inorder predecessor of curr1 */
			        while(pre1->right!=NULL && pre1->right!=curr1){
			           pre1=pre1->right;
			        }
			        /* Make curr1 as right child of its inorder predecessor */
			        if(pre1->right==NULL){
			         pre1->right=curr1;
			         curr1=curr1->left;
			        }
			        /* Revert the changes made in if part to restore the original 
       			    tree i.e., fix the right child of predecssor */
			        else{
			         val1=curr1->data;
			         pre1->right=NULL;
			         curr1=curr1->right;
			         done1=true;
			        }
			    }
		    }
		}
		while(done2==false){
			//if curr2 is NULL, then bst2 is exhausted
			if(curr2==NULL){
			    val2=INT_MAX;
		        done2=true;
		    }
		    else{
		       if(curr2->left==NULL){
			        val2=curr2->data;
			        curr2=curr2->right;
			        done2=true;
			    }
			   else{
			        pre2=curr2->left;
			    	/* Find the inorder predecessor of curr2 */
			        while(pre2->right!=NULL && pre2->right!=curr2){
			             pre2=pre2->right;
			        }
			        /* Make curr2 as right child of its inorder predecessor */
			        if(pre2->right==NULL){
			             pre2->right=curr2;
			            curr2=curr2->left;
			        }
			         /* Revert the changes made in if part to restore the original 
       		     	 tree i.e., fix the right child of predecssor */
			        else{
			             val2=curr2->data;
			             pre2->right=NULL;
			             curr2=curr2->right;
			             done2=true;
			        }
			    }
		    }
		}
		/*Prints the smaller value*/
		if(val1<=val2 && val1!=INT_MAX){
			cout<<val1<<" ";
			done1=false;
		}
		else if(val2<val1){
			cout<<val2<<" ";
			done2=false;
		}
		else{
		    return;
		}
	}
}

/* Driver program to test above functions */
int main(){
	node *bst1=newnode(60);
	bst1->left=newnode(50);
	bst1->left->left=newnode(40);
	bst1->left->right=newnode(55);
	bst1->right=newnode(70);
	bst1->right->right=newnode(80);
	/* Let us create the following tree as first tree
            60
          /   \
        50     70
       / \      \
      40  55     80
     */
	node *bst2=newnode(40);
	bst2->left=newnode(9);
	bst2->left->left=newnode(2);
	bst2->left->right=newnode(22);
	bst2->right=newnode(45);
	bst2->right->left=newnode(44);
	bst2->right->right=newnode(55);
	/* Let us create the following tree as second tree
            40
          /   \
        9      45
       / \    /  \
      2  22  44   55
     */
     
    // Print sorted nodes of both trees
	printMergedBSTs(bst1,bst2);
	return 0;
}