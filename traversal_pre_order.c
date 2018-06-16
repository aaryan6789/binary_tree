/* Traversal_preOrder.c  * Created on: May 25, 2018 * Author: Harsh */
#include "binary_tree.h"


/* PreOrder Traversal of a Tree : Root, Left, Right */
void preOrderTraversalR(struct TreeNode* root){
	if(root == NULL)
		return;

	printf("%d ", root->data);
	preOrderTraversalR(root->left);
	preOrderTraversalR(root->right);
}



/* Iterative pre order Traversal
 * Using Stack
 *
 * Algorithm:
 * 1) Create an empty stack nodeStack and push root node to stack.
 * 2) Do following while nodeStack is not empty.
 * ….a) Pop an item from stack and print it.
 * ….b) Push right child of popped item to stack
 * ….c) Push left child of popped item to stack
 *
 * Right child is pushed before left child to make sure that left subtree is processed first.
 */

void preOrderTraversalI(struct TreeNode* root){
	printf("\nPreOrder Traversal using Stack/ Iterative\n");
	if (root == NULL)
	       return;

	// Create an empty Stack
	struct Lstack* st = NULL;
	Lpush(&st, root);

	while(!isLStackEmpty(st)){
		struct TreeNode* temp = Lpop(&st);
		printf("%d ", temp->data);

		// Push the right child first on the stack  <--- Pay attention here
		if(temp->right)
			Lpush(&st, temp->right);

		if(temp->left)
			Lpush(&st, temp->left);
	}
}
