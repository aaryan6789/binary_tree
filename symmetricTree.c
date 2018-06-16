/*
 * symmetricTree.c
 *
 *  Created on: May 28, 2018
 *      Author: Harsh
 */
#include "binary_tree.h"

// Returns true if trees with roots as root1 and root2 are mirror
bool isMirror(struct TreeNode *root1, struct TreeNode *root2) {
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    // For 2 trees to be mirror images, the following 3 conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data){
    	return  isMirror(root1->left, root2->right) &&
    			isMirror(root1->right, root2->left);
    }

    // if neither of above conditions is true then
    // root1 and root2 are not mirror images
    return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetric(struct TreeNode* root) {
    // Check if tree is mirror of itself
    return isMirror(root, root);
}
