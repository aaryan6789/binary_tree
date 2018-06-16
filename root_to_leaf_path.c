/* root_to_leaf_path.c  * Created on: May 30, 2018 * Author: Harsh */
#include "binary_tree.h"
/* LeetCode | CTCI
 * Given a binary tree, return all root-to-leaf paths.
 * Note: A leaf is a node with no children.
 *
 * Example:
 * Input:
   	   1
 	 /   \
	2     3
 	 \
  	  5
 *
 * Output: ["1->2->5", "1->3"]
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

/* Method 1: Using Recursion
 * 1. Use a Path array to store CUrrent root to leaf path
 * 2. Traverse from root to leaf in top down fashion
 * 3. While traversing, store the data of all the nodes in the current path in the path array
 * 4. When we reach the leaf node, print the path array.
 */
void printArray(int* A, int size){
	int i;

	printf("Path: ");
	for(i = 0; i<size; i++)
		printf("%d ", A[i]);

	printf("\n");
}

void printPathsRecur(struct TreeNode* root, int path[], int pathLen);
void allPaths(struct TreeNode* root){
	int path[100];
	printPathsRecur(root, path, 0);
}

void printPathsRecur(struct TreeNode* root, int path[], int pathLen){
	if(root == NULL)
		return;

	// Append this node to the array path
	path[pathLen] = root->data;
	pathLen++;

	// Base Case: If reached to leaf : Print out the path
	if(root->left == NULL && root->right == NULL){
		printArray(path, pathLen);
	}
	else{
		// Recursive Case: Try both the SubTree's
		printPathsRecur(root->left, path, pathLen);
		printPathsRecur(root->right, path, pathLen);
	}
}
