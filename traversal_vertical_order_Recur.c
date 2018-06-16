/* traversal_vertical_order.c  * Created on: Jun 12, 2018 * Author: Harsh */
#include "binary_tree.h"


/*
 * Method 1 : Using recursion
 *
 * 1. Get the Min and Max distance from the root.
 * 2. Print the Vertical Lines
 */
void findMinMax(struct TreeNode* root, int* min, int* max, int hdist);
void printVerticalLine(struct TreeNode* root, int line_no, int hdist);
void verticalOrderTraversalR(struct TreeNode* root){
	int min = 0;
	int max = 0;

	// Find the min and max distance from the root
	findMinMax(root, &min, &max, 0);

	for(int line_no = min; line_no <= max; line_no++){
		printVerticalLine(root, line_no, 0);
		printf("\n");
	}
}

/* findMinMax - Updates the min and max horizontal distance from the root
 * We are using the Pointers to the min and max values as the function itself
 * is updating the min and max values.
 *
 * Remember : [*(&x)] = [value at(address of x)]
 */
void findMinMax(struct TreeNode* root, int* min, int* max, int hdist){
	// Base Case
	if(root == NULL)
		return;

	// Update the Min and Max distances
	if( hdist < *min)
		*min = hdist;
	else if(hdist > *max)
		*max = hdist;

	// Recursive Case
	findMinMax(root->left, min, max, hdist-1);
	findMinMax(root->right, min, max, hdist+1);
}

/* printVerticalLine - Function to print the nodes in each vertical line.
 * @line_no : vertical line number
 * @hdist : horizontal distance
 * @root: Root of the TreeNode
 */
void printVerticalLine(struct TreeNode* root, int line_no, int hdist){
	//Base Case
	if(root == NULL)
		return;

	// If the given node is on the Line Number
	if(hdist == line_no)
		printf("%d ", root->data);

	//Recursion : For left and Right Sub Trees
	printVerticalLine(root->left, line_no, hdist-1);
	printVerticalLine(root->right, line_no, hdist+1);
}
