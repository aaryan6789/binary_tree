#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1

/* Helper function that allocates a new node with the given data
   and NULL left and right pointers. */
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(!node){
    	printf("Tree node malloc Failed\n");
    	return NULL;
    }

    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    //printf("node->data = %d\n", node->data);
    return(node);
}

/* Driver program to test above function */
int main() {
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct TreeNode *T    = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct TreeNode *S  = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);


    struct TreeNode *R = newNode(1);
    R->left = newNode(2);
	R->right = newNode(3);
	R->left->left = newNode(4);
	R->left->right = newNode(5);
	R->right->left = newNode(6);
	R->right->right = newNode(7);
	R->right->left->right = newNode(8);
	R->right->right->right = newNode(9);
	R->right->right->left= newNode(10);
	R->right->right->left->right= newNode(11);
	R->right->right->left->right->right= newNode(12);

    printf("S->data = %d\n", S->data);
    printf("Done Making Tree.\n");
    printf("-------- Tree Basic Methods -----------\n");
    size2(S);
    size2(T);

    int depth = maxDepthR(S);
    depth = maxDepthI(S);
    printf("Depth of the Tree is %d\n", depth);

    int sum = 0;
    int ret = hasPathSum(T, sum);
    printf("Path with sum = %d is %d {1 = Yes, 0 = No}\n", sum, ret);

    printf("\n-------- Tree Traversal Methods -----------\n");
    printf("PreOrder traversal of the Tree:%d\n", T->data);
    preOrderTraversalR(T);
    preOrderTraversalI(T);
    printf("\n\n");

    printf("PostOrder traversal of the Tree:%d\n", T->data);
    postOrderTraversalR(T);
    postOrderTraversalI(T);
    printf("\n\n");

    printf("InOrder traversal of the Tree:%d\n", T->data);
    inOrderTraversalR(T);
    inOrderTraversalI(T);
    printf("\n\n");

    levelOrderTraversal(S);
    printf("\n");
    levelOrderTraversal(T);
    printf("\n");
    levelOrderTraversalLine(T);

    levelOrderTraversalLine2(T);

    printf("Zig Zag traversal of the Tree:%d\n", T->data);
    zigzagTraversalI(T);
    printf("\n");

    printf("Vertical traversal of the Tree:%d\n", T->data);
    verticalOrderTraversalR(T);
    printf("\n\n");

    averageOfLevels(T);
    averageOfLevels2(T);

    longestSameValuePath(T);

    printf("\nReverse\n");
    reverseLevelOrderTraversal(T);

    int dia = diameter(T);
    printf("Diameter of Tree:%d is %d\n", T->data, dia);

    allPaths(T);

    printf("-------- Tree Comparison Methods -----------\n");
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1\n");
    else
        printf("Tree 2 is not a subtree of Tree 1\n");


    verticalOrderTraversalI(T);

    verticalOrderTraversalI(R);

    top_view(R);

    return 0;
}
