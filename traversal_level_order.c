/* level_order_traversal.c | Created on: May 28, 2018 * Author: Harsh */

//int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
//
//    if(root==NULL)
//    	return NULL;
//
//    int** ret=(int**)malloc(4080*sizeof(int*));
//    *columnSizes=(int*)malloc(4080*sizeof(int));
//    enqueue(root);
//    ret[0]=(int*)malloc(sizeof(int));
//    *returnSize=0;
//
//    int next=0; //how many nodes in next level
//    int count=0; //how many node get in this level
//    int cur=1; //how many node in this level
//    int num=0;
//    while(front != NULL){
//        struct TreeNode* p= (struct TreeNode*) dequeue();
//        ret[*returnSize][count]=p->val;
//        count++;
//
//        if(p->left){
//            enqueue(p->left);
//            next++;
//
//        }
//        if(p->right){
//            enqueue(p->right);
//            next++;
//        }
//
//        if(cur==count){
//            num++;
//            (*columnSizes)[*returnSize] = cur;
//            (*returnSize)++;
//            ret[*returnSize]=(int*)malloc(next*sizeof(int));
//            cur=next;
//            next=count=0;
//        }
//    }
//
//   //Upside is the answer to the Binary Tree Level Order Traversal I
//
// //Below is how i do for question Binary Tree Level Order Traversal II
//
//    int** ret1=(int**)malloc(*returnSize*sizeof(int*));
//    int i;
//    for(i=0;i<*returnSize;i++){
//        ret1[i]=(int*)malloc((*columnSizes)[*returnSize-i-1]*sizeof(int));
//        ret1[i]=ret[*returnSize-1-i];
//
//    }
//    return ret1;
//}

#include "binary_tree.h"
/*
 * Given a Binary Tree:
 * 			1
 * 		   / \
 * 		  2   3
 * 		 / \
 * 		4   5
 * Level order traversal of the above tree is 1 2 3 4 5
 */

/* METHOD 1: Use Queue
 * Algorithm:
 * For each node, first the node is visited and then it’s child nodes are put in a FIFO queue.
 *
 * printLevelorder(tree)
 * 1) Create an empty queue q
 * 2) temp_node = root 			//start from root
 * 3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children (first left then right children) to q
    c) Dequeue a node from q and assign it’s value to temp_node
 */
void levelOrderTraversal(struct TreeNode* root){
	printf("Level Order Traversal - Using Queue\n");
	if(!root)
		return;

	struct TreeNode* temp;
	struct Queue* q = createQueue();
	enQueue(q, root);

	while(!isQueueEmpty(q)){
		temp = deQueue(q);
		printf("%d ", temp->data);

		if(temp->left != NULL)
			enQueue(q, temp->left);

		if(temp->right)
			enQueue(q, temp->right);
	}
}


/* Level Order Traversal Line By Line
 * Given a binary tree, print level order traversal in a way that nodes of
 * all levels are printed in separate lines.
 */
void levelOrderTraversalLine(struct TreeNode* root){
	printf("Level Order Traversal - Line by Line\n");
	if(!root)
			return;

	struct TreeNode* temp;
	struct Queue* q = createQueue();
	enQueue(q, root);

	while(1){
		int nodeCount = queueSize(q);
		if(nodeCount == 0)
			break;

		while(nodeCount>0){
			temp = deQueue(q);
			printf("%d ", temp->data);

			if(temp->left != NULL)
				enQueue(q, temp->left);

			if(temp->right)
				enQueue(q, temp->right);

			nodeCount--;
		}
		printf("\n");
	}
}

/* Level Order Traversal : Line by Line : Using 2 Queues
 * 1. Create 2 Queues
 * 2. Insert the 1st level in the first queue
 * 3. Print it while dequeuing from the 1st queue.
 * 4. Insert the left and right children into the second queue.
 * 5. Now start printing the second queue
 *    Before dequeuing from the second queue insert its left and right children
 *    to first queue.
 * 6. Continue this process until the queue becomes empty.
 */

void levelOrderTraversalLine2(struct TreeNode* root){
	printf("Level Order Traversal - Line by Line Using 2 Queues\n");
	if(!root)
			return;

	struct TreeNode* temp;
	struct Queue* q1 = createQueue();
	struct Queue* q2 = createQueue();

	// Enqueue the 1st level in Queue1
	enQueue(q1, root);

	// Loop till both the queues become empty
	while(!isQueueEmpty(q1) || !isQueueEmpty(q2)){

		while(!isQueueEmpty(q1)){
			temp = deQueue(q1);
			printf("%d ", temp->data);

			// Push the Left and Right child of the TreeNode from q1 on to q2
			if(temp->left != NULL){
				enQueue(q2, temp->left);
			}

			if(temp->right != NULL){
				enQueue(q2, temp->right);
			}
		}

		printf("\n");

		while(!isQueueEmpty(q2)){
			temp = deQueue(q2);
			printf("%d ", temp->data);

			// Push the Left and Right child of the TreeNode from q1 on to q2
			if(temp->left != NULL){
				enQueue(q1, temp->left);
			}

			if(temp->right != NULL){
				enQueue(q1, temp->right);
			}
		}

		printf("\n");
	}
}



