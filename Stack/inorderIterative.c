#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
  struct TreeNode *left;
  struct TreeNode *right;
  int val;
} TreeNode;
typedef struct stack
{
  struct TreeNode *node;
  struct stack *next;
} stack;
void traverseTree(TreeNode *root);
TreeNode *btree_create_node(int item)
{
  TreeNode *node;
  node = malloc(sizeof(TreeNode));
  if (node == NULL)
  {
    return NULL;
  }
  node->val = item;
  node->left = NULL;
  node->right = NULL;
  return node;
}
void traverseTree(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  stack *top = NULL;
  stack *new_node;
  while (root != NULL)
  {
    new_node = malloc(sizeof(stack));
    new_node->node = root;
    new_node->next = top;
    top = new_node;
    root = root->left;
  }

  while (top != NULL)
  {
  stack *current = top;
  top = top->next;
    printf("%d", current->node->val);
    if (current->node->right)
    {
      root = current->node->right;
      while (root != NULL)
      {
        new_node = malloc(sizeof(stack));
        new_node->node = root;
        new_node->next = top;
        top = new_node;
        root = root->left;
      }
    }

    stack *temp = current; // Store the current node for freeing later
        current = current->next;
        free(temp);
  }
}
int main()
{
  int num = 1;
  TreeNode *root = btree_create_node(num);
  int num1 = 2;
  int num2 = 3;
  int num3 = 4;
  int num4 = 5;
  int num5 = 6;
  int num6 = 7;
 
  root->left = btree_create_node(num1);
  root->right = btree_create_node(num2);
  root->left->left = btree_create_node(num3);
  root->left->right = btree_create_node(num4);
  root->right->right = btree_create_node(num5);
  root->right->left = btree_create_node(num6);

  traverseTree(root);
}