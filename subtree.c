/* subtree.c * Created on: May 22, 2018  *  Author: Harsh  */
#include "binary_tree.h"
/*
Check if a binary tree is subtree of another binary tree
Given two binary trees, check if the first tree is subtree of the second one.

A subtree of a tree T is a tree S consisting of a node in T
and all of its descendants in T.
The subtree corresponding to the root node is the entire tree;
the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T.
        Tree 2
          10
        /    \
      4       6
       \
        30


        Tree 1
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30

Solution:
Traverse the tree T in preorder fashion.
For every visited node in the traversal, see if the subtree rooted with this node is identical to S.
*/

/* A binary tree node has data, left child and right child
struct node {
    int data;
    struct node* left;
    struct node* right;
};
*/
#define bool int
#define true 1
#define false 0

/* A utility function to:
 * check whether trees with roots as root1 and root2 are identical or not */
bool areIdentical(struct TreeNode * root1, struct TreeNode *root2) {
    /* base case(s) */
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    /* Check if the data of both roots is same and data of left and right
       subtrees are also same */
    return (root1->data == root2->data   &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}


/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(struct TreeNode *T, struct TreeNode *S) {
    /* base cases */
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;

    /* If the tree with root as current node doesn't match then
       try left and right subtrees one by one */
    return isSubtree(T->left, S) ||
           isSubtree(T->right, S);
}
