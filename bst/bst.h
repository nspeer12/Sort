#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
     int data;
     struct node *left;
     struct node *right;
} node;

int treeDiff(node *a, node *b)
{
     // return 0 if similar
     // return 1 if not similar

     if(a == NULL && b == NULL)
          return 0;

     if(a == NULL || b == NULL)
          return 1;

     if(treeDiff(a->left, b->left) == 1)
          return 1;

     if(treeDiff(a->right, b->right) == 1)
          return 1;

     if(a->data == b->data)
          return 1;
}

int countOneChild(node * root)
{
     // write a recursive function that counts how many nodes in a tree have a single countOneChilde

     if(root == NULL)
          return 0;

     if(root->left != NULL && root->right == NULL)
          return 1 + countOneChild(root->left);

     if(root->left == NULL && root->right != NULL)
          return 1 + countOneChild(root->right);

     if(root->left != NULL && root->right != NULL)
          return countOneChild(root->right) + countOneChild(root->right);

}

node *largest(node *root)
{
     // recursively find the largest node in the tree
     if(root == NULL)
          return NULL;

     if(root->right != NULL)
          return largest(root->right);
     else
          return root;
}

node * createNode(node * root, int data)
{


     if(root == NULL)
     {
         root = malloc(sizeof(node));
         root->data = data;
         return root;
     }
}

void insertNode(node *root, int data)
{
     if(root == NULL)
          return;

     if(data < root->data && root->left == NULL)
     {
          root->left = malloc(sizeof(node));
          root->left->data = data;
          return;
     }

     if(data > root->data && root->right == NULL)
     {

          root->right = malloc(sizeof(node));
          root->right->data = data;
          return;
     }

     if(data < root->data)
         insertNode(root->left, data);

     if(data > root->data)
         insertNode(root->right, data);

     return;
}

int countNodes(node * root)
{
     if(root == NULL)
          return 0;

     return 1 + countNodes(root->right) + countNodes(root->left);

}

int countLeafNodes(node * root)
{
     if(root == NULL)
          return 0;

     if(root->left == NULL && root->right == NULL)
          return 1;

     return countLeafNodes(root->left) + countLeafNodes(root->right);

}

void printInOrder(node * root)
{
     if(root != NULL)
     {
          printInOrder(root->left);
          printf("%d ", root->data);
          printInOrder(root->right);
     }
}

void printPostOrder(node * root)
{
     if(root != NULL)
     {
          printPostOrder(root->left);
          printPostOrder(root->right);
          printf("%d ", root->data);
     }

     return;



}
void printPreOrder(node * root)
{
     if(root != NULL)
     {
          printf("%d ", root->data);
          printPreOrder(root->left);
          printPreOrder(root->right);
     }

}

void insertNodeIteratively(node * root, int data)
{
     node * tmp = root;
     while(tmp != NULL)
     {
        // printf("tmp %d\n", tmp->data);
          if(data >= tmp->data)
          {
            //   printf("%d is greater than %d", data, tmp->data);
               if(tmp->right != NULL)
                    tmp = tmp->right;
               else
               {
                    tmp->right = malloc(sizeof(node));
                    tmp->right->data = data;
                    break;
               }
          }

          if(data < tmp->data)
          {
              if(tmp->left != NULL)
                    tmp = tmp->left;
              else
              {
                   tmp->left = malloc(sizeof(node));
                   tmp->left->data = data;
                   break;
              }
         }

         if(data == tmp->data)
          break;
     }
}

node * destroyTreeRecursively(node * root)
{
     if (root == NULL) return NULL;

     destroyTreeRecursively(root->left);
     destroyTreeRecursively(root->right);
     free(root);

     return NULL;
}
