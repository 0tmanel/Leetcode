#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    void *val;
}TreeNode;
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
 
struct TreeNode* invertTree(struct TreeNode* root)
{
    TreeNode *item;
    if (root == NULL )
    {
        return NULL ;
    }
    item = root->left;
    root->left= root->right;
    root->right = item;
    invertTree(root->left);
    printf("%d", *(int*)root->val);
    invertTree(root->right);
    
    return root;
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
     void *nm1 = &num1;
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

   invertTree(root);
}