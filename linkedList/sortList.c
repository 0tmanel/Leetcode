#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  ListNode
{
    struct ListNode   *next;
    int    data;
}   ListNode;
typedef struct Stack{
    ListNode* top;
}Stack;
ListNode *ft_create_elem(int data)
{
	ListNode* new_node;
	
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if(new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return (new_node);
}

void  merg(ListNode* left, ListNode *right, ListNode* head)
{

}
void merg_sort(ListNode *head)
{
    int len = ft_len(head);
    if(len <= 1 )
    {
        return 
    }

}
struct ListNode* sortList(struct ListNode* head) {
    ListNode *temp1 = head;
    ListNode *temp = head;
    if(head->next == NULL)
    {
        return 0;
    }
    while (temp1 != NULL)
    {
        head = temp; 
    while (head != NULL && head->next != NULL)//make sure next pointer does not accsess boundaries
    {
        if(head->data > head->next->data)
        {
            ListNode *temp = malloc(sizeof(ListNode));
            temp->data = head->data;
            head->data = head->next->data;
            head->next->data = temp->data;
        }
        head = head->next;
    }
    temp1 = temp1->next;
    }
    return temp;
}
int main() 
{
  
  int a = 9;
  int b = 8;
  int c = 7;
  int d = 6;
  
  ListNode* head = ft_create_elem(a);
  head->next = ft_create_elem(b);
  head->next->next = ft_create_elem(c);
  head->next->next->next = ft_create_elem(d);
  
   ListNode *result = sortList(head);
   while (result != NULL)
   {
    printf("%d", result->data);
    result = result->next;
   }
 //printf("%d", sum);int sum = 
 return 0;
}