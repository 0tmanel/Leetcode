
#include <stdlib.h>
#include <stdio.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
struct TreeNode *btree_create_node(int item)
 {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
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
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

  int left = maxDepth(root->left);
   int right =  maxDepth(root->right);
   return (left > right ? left : right) + 1;

}
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int bb = 5;
    int cc = 6;
    int dd = 7;
    struct TreeNode *node = btree_create_node(a);
    node->left = btree_create_node(b);
    node->left->left = btree_create_node(c);
    node->left->right = btree_create_node(d);
    node->right = btree_create_node(bb);
    node->right->left = btree_create_node(cc);
    node->right->right = btree_create_node(dd);
    int level = maxDepth(node);
    printf("%d\n", level);
}
/*Let’s say the tree is:

mathematica

        A
       / \
      B   C
     / \
    D   E
Nodes:

root = A

root->left = B

root->right = C

root->left->left = D

root->left->right = E

🔍 What happens with this code:
c
Copy
Edit
int left = maxDepth(root->left);
int right = maxDepth(root->right);
Suppose you're at root = A.

This means:

First, the line int left = maxDepth(root->left); is executed.

This pauses execution of the current function (A).

It goes into a new call: maxDepth(B).

Inside maxDepth(B):

Again, it hits int left = maxDepth(root->left); → calls maxDepth(D).

Inside maxDepth(D):

D has no children, so both maxDepth(NULL) return 0, and it returns 1.

Now back in maxDepth(B), it executes:

int right = maxDepth(root->right); → calls maxDepth(E)

Inside maxDepth(E):

E has no children → returns 1.

Back in maxDepth(B):

Now it can compute max(1, 1) + 1 = 2 and return to maxDepth(A).

Now back in maxDepth(A):

It executes int right = maxDepth(root->right); → calls maxDepth(C)

C has no children → returns 1.

Finally, maxDepth(A) computes: max(2, 1) + 1 = 3.

*/