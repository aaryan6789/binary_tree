/*
 * diameter.c
 *
 *  Created on: May 30, 2018
 *      Author: Harsh
 */
#include "binary_tree.h"

int max(int a, int b){
	if(a>=b)
		return a;
	else
		return b;
}

int diameter(struct TreeNode* root){
	if(root == NULL)
		return 0;

	int lheight = maxDepthR(root->left);
	int rheight = maxDepthR(root->right);

	int ldia = diameter(root->left);
	int rdia = diameter(root->right);

	int maxDia = (ldia>rdia ? ldia:rdia);

	int ret = max(maxDia, lheight+rheight+1);
	//printf("Diameter of Tree:%d is %d\n", root->data, ret);
	return ret;
}
