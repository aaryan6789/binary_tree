/* binary_tree_hash_table.c  * Created on: Jun 12, 2018 * Author: Harsh */
#include "binary_tree.h"
/*
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
*/

/**
 * create_ht - Create a new Hash Table
 * It creates a new hash table by allocating memory as big as the size.
 */
struct hash_table* create_ht(){
	// Allocate Memory to the HASH TABLE
	struct hash_table *ht = (struct hash_table *)malloc(sizeof(struct hash_table));
	if(!ht){
		printf("malloc error on ht.\n");
		return NULL;
	}

	// Set Count of the table to 0 as empty table
	ht->count = 0;

	// Establish separate chaining by allocating memory for each of the node in the table
	// 1. Allocate memory for each linked list node of the hash table.
	// 2. Initialize each node of the Hash table with NULL
	ht->front = NULL;

	//printf("Hash Table of Dynamic Size is created.\n Table Count = %d\n Table Front = %p\n",
	//		ht->count, ht->front);
	return ht;
}

/**
 *  hash_function - Hash Function
 *  It will run the Key value and transforms it into a value to be represented in the
 *  Array as an index.
 */
int hash_function(struct hash_table *ht, int key){
	int hash = key;

	//hash = (hash >> 3) * 2654435761;		// Knuth's Math Method
	//hash = hash / (ht->table_size);			// Divide by table size to fit in table boundaries

	printf("The hash_index for key %d is %d\n", key, hash);
	return hash;							// Index in the table returned
}

int find_list(struct hash_table* ht, int in_key){
	if(ht->front == NULL){
		return 0;
	}

	struct list* current;
	current = ht->front;
	while(current != NULL){
		if(current->key == in_key){
			//printf(" Already Existing List with Key:%d found.\n", in_key);
			return true;
		}
		current = current->next;
	}

	//printf("No List Found.\n");
	return false;

}

struct list* get_list(struct hash_table* ht, int in_key){
	struct list* current = ht->front;

	while(current!= NULL){
		if(current->key == in_key){
			return current;
		}

		current = current->next;
	}

	return NULL;
}

void print_ht_node_list(struct ht_node* head){
	if(head == NULL)
		return;

	struct ht_node *current = head;
	int num_nodes=0;

	// printf("\nPrint List of ht Nodes :\n");
	while(current != NULL) {
		printf("%d ", current->value->data);
		num_nodes++;
		current = current->next;
	}
	printf(" : Number of Nodes: %d", num_nodes);
}


void print_hash_table(struct hash_table* ht){
	printf("HASH TABLE \n");
	if(ht->front == NULL){
		printf("Hash Table is empty\n");
		return;
	}

	struct list* current = ht->front;
	while(current != NULL){
		printf("Key : %d -> ", current->key);
		print_ht_node_list(current->treeNode);

		current = current->next;
		printf("\n");
	}
}

void list_insert(struct hash_table* ht, int in_key, struct TreeNode* tnode){
	struct list* keyList = get_list(ht, in_key);
	//printf("List Is already present, so just add another node in that list\n");

	// Get the first TreeNode for the Key
	struct ht_node* first = keyList->treeNode;

	// If the first node is NULL, then make a newNode and Insert it
	if(first == NULL){
		struct ht_node* htn = (struct ht_node*)malloc(sizeof(struct ht_node));
		htn->key = in_key;
		htn->next = NULL;
		htn->value = tnode;

		keyList->treeNode = htn;
	}
	// Else if there is some node already in the list, then add into it
	else{
		struct ht_node* htn = (struct ht_node*)malloc(sizeof(struct ht_node));
		htn->key = in_key;
		htn->next = NULL;
		htn->value = tnode;

		// Make links in the
		while(first->next != NULL)
			first = first->next;

		first->next = htn;
	}

	//printf("Inserted %d with TreeNode->data = %d in the Table\n",
	//		in_key, tnode->data);
}

/**
 * ht_insert - Insert a key in the hash table
 * In separate chaining Hash table insertion the new key will be inserted in the
 * linked list at the front of the hash value slot for that key.
 */
void ht_insert(struct hash_table *ht, int key, struct TreeNode* tnode){
	// Get the hash slot for the key
	//int hash_index = hash_function(ht, key);
	//printf("Hash_index = for key = %d\n", /*hash_index,*/ key);

	// Check if the key is already there i.e List with this key present already
	if(find_list(ht, key)){
		list_insert(ht, key, tnode);
	}
	// Else if the list is not present
	else if(!find_list(ht, key)) {
		// If the Table is Empty
		if(ht->front == NULL){
			// Make a New List and first list
			struct list* newList = (struct list*)malloc(sizeof(struct list));
			if(!newList){
				printf("malloc Failed for newList when ht_front is NULL.\n");
			}

			newList->key = key;
			newList->next = NULL;

			// Create a new hash Table node in the list
			struct ht_node* newht = (struct ht_node*)malloc(sizeof(struct ht_node));
			newht->value = tnode;
			newht->key = key;
			newht->next = NULL;

			newList->treeNode = newht;
			// Fill in the Hash Table
			ht->front = newList;
		}
		else{
			// There is no list for this key in the existing table
			// Make a New List and add it to the table in the end
			struct list* newList = (struct list*)malloc(sizeof(struct list));
			if(!newList){
				printf("malloc Failed for newList.\n");
			}

			newList->key = key;
			newList->next = NULL;

			// Create a new hash Table node in the list
			struct ht_node* newht = (struct ht_node*)malloc(sizeof(struct ht_node));
			newht->value = tnode;
			newht->key = key;
			newht->next = NULL;

			newList->treeNode = newht;

			struct list* current = ht->front;
			while(current->next != NULL){
				current = current->next;
			}
			current->next = newList;
		}
	}
	else{
		printf("No idea what is happening\n");
	}
	// Increment the count of the hash table elements
	ht->count++;

	/*printf("Inserted %d on the hash map.\n Tables node count %d\n",
			key, ht->count);*/

	return;
}

/**
 * ht_search - Search for a key in the hash table
 * In separate chaining Hash table searching for a key will be in the
 * linked list at the hash value slot for that key.
 */
int ht_search(struct hash_table *ht, int search_key, int search_data){
	printf("Searching %d key and %d data in the hash table\n",
			search_key, search_data);

	// Get the hash index of the list for the key
	//int hash_index = hash_function(ht, search_key);

	if(find_list(ht, search_key)){
		struct list* keyList = get_list(ht, search_key);
		struct ht_node* first = keyList->treeNode;

		while(first->next != NULL){
			if(first->value->data == search_data){
				printf("TreeNode with %d exists.\n", search_data);
				return true;
			}
			else{
				return false;
			}
		}
	}

	return false;

}

/**
 * ht_remove - Remove a key in the hash table
 * When removing from a separately chained hash table, a search is required for
 * the old key. Fortunately, this is the hardest part of the algorithm and the
 * key is gone, which is a welcome change from the other collision resolution strategies.
 *
void ht_remove(struct hash_table *ht, int key){
	printf("Removing %d key from the hash table\n", key);
	// Get the hash index for the key
	int hash_index = hash_function(ht, key);
	int found = ht_search(ht, key);



	struct ht_node *ht_node =  ht->ht_node_list[hash_index];
	int count = 0;

	if(found && ht_node != NULL){
		// Remove the node from the hash Index
		while (ht_node->key != key){
			ht_node = ht_node->next;
			count++;
		}

		printf("ht_node->key = %d count %d ht_node->next->key %d\n", ht_node->key, count, ht_node->next->key);

		if(ht_node->next == NULL){
			free(ht_node);
			ht->element_count--;
			return;
		}

		struct ht_node *next_node = ht_node->next;
		ht_node->key = next_node->key;
		ht_node->next = next_node->next;
		free(next_node);
		ht->element_count--;

		printf("Deleted %d key from the hash table. Elem_count %d\n", key, ht->element_count);
		return;
	}
	else{
		return;
	}

}

*/
