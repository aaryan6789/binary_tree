/* binary_tree_merge_sort.c  * Created on: Jun 16, 2018 * Author: Harsh */
#include "binary_tree.h"
#include "binary_tree_queue_vertical.h"

void FrontBackSplit(struct list* source, struct list** frontRef, struct list** backRef);
struct list* SortedMerge(struct list* a, struct list* b);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct list** headRef) {
	struct list* head = *headRef;
	struct list* a;
	struct list* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)){
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https://www.geeksforgeeks.org/?p=3622 for details of this function */
struct list* SortedMerge(struct list* a, struct list* b) {
	struct list* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->key <= b->key)	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

/* Split the nodes of the given list into front and back halves,
 * and return the two lists using the reference parameters.
 *
 * If the length is odd, the extra node should go in the front list.
 * Uses the fast/slow pointer strategy.
 */
void FrontBackSplit(struct list* source, struct list** frontRef, struct list** backRef) {
    struct list* fast;
    struct list* slow;

    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
    	fast = fast->next;
    	if (fast != NULL) {
    		slow = slow->next;
    		fast = fast->next;
    	}
    }

    /* 'slow' is before the midpoint in the list, so split it in two at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
