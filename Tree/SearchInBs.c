#include <stdlib.h>
 #include <stdio.h>
 
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
    struct TreeNode *node =( struct TreeNode*) malloc(sizeof(struct TreeNode));
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

struct TreeNode* searchBST(struct TreeNode* root, int val)
  {
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val > val)
    {
     return searchBST(root->left, val);
    }
    else if(root->val == val)
    {
        return root;
    }
    else
    {
        return searchBST(root->right, val);
    }
  }
  int main ()
{
    int a = 4;
    int b = 2;
    int c = 3;
    int d = 1;
    int bb = 6;
    int cc = 7;
    int dd = 5;
    struct TreeNode * node = btree_create_node(a);;
    node->left = btree_create_node(b);
    node->left->left = btree_create_node(d);
    node->left->right = btree_create_node(c);
     node->right = btree_create_node(bb);
    node->right->left = btree_create_node(dd);
    node->right->right = btree_create_node(cc);
   int item = 9;
    struct TreeNode* data = searchBST(node, 6);
         btree_apply_infix(data);
}