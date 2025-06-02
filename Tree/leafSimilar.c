#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *btree_create_node(int item)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    if (node == NULL)
    {
        return NULL;
    }
    node->val = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void getLeaves(struct TreeNode *root, int *leaves, int *size)
{
     if (root == NULL) return;
     //"A node is a leaf if BOTH left and right are NULL."
    if (root->left == NULL && root->right == NULL)
    {
        leaves[*size] = root->val;
        (*size)++;
        return;
    }
    getLeaves(root->left, leaves, size);
    getLeaves(root->right, leaves, size);
}
bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int leaves1[200];
    int leaves2[200];
    int size1, size2 = 0;
    getLeaves(root1, leaves1, &size1);
    getLeaves(root2, leaves2, &size2);
    //if (size1 != size2) return false;
    int i = 0;
    while (i < size1)
    {
        printf("first leave : %d \n", leaves1[i]);
         printf("second leave: %d \n", leaves2[i]);
         i++;
    }
    while (i < size1)
    {
        if (leaves1[i] != leaves2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
int main()
{
    struct TreeNode *root1 = btree_create_node(1);
     root1->left = btree_create_node(2);
    // root1->right = btree_create_node(3);
    struct TreeNode *root2 = btree_create_node(2);
     root2->left = btree_create_node(2);
    // root2->right = btree_create_node(2);
    int bol = leafSimilar(root1, root2);
    printf("%d\n", bol);
}