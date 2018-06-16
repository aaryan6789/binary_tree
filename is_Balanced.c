/*
 * is_Balanced.c
 *
 *  Created on: May 25, 2018
 *      Author: Harsh
 */
#include "binary_tree.h"

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* returns maximum of two integers */
int imax(int a, int b) {
  return (a >= b)? a: b;
}

/*
 * The function Compute the "height" of a tree.
 * Height is the number of nodes along the longest path
 * from the root node down to the farthest leaf node */
int height(struct TreeNode* node) {
   /* Base Case : Empty Tree */
   if(node == NULL)
       return 0;

   /* If tree is not empty then
    * height = 1 + max of left height and right heights */
   return 1 + imax(height(node->left), height(node->right));
}

/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct TreeNode *root) {
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */

   /* If tree is empty then return true */
   if(root == NULL)
    return 1;

   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);

   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;

   /* If we reach here then tree is not height-balanced */
   return 0;
}
