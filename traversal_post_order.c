/* post_order_traversal.c  * Created on: May 30, 2018 * Author: Harsh */

#include "binary_tree.h"

/* PostOrder Traversal of a Tree : Left, Right, Root */
void postOrderTraversalR(struct TreeNode* root){
	if(root == NULL)
		return;

	postOrderTraversalR(root->left);
	postOrderTraversalR(root->right);
	printf("%d ", root->data);
}

/* Post Order Traversal : Iterative
 * 1. Using 2 Stacks
 *
 * Algorithm:
 * 1. Push root to first stack.
 * 2. Loop while first stack is not empty.
 *    2.1 Pop a node from first stack and push it to second stack.
 *    2.2 Push left and right children of the popped node to first stack.
 * 3. Print contents of second stack.
 *
 * Note: After step 2, we get reverse post-order traversal in second stack.
 */

void postOrderTraversalI(struct TreeNode* root){
	printf("\nPost Order Traversal: Iterative :: Using 2 Stacks\n");
	struct Lstack* st1 = NULL;
	struct Lstack* st2 = NULL;

	// Push the root to stack 1
	Lpush(&st1, root);

	while(!isLStackEmpty(st1)){
		struct TreeNode* temp = Lpop(&st1);
		Lpush(&st2, temp);

		if(temp->left)
			Lpush(&st1, temp->left);

		if(temp->right)
			Lpush(&st1, temp->right);
	}

	// Print the Second Stack contents
	while(!isLStackEmpty(st2)){
		struct TreeNode* pop = Lpop(&st2);
		printf("%d ", pop->data);
	}
}
