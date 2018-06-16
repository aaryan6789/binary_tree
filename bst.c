/*
 * bst.c
 *
 *  Created on: May 22, 2018
 *      Author: Harsh
 */
#include "binary_tree.h"
#include <limits.h>

//For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.
//
///* Returns true if a binary tree is a binary search tree */
//int isBST(struct btNode* root) {
//  if (root == NULL)
//    return(true);
//
//  /* false if the max of the left is > than us */
//  if (root->left !=NULL && maxValue(root->left) > root->data)
//    return(false);
//
//  /* false if the min of the right is <= than us */
//  if (root->right!=NULL && minValue(root->right) < root->data)
//    return(false);
//
//  /* false if, recursively, the left or right is not a BST */
//  if (!isBST(root->left) || !isBST(root->right))
//    return(false);
//
//  /* passing all that, it's a BST */
//  return(true);
//}
//
//
//// Method 2 : (efficient version)
//int isBSTUtil(struct btNode* root, int min, int max);
//
///* Returns true if the given tree is a binary search tree. */
//int isBST2(struct btNode* root) {
//	return(isBSTUtil(root, INT_MIN, INT_MAX));
//}
//
//
///* Returns true if the given tree is a BST and its values are >= min and <= max.*/
//int isBSTUtil(struct btNode* root, int min, int max) {
//	/* an empty tree is BST */
//	if (root==NULL)
//	 return 1;
//
//	/* false if this root violates the min/max constraint */
//	if (root->data < min || root->data > max)
//		return 0;
//
//	/* otherwise check the subtrees recursively,
//	tightening the min or max constraint */
//	return (isBSTUtil(root->left, min, root->data-1) &&  // Allow only distinct values
//			isBSTUtil(root->right, root->data+1, max));  // Allow only distinct values
//}
