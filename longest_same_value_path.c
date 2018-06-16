/* longest_same_value_path.c  * Created on: May 31, 2018 * Author: Harsh */
#include "binary_tree.h"

/* Longest Path with Same Values in a Binary Tree

Given a binary tree, find the length of the longest path
where each node in the path has the same value.
This path may or may not pass through the root.
The length of path between two nodes is the number of edges between them.

Examples:
Input :
              2
             / \
            7   2
           / \   \
          1   1   2
Output : 2

Input :
              4
             / \
            4   4
           / \   \
          4   9   5
Output : 3
 */
int length(struct TreeNode* root, int* ans);

// Wrapper Function to return the longest Path
int longestSameValuePath(struct TreeNode* root){
	int ans = 0;
	length(root, &ans);

	printf("\n Longest Path = %d\n", ans);
	return ans;
}

int length(struct TreeNode* root, int* ans){
	// Base Case: When Root is Null
	if(!root)
		return 0;

	// Recursive Case: For SubTrees
	int left = length(root->left, ans);
	int right = length(root->right, ans);

	// Variables to store the max lengths in two directions
	int leftMax = 0;
	int rightMax = 0;

	if(root->left && (root->left->data == root->data)){
		leftMax = leftMax + left + 1;
	}

	if(root->right && (root->right->data == root->data)){
		rightMax = rightMax + right + 1;
	}

	*ans = max(*ans, (leftMax+rightMax));

	return max(leftMax, rightMax);
}
