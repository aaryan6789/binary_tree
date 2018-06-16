/* invert_tree.c  * Created on: May 30, 2018 * Author: Harsh */
#include "binary_tree.h"

/* LeetCode Easy
 *  Invert a binary tree.
 *
 *  Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

 * Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
 */

/* invertTree - for inverting the Tree
 * Inverting the tree means that the left child of the root goes to be the right child.
 * And the left child of the root becomes the right child.
 * This property goes to the leaves of the tree.
 *
 * Method 1: Using Recursion
 * 1. Recursively call the invert tree on all the child nodes of the Tree.
 *
 * Method 2 : Using Queue
*/
struct TreeNode* invertTreeR(struct TreeNode* root) {
    // Base Case: For Leaves
    if (root == NULL)
        return NULL;

    // Recursive Case: For Sub Trees
    struct TreeNode* leftTree = invertTreeR(root->left);
    struct TreeNode* rightTree = invertTreeR(root->right);

    root->left = rightTree;
    root->right = leftTree;

    return root;
}
