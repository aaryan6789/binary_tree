/* path_sum.c  * Created on: May 30, 2018 * Author: Harsh */
#include "binary_tree.h"

/* LeetCode 112
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 * Example: Given the below binary tree and sum = 22,
 *
 *		    5
 *		   / \
 *		  4   8
 *		 /   / \
 *		11  13  4
 *	   /  \      \
 *	  7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

/* Algorithm:
 * 1. Start from root and recursively check for the sum
 * 2. Calculate the Sub Sum
 * 3. Check for the SubSum in the Left Sub Tree
 * 4. Check for the SubSum in the right Sub Tree
 */
int hasPathSum(struct TreeNode* root, unsigned int sum){
	if(root == NULL){
		return (sum == 0);
	}
	else{

		int subSum;
		int ans = 0;
		subSum = sum - root->data;
		if(subSum == 0 && root->left == NULL && root->right == NULL)
			return true;

		// Check if there is a left SubTree Path, then check in the Right SubTree
		if(root->left != NULL)
			ans = ans || hasPathSum(root->left, subSum);

		if(root->right != NULL)
			ans = ans || hasPathSum(root->right, subSum);

		return ans;
	}
}
