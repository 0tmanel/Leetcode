#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
}TreeNode;
TreeNode *btree_create_node(int item)
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
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
 {
    if(!p  && !q)
    {
        return true;
    }else if (p == NULL &&  q != NULL || p != NULL && q == NULL)
    {
        return false;
    }else if (p->val != q->val)
    {
        return false;
    }else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
}
int main ()
{
    int num = 1;
    TreeNode *p = btree_create_node(num);
    int num1 = 2;
    int num2 = 3;
    int num0 = 4;
    int num01 = 9;
    int num3 = 1;
    TreeNode *q = btree_create_node(num3);
    int num4 = 2;
    int num5 = 3;
    int num6 = 4;
    int num7 = 9;
     p->left = btree_create_node(num1);
    p->right = btree_create_node(num2); 
    p->left->left = btree_create_node(num0);
    p->left->right = btree_create_node(num01);
    q->left = btree_create_node(num4);
     q->right = btree_create_node(num5);
     q->left->left = btree_create_node(num6);
    q->left->right = btree_create_node(num7);
  int boole =  isSameTree(p, q);
  printf("%d", boole);
}