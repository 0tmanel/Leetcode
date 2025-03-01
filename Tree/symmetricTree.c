#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

  bool Helper(TreeNode* left, TreeNode* right)
  {
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    return Helper(left->left, right->right) && Helper(left->right, right->left);
  }
  bool isSymmetric(struct TreeNode* root) {
    if(!root->left && !root->right)
    {
        return true;
    }
    else if(!root->left || !root->right)
    {
        return false;
    }
    else if(root->left->val != root->right->val)
    {
        return false;
    }
   return Helper(root->left, root->right);
}
int main ()
{
    int num = 2;
    TreeNode *p = btree_create_node(num);
    int num1 = 1;
    int num2 = 3;
    int num0 = 4;
    int num01 = 5;
    int num3 = 1;
    int num4 = 2;
    int num5 = 3;
    int num6 = 4;
    int num7 = 5;
     p->left = btree_create_node(num1);
    p->right = btree_create_node(num4); 
    p->left->left = btree_create_node(num2);
    p->left->right = btree_create_node(num0);
     p->right->left = btree_create_node(num6);
    p->right->right = btree_create_node(num5);
  int boole =  isSymmetric(p);
  printf("%d", boole);
}