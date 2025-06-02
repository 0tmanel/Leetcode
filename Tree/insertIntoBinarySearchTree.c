#include <stdio.h>
#include <stdlib.h>
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 void print(int data)
 {
    printf("%d\n", data);
 }
  void btree_apply_infix(struct TreeNode *root)
  {
    if(!root)
    {
        return;
    }
    btree_apply_infix(root->left);
    print(root->val);
    btree_apply_infix(root->right);
  }
 struct TreeNode *btree_create_node(int item)
 {
    struct TreeNode *node = malloc(sizeof( struct TreeNode));
    if(!node)
    {
        return NULL;
    }
    else{
        node->val = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
 }
struct TreeNode* insertIntoBST(struct TreeNode** root, int val) {
    if(!(*root))
    {
        *root = btree_create_node(val);
    }
    if((*root)->val > val)
    {
       //root->left =
        insertIntoBST(&(*root)->left, val);
    }else if((*root)->val < val)
    {
       //root->right = 
        insertIntoBST(&(*root)->right, val);
    }
     return *root;
}
 int main ()
{
    int a = 4;
    int b = 2;
    int c = 1;
    int d = 3;
    int bb = 7;
    struct TreeNode * node = btree_create_node(a);
    node->left = btree_create_node(b);
    node->left->left = btree_create_node(c);
    node->left->right = btree_create_node(d);
     node->right = btree_create_node(bb);
    struct TreeNode* root =  insertIntoBST(&node, 5);
     btree_apply_infix(root);
}