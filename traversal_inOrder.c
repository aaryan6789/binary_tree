/* in_order_traversal.c  * Created on: May 30, 2018 * Author: Harsh */
#include "binary_tree.h"

/* InOrder Traversal of a Tree : Left, Root, Right */
void inOrderTraversalR(struct TreeNode* root){
	if(root == NULL)
		return;

	inOrderTraversalR(root->left);
	printf("%d ", root->data);
	inOrderTraversalR(root->right);

}

/* Iterative InOrder Traversal
 * Using Stack
 *
 * 1) Create an empty stack S.
 * 2) Initialize current node as root
 * 3) Push the current node to S and set current = current->left until current is NULL
 * 4) If current is NULL and stack is not empty then
 *   a) Pop the top item from stack.
 *   b) Print the popped item, set current = popped_item->right
 *   c) Go to step 3.
 * 5) If current is NULL and stack is empty then we are done.
 */
void inOrderTraversalI(struct TreeNode* root){
	printf("\nInOrder Traversal using Stack/ Iterative\n");
	/* set current to root of binary tree */
	struct TreeNode* current = root;

	// Initialize Stack
	struct Lstack* tstack = NULL;
	int done = 0;

	while(!done){
		// If current is not Null then push it on the Stack
		if(current != NULL){
			Lpush(&tstack, current);
			current = current->left;
		}
		// If current is NULL then Pop from the stack and Print
		else{
			if(!isLStackEmpty(tstack)){
				current = Lpop(&tstack);
				printf("%d ", current->data);
				// Set the current to the right node of the current
				current = current->right;
			}
			else{
				done = 1;
			}
		}
	}
}
