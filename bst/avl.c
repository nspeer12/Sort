#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	int height;
	struct node *left;
	struct node *right;
} node;

node * createNode(int data)
{
	node * newNode;

	if(newNode = malloc(sizeof(node))) == NULL
		return;

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 0;

	return newNode;
}

int main(void)
{



	return 0;
}
