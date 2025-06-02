#include <stdio.h>
#include <stdlib.h>
 struct ListNode {
      int val;
     struct ListNode *next;
 };
   struct ListNode*ft_create_elem(int data)
{
	struct ListNode* new_node;
	
	new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(new_node)
	{
		new_node->val = data;
		new_node->next = NULL;
	}
	return (new_node);
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
     struct ListNode *head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    int d = 4;
    int e = 5;
    int f = 3;
   
  struct ListNode *head2 = ft_create_elem(d);
    head2->next = ft_create_elem(e);
    head2->next->next = ft_create_elem(f);
    
   struct ListNode *node = oddEvenList(head);
//    while(node)
//     {
//         printf("%d\n", node->val);
//         node = node->next;
//     }
   
}