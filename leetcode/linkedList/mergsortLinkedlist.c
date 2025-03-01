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
ListNode* mergeList(struct ListNode* a, struct ListNode* b)
{
    struct ListNode* mergedL = NULL;
    if(a == NULL)
    {
        return b;
    }else if(b == NULL)
    {
        return a;
    }
    if(a->data  < b->data)
    {
        mergedL = a;
        mergedL->next = mergeList(a->next, b);
    }else{
        mergedL = b;
        mergedL->next = mergeList(a, b->next);
    }
    return mergedL;
}
void partition (struct ListNode* head, ListNode** front, ListNode** back)
{
    struct ListNode* fast;
     struct ListNode* slow;
     if(head == NULL || head->next ==NULL)
     {
        *front = head;
        *back = NULL;
     }
     else
     {
        slow = head;
        fast = head->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front = head;
        *back = slow->next;
        slow->next = NULL;
     }

}
ListNode* mergeSort(struct ListNode* source)
{
    struct ListNode* head = source;
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    partition(head, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    return mergeList(a, b);
    

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
  
   ListNode *result = mergeSort(head);
   while (result != NULL)
   {
    printf("%d", result->data);
    result = result->next;
   }
 //printf("%d", sum);int sum = 
 return 0;
}