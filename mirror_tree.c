/*
 * mirror_tree.c
 *
 *  Created on: May 25, 2018
 *      Author: Harsh
 */
#include "binary_tree.h"

/* Change a tree so that the roles of the  left and
    right pointers are swapped at every node.

 So the tree...
       4
      / \
     2   5
    / \
   1   3

 is changed to...
       4
      / \
     5   2
        / \
       3   1
*/
void mirrorRecur(struct TreeNode* root) {
	if (root==NULL) {
		return;
	}
	else {
		struct TreeNode* temp;

		/* Check the subtrees */
		mirrorRecur(root->left);
		mirrorRecur(root->right);

		/* swap the pointers in this node */
		temp        = root->left;
		root->left  = root->right;
		root->right = temp;
	}
}

void swap(struct TreeNode* left, struct TreeNode* right){
	/* swap the pointers in this node */
	struct TreeNode* temp = left;
	left  = right;
	right = temp;
}

void mirrorIterative(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    struct TreeNode* temp;
    enQueue(q, root);

    // Do BFS.
    // While doing BFS, keep swapping left and right children
    while (!isQueueEmpty(q)) {
    	// pop top node from queue
        temp = deQueue(q);

        // swap left child with right child
        swap(temp->left, temp->right);

        // push left and right children
        if (temp->left)
        	enQueue(q, temp->left);

        if (temp->right)
            enQueue(q, temp->right);
    }
}

// Check if 2 Trees are mirror images of each other
int areMirror(struct TreeNode* a, struct TreeNode* b){
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;

    // If only one is empty
    if (a==NULL || b == NULL)
        return false;

    /* Both non-empty, compare them recursively.
     * Note that in recursive calls,
     * we pass left of one tree and right of other tree */
    return  (a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left));
}
