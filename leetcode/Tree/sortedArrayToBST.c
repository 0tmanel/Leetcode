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
TreeNode* Helper(int* nums, int left, int right)
  {
    if(left > right)
    {
        return NULL;
    }
    int mid = left + (right - left) / 2;
    TreeNode* root = btree_create_node(nums[mid]);
   root->left = Helper(nums, left, mid - 1);     
    root->right = Helper(nums, mid + 1, right);
    return root;
  }  
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int i = 0;
    int j = numsSize - 1;
     
    return Helper(nums, i, j);
}
void btree_apply_prefix(TreeNode *root)
{
  if(root == NULL)
  {
    return;
  }
    btree_apply_prefix(root->left);
   printf("%d", root->val);
    btree_apply_prefix(root->right);
}
int main ()
{
    int arr[] = {1, 2, 3, 4, 5};
    int numSize = sizeof(arr) / sizeof(arr[0]);
   TreeNode* tree = sortedArrayToBST(arr, numSize);
   btree_apply_prefix(tree);
   
}