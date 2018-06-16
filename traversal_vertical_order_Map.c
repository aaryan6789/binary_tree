/* traversal_vertical_order_Map.c  * Created on: Jun 12, 2018 * Author: Harsh */
#include "binary_tree.h"
#include "binary_tree_queue_vertical.h"

/* Method 2: Using Queue and Hash Map
 *
 * 1. Create an empty Queue
 * 2. EnQueue root
 * 3. Update hdist for the root to 0.
 * 	  Rule for hdist:
 * 	  1. For Root : hdst = 0
 * 	  2. For Left Child : hdist = hdst - 1 (From the Parent node)
 * 	  3. For right Child: hdist = hdst + 1
 *
 * 4. Add hdst = 0 in the hash Table and root as its value.
 * 5. In a loop untill queue is empty
 * 	  1. Dequeue form the Queue
 * 	  2. Check for the Left child and update hdst in the Hash table, then the right child
 * 	  3. Enqueue the left child and the right child
 */
void verticalOrderTraversalI(struct TreeNode* root){
	// Base Case
	if(root == NULL)
		return;

	int hdist = 0;

	// Create an empty Queue
	struct VQueue *vq = createVQueue();
	enVQueue(vq, root, hdist);
	struct hash_table* ht = create_ht();

	struct TreeNode* tempTnode;
	while(!isVQueueEmpty(vq)){
		// Dequeue from the front
		struct VQnode* temp = deVQueue(vq);
		hdist = temp->hd;
		tempTnode = temp->tnode;

		ht_insert(ht, hdist, tempTnode);

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


