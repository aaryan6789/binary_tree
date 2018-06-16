/* top_view.c  * Created on: Jun 16, 2018 * Author: Harsh */
#include "binary_tree.h"
#include "binary_tree_queue_vertical.h"

/* Top view of a binary tree is the set of nodes visible when the tree is viewed
 * from the top.
 * Given a binary tree, print the top view of it.
 * The output nodes can be printed in any order.
 * Expected time complexity is O(n)
 *
 * A node x is there in output if x is the topmost node
 * at its horizontal distance.
 * Horizontal distance of left child of a node x is equal to
 * horizontal distance of x minus 1,
 * and that of right child is horizontal distance of x plus 1.
 */

void top_view(struct TreeNode* root){
	// Base Case
	if(root == NULL)
		return;

	int hdist = 0;

	// Create an empty Queue
	struct VQueue *vq = createVQueue();
	enVQueue(vq, root, hdist);

	// Create an empty Hash Table
	struct hash_table* ht = create_ht();

	struct TreeNode* tempTnode;
	while(!isVQueueEmpty(vq)){
		// Dequeue from the front
		struct VQnode* temp = deVQueue(vq);
		hdist = temp->hd;
		tempTnode = temp->tnode;

		// if horizontal dist value is not in the hashmap
		// that means it is the first value with that
		// horizontal distance so print it and store
		// this value in hashmap
		if (!ht_key_search(ht, hdist)) {
			ht_insert(ht, hdist, tempTnode);
			printf("%d ", tempTnode->data);

		}

		if(tempTnode->left)
			enVQueue(vq, tempTnode->left, hdist - 1);

		if(tempTnode->right)
			enVQueue(vq, tempTnode->right, hdist + 1);
	}

	struct list** listRef = &ht->front;
	print_hash_table(ht);
	MergeSort(listRef);
	print_hash_table(ht);

}
