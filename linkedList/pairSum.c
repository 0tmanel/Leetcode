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
int calcu(struct ListNode* head)
{
    struct ListNode* temp = head;
    int index = 0;
    while(temp)
    {
        index++;
        temp = temp->next;
    }
    return index;
}
int pairSum(struct ListNode* head) {
    int length = calcu(head);
    int i = 0;
    int sum = 0;
    while(i < length)
    {
        if(0 <= i && i <= (length / 2) - 1)
        {
            sum += head->val; 
        }
        head = head->next;
        i++;
    }
    return sum;
}
int main()
{
    int a = 5;
    int b = 4;
    int c = 2;
    int d = 1;
    
  struct ListNode *head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    head->next->next->next = ft_create_elem(d);
  int sum = pairSum(head);
   
        printf("%d\n", sum);
   
}
