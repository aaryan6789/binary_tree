/*
 * queue.c
 *
 *  Created on: May 29, 2018
 *      Author: Harsh
 */
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

/*
struct Qnode{
	struct TreeNode* tnode;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front;
	struct Qnode* rear;
};
*/

struct Queue* createQueue(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

	q->front = NULL;
	q->rear = NULL;

	return q;
}

// Enqueue a TreeNode in the Queue
// QUEUE is a FIFO Data structure
// EnQueue operation is always on the Rear
void enQueue(struct Queue* q, struct TreeNode* treeNode){

	struct Qnode* newNode = (struct Qnode*)malloc(sizeof(struct Qnode));
	newNode->tnode = treeNode;
	newNode->next = NULL;

	if((q->front == NULL)&&(q->rear == NULL)){
		q->front = q->rear = newNode;
	}
	else{
		/* Add this node at the end of the queue and also
		 * update the rear, pointing to this node */
		q->rear->next = newNode;
		q->rear = newNode;
	}

	//printf("EnQueue %d (%d) in Tree Traversal Queue\n", treeNode->data, q->rear->tnode->data);
	return;
}

// Dequeue from front
struct TreeNode* deQueue(struct Queue* q){
	// Check for empty queue first
	if (q->front == NULL){
		printf("Queue is empty.\n");
		return NULL;
	}

	//printf("Dequeue from Front = %d \n", q->front->tnode->data);

	struct TreeNode* dqTnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	dqTnode = q->front->tnode;
	//printf("Dequeued TreeNode is %d\n", dqTnode->data);

	// update front
	struct Qnode* newFront = q->front->next;
	q->front = newFront;

	// If newFront becomes NULL, then change rear also to NULL
	if (q->front == NULL){
		q->rear = NULL;
	}

	return dqTnode;
}

int isQueueEmpty(struct Queue* q){
	if(q->front == NULL){
		//printf("Queue is Empty\n");
		return 1;
	}
	else{
		return 0;
	}
}

int queueSize(struct Queue* q){
	if(q->front == NULL){
		return 0;
	}

	int qsize = 0;
	struct Qnode* front = q->front;

	while(front){
		front = front->next;
		qsize++;
	}
	//printf("Queue Size = %d\n", qsize);
	return qsize;
}

void printQueue(struct Queue* q){
	if(isQueueEmpty(q))
		return;

	struct Qnode* front = q->front;
	while(front){
		printf("%d ", front->tnode->data);
		front = front->next;
	}
	return;
}

