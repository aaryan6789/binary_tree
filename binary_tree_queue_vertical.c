/* binary_tree_queue_vertical.c  * Created on: Jun 15, 2018 * Author: Harsh */
#include "binary_tree.h"
#include "binary_tree_queue_vertical.h"

/*
struct VQnode{
	struct TreeNode* tnode;
	struct VQnode* next;
};

struct VQueue{
	struct VQnode* front;
	struct VQnode* rear;
};
*/

struct VQueue* createVQueue(){
	struct VQueue* q = (struct VQueue*)malloc(sizeof(struct VQueue));

	q->front = NULL;
	q->rear = NULL;

	return q;
}

// Enqueue a TreeNode in the VQueue
// QUEUE is a FIFO Data structure
// EnQueue operation is always on the Rear
void enVQueue(struct VQueue* q, struct TreeNode* treeNode, int hd){
	struct VQnode* newNode = (struct VQnode*)malloc(sizeof(struct VQnode));
	newNode->tnode = treeNode;
	newNode->next = NULL;
	newNode->hd = hd;

	if((q->front == NULL)&&(q->rear == NULL)){
		q->front = q->rear = newNode;
	}
	else{
		/* Add this node at the end of the queue and also
		 * update the rear, pointing to this node */
		q->rear->next = newNode;
		q->rear = newNode;
	}

	//printf("EnQueue %d (%d) in Tree Traversal VQueue\n", treeNode->data, q->rear->tnode->data);
	return;
}

// Dequeue from front
struct VQnode* deVQueue(struct VQueue* q){
	// Check for empty queue first
	if (q->front == NULL){
		printf("VQueue is empty.\n");
		return NULL;
	}

	//printf("Dequeue from Front = %d \n", q->front->tnode->data);

	struct VQnode* dqVQnode = (struct VQnode*)malloc(sizeof(struct VQnode));
	dqVQnode = q->front;
	//printf("Dequeued TreeNode is %d\n", dqTnode->data);

	// update front
	struct VQnode* newFront = q->front->next;
	q->front = newFront;

	// If newFront becomes NULL, then change rear also to NULL
	if (q->front == NULL){
		q->rear = NULL;
	}

	return dqVQnode;
}

int isVQueueEmpty(struct VQueue* q){
	if(q->front == NULL){
		//printf("VQueue is Empty\n");
		return 1;
	}
	else{
		return 0;
	}
}

int VqueueSize(struct VQueue* q){
	if(q->front == NULL){
		return 0;
	}

	int qsize = 0;
	struct VQnode* front = q->front;

	while(front){
		front = front->next;
		qsize++;
	}
	//printf("VQueue Size = %d\n", qsize);
	return qsize;
}

void printVQueue(struct VQueue* q){
	if(isVQueueEmpty(q))
		return;

	struct VQnode* front = q->front;
	while(front){
		printf("%d ", front->tnode->data);
		front = front->next;
	}
	return;
}
