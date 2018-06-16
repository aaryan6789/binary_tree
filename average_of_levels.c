/* average_of_levels.c  * Created on: May 31, 2018 * Author: Harsh */

#include "binary_tree.h"
/* Average of Levels of a Binary Tree
 * Given a binary tree, print level order traversal in a way that nodes of
 * all levels are printed in separate lines.
 */
void averageOfLevels(struct TreeNode* root){
	printf("Level Order Traversal - Average\n");
	if(!root)
			return;

	struct TreeNode* temp;
	struct Queue* q1 = createQueue();
	struct Queue* q2 = createQueue();
	enQueue(q1, root);

	while(!isQueueEmpty(q1) || !isQueueEmpty(q2)){
		int sum = 0;
		int size = 0;
		while(!isQueueEmpty(q1)){
			temp = deQueue(q1);
			printf("%d ", temp->data);
			size++;
			sum = sum + temp->data;

			if(temp->left){
				enQueue(q2, temp->left);
			}

			if(temp->right){
				enQueue(q2, temp->right);
			}
		}

		//printf("Size of q1 = %d\n", size);
		printf("Average of Level = %d %d \n", sum, sum/size);

		sum = 0;
		size = 0;
		while(!isQueueEmpty(q2)){
			temp = deQueue(q2);
			size++;
			printf("%d ", temp->data);
			sum = sum + temp->data;

			if(temp->left){
				enQueue(q1, temp->left);
			}

			if(temp->right){
				enQueue(q1, temp->right);
			}
		}

		//printf("Size of q2 = %d", size);
		printf("Average of Level = %d %d \n", sum, sum/size);
	}
}

/* Average of Levels: Using 2 Queues:
 *
 *1. Start by pushing the root node into the queue.
 *    Then, remove a node from the front of the queue.
 *2. For every node removed from the queue, push all its children into a new temporary queue.
 *3. Keep on popping nodes from the queue and adding these node’ s children
 *    to the temporary queue till queue becomes empty.
 *4. Every time queue becomes empty, it indicates that one level of the tree has been considered.
 *5. While pushing the nodes into temporary queue,
 *    keep a track of the sum of the nodes along with the number of nodes pushed and
 *    find out the average of the nodes on each level by making use of these sum and count values.
 *6. After each level has been considered,
 *    again initialize the queue with temporary queue and
 *    continue the process till both queues become empty.
 */
void averageOfLevels2(struct TreeNode* root){
	printf("Level Order Traversal - Average 2\n");
	if(!root)
			return;

	struct TreeNode* temp;
	struct Queue* q1 = createQueue();

	enQueue(q1, root);

	while(!isQueueEmpty(q1)){
		int sum = 0;
		int size = 0;
		struct Queue* tempQ = createQueue();
		while(!isQueueEmpty(q1)){
			temp = deQueue(q1);
			printf("%d ", temp->data);
			size++;
			sum = sum + temp->data;

			if(temp->left){
				enQueue(tempQ, temp->left);
			}

			if(temp->right){
				enQueue(tempQ, temp->right);
			}
		}
		q1 = tempQ;

		//printf("Size of q1 = %d\n", size);
		printf("Average = %d %f \n", sum, sum*(1.0)/size);
	}
}
