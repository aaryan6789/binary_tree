/* reverse_level_order_traversal.c  *  *  Created on: May 30, 2018  *      Author: Harsh */
#include "binary_tree.h"

/* Given a Binary Tree:
 * 			1
 * 		   / \
 * 		  2   3
 * 		 / \
 * 		4   5
 *
 * Reverse Level order traversal of the above tree is “4 5 2 3 1”.
 */
/* Method 1 : Using Queue and Stack
 * 1. Create a Queue
 *    Create a Stack
 * 2. EnQueue the root
 * 3. while the the queue is not empty
 *   a. Dequeue from the Queue
 *   b. Push it on the Stack
 *   c. If right child is present, enQueue Right Child
 *   d. If left child is available, enQueue Left Child
 * 4. Print the Stack
 *
 * Time Complexity = O(n)
 * Space Complexity = O(2n) for Queue and Stack
 */
void reverseLevelOrderTraversal(struct TreeNode* root){
	if(!root)
		return;

	struct TreeNode* temp;
	struct Queue* q = createQueue();
	enQueue(q, root);

	while(!isQueueEmpty(q)){
		temp = deQueue(q);
		printf("%d ", temp->data);
		// TODO:Instead of Printing here, push it on the stack

		// EnQueue the Right child first
		if(temp->right != NULL)
			enQueue(q, temp->right);

		// Enqueue the Left child after right
		if(temp->left != NULL)
			enQueue(q, temp->left);
	}

	printf("\n");
	// TODO: Print Stack here
}
