/* traversal_zig_zag_spiral.c  * Created on: Jun 11, 2018 * Author: Harsh */
#include "binary_tree.h"

/* LeetCode | CTCI
 * ZIG ZAG Traversal
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 *  (ie, from left to right, then right to left for the next level and alternate between).
 *
 *  For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
/* Algorithm: Using 2 stacks
 * 1. Use one stack for printing from left to right and
 *    other stack for printing from right to left.
 * 2. In every iteration, we have nodes of one level in one of the stacks.
 * 3. Print the nodes, and push nodes of next level in other stack.
 */

void zigzagTraversalI(struct TreeNode* root){
	if (root == NULL)
		return;

	// Create 2 empty Stacks
	struct Lstack* st1 = NULL; 	// For levels to be printed from right to left
	struct Lstack* st2 = NULL;	// For levels to be printed from left to right

	// Push Level 1 on Stack 1
	Lpush(&st1, root);

	// Keep printing while any of the stacks have nodes
	while(!isLStackEmpty(st1) || !isLStackEmpty(st2)){

		while(!isLStackEmpty(st1)){
			struct TreeNode* temp = Lpop(&st1);
			printf("%d ", temp->data);

			// Push the left first before right for next level
			if(temp->left)
				Lpush(&st2, temp->left);

			if(temp->right)
				Lpush(&st2, temp->right);
		}
		printf("\n");	// For printing the next level in next line

		while(!isLStackEmpty(st2)){
			struct TreeNode* temp = Lpop(&st2);
			printf("%d ", temp->data);

			// Push Right node first before left on stack 2 for next level
			if(temp->right)
				Lpush(&st1, temp->right);

			if(temp->left)
				Lpush(&st1, temp->left);
		}
		printf("\n");
	}
}

