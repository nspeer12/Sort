#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct avlavlNode
{
	int data;
	int height;
	struct avlNode *left;
	struct avlNode *right;
} avlNode;

avlNode * createavlNode(int data)
{
	avlNode * newavlNode;

	if(newavlNode = malloc(sizeof(avlNode)) == NULL)
		return;

	newavlNode->data = data;
	newavlNode->left = NULL;
	newavlNode->right = NULL;
	newavlNode->height = 0;

	return newavlNode;
}

int getHeight(avlNode * root)
{
	if(root == NULL)
		return -1;

	return root->height;
}

int balanceFactor(avlNode * root)
{
	if(root == NULL)
		return -1;

	return getHeight(root->left) - getHeight(root->right);
}
int main(void)
{



	return 0;
}
