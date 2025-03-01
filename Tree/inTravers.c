#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode {
    int* data;  // Pointer to the TreeNode (or any data type)
    struct StackNode* next;  // Pointer to the next node in the stack
} StackNode;
typedef struct Stack {
    StackNode* top;  // Pointer to the top node of the stack
} Stack;

TreeNode *btree_create_node(void *item)
  {
    TreeNode *node;
    node = malloc(sizeof(TreeNode));
    if(node == NULL)
    {
        return NULL;
    }
    node->val = item;
    node->left = NULL;
    node->right = NULL;
    return node ;
  }
  int* arr ;
 int size;
void inorder(struct TreeNode* node){
    if(!node){
        return;
    }
    inorder(node->left);
    arr = (int*)realloc(arr,sizeof(int)*++size);
    arr[size-1] = *(int*)node -> val;
    inorder(node->right);
} 
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    size = 0 ;
    arr = NULL;
    inorder(root);
    *returnSize = size;
    return arr;
}
int main ()
{
    int num = 1;
    void* nm = &num;
    TreeNode *root = btree_create_node(nm);
    int num1 = 2;
    int num2 = 3;
    int num3 = 4;
    int num4 = 5;
    int num5 = 6;
    int num6 = 7;
    void *nm1 = &num1 ;
    void  *nm2 = &num2;
    void *nm3 = &num3;
    void *nm4 = &num4;
    void *nm5 = &num5;
    void *nm6 = &num6;
   
    root->left = btree_create_node(nm1);
    root->right = btree_create_node(nm2);
    root->left->left = btree_create_node(nm3);
    root->left->right = btree_create_node(nm4);
     root->right->right = btree_create_node(nm5);
    root->right->left = btree_create_node(nm6);
    int returnSize = 7;
    int *array = inorderTraversal(root, &returnSize);
    int i = 0;
    while (i  <= returnSize)
    {
        printf("%d\n", array[i]);
       i++;
    }
   
}  