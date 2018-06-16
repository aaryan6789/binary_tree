/* inorder_successor.c  *  Created on: May 25, 2018 *  Author: Harsh */
#include "binary_tree.h"

/* InOrder Successor
Given a binary search tree and a node in it,
find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.

Example 1: Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2

Example 2: Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /
1

Output: null

Inorder Successor of a node in binary tree is the next node in Inorder traversal
of the Binary Tree.
Inorder Successor is NULL for the last node in Inorder traversal.
 */

typedef struct TreeNode Node;

// function to find left most node in a tree
struct TreeNode* leftMostNode(struct TreeNode* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;

    return node;
}

// function to find right most node in a tree
struct TreeNode* rightMostNode(struct TreeNode* node){
    while (node != NULL && node->right != NULL)
        node = node->right;

    return node;
}
// recursive function to find the Inorder Successor
// when the right child of node x is NULL
struct TreeNode* findInorderRecursive(struct TreeNode* root, struct TreeNode* x ) {
    struct TreeNode* temp;

	if (!root)
        return NULL;

    if (root==x ||
       (temp = findInorderRecursive(root->left,x)) ||
	   (temp = findInorderRecursive(root->right,x))) {
        if (temp) {
            if (root->left == temp) {
                printf("Inorder Successor of %d is %d \n", x->data, root->data);
                return NULL;
            }
        }

        return root;
    }

    return NULL;
}

// function to find inorder successor of a node
void inorderSuccesor(struct TreeNode* root, struct TreeNode* x) {
    // Case1: If right child is not NULL
    if (x->right != NULL){
        struct TreeNode* inorderSucc = leftMostNode(x->right);
        printf("Inorder Successor of %d is %d \n", x->data, inorderSucc->data);
    }

    // Case2: If right child is NULL
    if (x->right == NULL) {
        //int f = 0;
        struct TreeNode* rightMost = rightMostNode(root);

        // case3: If x is the right most node
        if (rightMost == x)
            printf("No inorder successor! Right most node.\n");
        else
            findInorderRecursive(root, x);
    }
}
