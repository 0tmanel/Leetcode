#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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
  bool ft_check(TreeNode* root, long min, long max)
  {
    if (root == NULL)
    {
        return true;
    }
    if(root->val < min || root->val > max)
    {
        return false;
    }
     
    return ft_check(root->left, min, root->val) && ft_check(root->right, root->val, max);

  }
bool isValidBST(struct TreeNode* root) {
   
    return ft_check(root, LONG_MIN, LONG_MAX);
   
}
int main ()
{
    int num = 2;
    TreeNode *root = btree_create_node(num);
    int num1 = 1;
    int num2 = 3;
     root->left = btree_create_node(num1);
    root->right = btree_create_node(num2); 
   int result =  isValidBST(root);
   printf("%d", result);
    
}