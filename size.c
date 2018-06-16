/* calculate_size.c * * Created on: May 20, 2018 *      Author: Harsh  */
#include "binary_tree.h"

/* Calculate the Size of the Tree
 * Size of the Tree is the number of elements present in the tree
 *
 * Method1: Using Recursion
 * size of tree = size of left Subtree + 1 + size of right Subtree
 */
int size(struct TreeNode* root){
	if(!root)
		return 0;

	int ret = size(root->left) + 1 + size(root->right);
	printf("Size of the Binary Tree:Root=%d is %d\n", root->data, ret);
	return ret;
}

/* Method2 : Using Queue
 */
int size2(struct TreeNode* root){
	printf("Calculating Size of the Tree without Recursion\n");
	if(root == NULL){
		return 0;
	}

	int count = 0;
	struct TreeNode* temp;
	struct Queue* q = createQueue();
	enQueue(q, root);

	while(!isQueueEmpty(q)){
		temp = deQueue(q);
		count++;

		if(temp->left != NULL)
			enQueue(q, temp->left);

		if(temp->right != NULL)
			enQueue(q, temp->right);
	}

	printf("Size of the Tree = %d\n", count);
	return count;
}
