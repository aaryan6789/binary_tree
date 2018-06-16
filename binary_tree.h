/* binary_tree.h * Created on: May 20, 2018 *      Author: Harsh */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define true 1
#define false 0
#define bool int

// Representation of the Tree Node
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

//===============================================================
// Helper Queue Structure
//===============================================================
struct Qnode{
	struct TreeNode* tnode;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front;
	struct Qnode* rear;
};

//===============================================================
// Methods on Queue
// ==============================================================
struct Queue* createQueue();
void enQueue(struct Queue* q, struct TreeNode* treeNode);
struct TreeNode* deQueue(struct Queue* q);
int isQueueEmpty(struct Queue* q);
int queueSize(struct Queue* q);
void printQueue(struct Queue* q);

//===============================================================
// Helper Stack Structure (by a Linked List)
// Stack node contains a pointer to tree node and a pointer to next stack node.
//===============================================================
struct Lstack{
	struct TreeNode* tnode;
	struct Lstack *next;
};
//===============================================================
// Methods on Stack
// ==============================================================
void Lpush(struct Lstack** head_ref, struct TreeNode* tn);
struct TreeNode* Lpop(struct Lstack** head_ref);
int Ltop(struct Lstack *head);
int isLStackEmpty(struct Lstack *head);
void print_Lstack(struct Lstack* top);

//===============================================================
// Helper Hash Table Structures
//===============================================================
struct ht_node{
	int key;					// Key
	struct TreeNode* value;		// Value
	struct ht_node* next;		// Pointer to the next element is the list
};

struct list{
	int key;					// Key for the htable
	struct ht_node* treeNode;	// Pointer to the TreeNodes maching the same key
	struct list* next;			// Pointer to the next list
};

// Array of Linked Lists
struct hash_table{
	int count;
	struct list* front;			// Pointer to the first node in the list list
};
//===============================================================
// Methods on Hash Table
// ==============================================================
struct hash_table* create_ht();
int find_list(struct hash_table* ht, int in_key);
struct list* get_list(struct hash_table* ht, int in_key);
void ht_insert(struct hash_table *ht, int key, struct TreeNode* tnode);
int ht_key_search(struct hash_table *ht, int search_key);

void print_hash_table(struct hash_table* ht);


// Utility Functions
int max(int a, int b);
//===============================================================
// Methods on Tree
// ==============================================================
// Tree Methods: Basic
int size(struct TreeNode* root);
int size2(struct TreeNode* root);
int maxDepthR(struct TreeNode* root);
int maxDepthI(struct TreeNode* root);
int diameter(struct TreeNode* root);

// Tree Path
int hasPathSum(struct TreeNode* root, unsigned int sum);
void allPaths(struct TreeNode* root);
void printPathsRecur(struct TreeNode* root, int path[], int pathLen);

// Tree Traversals
void preOrderTraversalR(struct TreeNode* root);
void preOrderTraversalI(struct TreeNode* root);
void inOrderTraversalR(struct TreeNode* root);
void inOrderTraversalI(struct TreeNode* root);
void postOrderTraversalR(struct TreeNode* root);
void postOrderTraversalI(struct TreeNode* root);
void levelOrderTraversal(struct TreeNode* root);
void levelOrderTraversalLine(struct TreeNode* root);
void reverseLevelOrderTraversal(struct TreeNode* root);
void levelOrderTraversalLine2(struct TreeNode* root);

void zigzagTraversalI(struct TreeNode* root);
void verticalOrderTraversalR(struct TreeNode* root);
void verticalOrderTraversalI(struct TreeNode* root);

void top_view(struct TreeNode* root);

void averageOfLevels(struct TreeNode* root);
void averageOfLevels2(struct TreeNode* root);

int longestSameValuePath(struct TreeNode* root);

// Tree Comparisons
bool isSubtree(struct TreeNode *T, struct TreeNode *S);

// Tree Modifications
struct TreeNode* invertTreeR(struct TreeNode* root);

#endif /* BINARY_TREE_H_ */
