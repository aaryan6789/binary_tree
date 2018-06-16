/* binary_tree_queue_vertical.h  * Created on: Jun 15, 2018 * Author: Harsh */
#include "binary_tree.h"

#ifndef BINARY_TREE_QUEUE_VERTICAL_H_
#define BINARY_TREE_QUEUE_VERTICAL_H_
//===============================================================
// Helper Queue Structure
//===============================================================
struct VQnode {
	int hd;
	struct TreeNode* tnode;
	struct VQnode* next;
};

struct VQueue{
	struct VQnode* front;
	struct VQnode* rear;
};

//===============================================================
// Methods on Queue
// ==============================================================
struct VQueue* createVQueue();
void enVQueue(struct VQueue* q, struct TreeNode* treeNode, int hd);
struct VQnode* deVQueue(struct VQueue* q);
int isVQueueEmpty(struct VQueue* q);
int VqueueSize(struct VQueue* q);
void printVQueue(struct VQueue* q);

void MergeSort(struct list** headRef) ;

#endif /* BINARY_TREE_QUEUE_VERTICAL_H_ */
