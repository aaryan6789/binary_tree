/* maxDepth.c * Created on: May 28, 2018 * Author: Harsh */
#include "binary_tree.h"
/* 104 LeetCode E
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path
 *  from the root node down to the farthest leaf node.
 * Note: A leaf is a node with no children.
 *
 * Example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 * return its depth = 3.
 */

// Max Depth of a Binary Tree is the path that is the longest from the Root to a Leaf in the Tree.
// Recursive Algorithm:
//1. Base Case: If root is NULL then return 0
//2. Recur Case:
// a. Get the Max Depth of the Left Sub Tree
// b. Get the MAx depth of the Right Sub Tree
// c. Compare the leftDepth and rightDepth and return the Max of the 2.
int maxDepthR(struct TreeNode* root) {
    // Base Case
    if(root == NULL)
        return 0;
    // Recursive Case
    else{
        int leftDepth = maxDepthR(root->left);
        int rightDepth = maxDepthR(root->right);

        if(leftDepth > rightDepth){
            return (leftDepth+1);
        }
        else{
            return (rightDepth+1);
        }
    }
}


/* Method 2 : Iterative
 * 1. Create a queue.
 * 2. EnQueue root into the queue.
 * 	  Initialize height = 0
 * 3. Loop continously
 *   a. Get the	nodeCount = size of queue
 *   b. If number of nodes at this level is 0, then return height. (Terminating Condition)
 * 		else Increase Height.
 *   c. Remove nodes of this level and add nodes of next level
 *    	while (nodeCount > 0)
			DeQueue node from front
			push its children to queue
			decrease nodeCount
   At this point, queue has nodes of next level
 */
int maxDepthI(struct TreeNode* root) {
	if(!root)
		return 0;

	struct TreeNode* temp;
	struct Queue* q = createQueue();
	enQueue(q, root);
	int depth = 0;

	while(1){
		// nodeCount indicates number of nodes at current level
		int nodeCount = queueSize(q);
		if(nodeCount == 0)
			return depth;
		else
			depth++;

		// Dequeue all nodes of current level and Enqueue all nodes of next to current level
		while(nodeCount > 0){
			temp = deQueue(q);
			printf("%d \n", temp->data);

			if(temp->left != NULL)
				enQueue(q, temp->left);

			if(temp->right)
				enQueue(q, temp->right);

			nodeCount--;
		}
	}
}


