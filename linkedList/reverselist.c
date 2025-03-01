#include <stdio.h>
#include <stdlib.h>
typedef struct  ListNode
{
    struct ListNode   *next;
    int    data;
}   ListNode;
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
struct ListNode* reverseList(struct ListNode* head) {

    ListNode*current = head;
    ListNode*prev = NULL;
    /* The first time you set current->next = prev;, 
    it’s necessary for prev to be NULL so that the first node points to NULL, 
    completing the reversal correctly.*/
    while (current != NULL)
    {
        ListNode*nextNode = current->next;
        current->next = prev;//nextNode = prev does not serve the purpose of reversing the list;
                             //it only updates a variable reference.
        prev = current;
        current = nextNode;// so in every new node we make it point to prev, and after that we update prev
    }
  
    return prev;
}
int main() 
{
  ListNode *head = NULL;
  int a = 13;
  int b = 3;
  int c = 7;
  
  
  head = ft_create_elem(a);
  head->next = ft_create_elem(b);
  head->next->next = ft_create_elem(c);
  

  ListNode* sum = reverseList(head);
 while (sum != NULL)
 {
  printf("%d", sum->data);
  sum = sum->next;
 }
  
  return 0;
}
/*Step-by-Step Reversal Process Iteration 1
Current Node: current points to 1.
Next Node: Save the next node:
nextNode = current->next (so nextNode points to 2).
Reverse the Link:
Set current->next = prev, which means 1->next = NULL. Now the list looks like:
1 -> NULL
Update Prev and Current:
Move prev to current:
prev = current (now prev points to 1).
Move current to nextNode:
current = nextNode (now current points to 2).
Iteration 2
Current Node: current points to 2.
Next Node: Save the next node:
nextNode = current->next (so nextNode points to 3).
Reverse the Link:
Set current->next = prev, which means 2->next = 1. Now the list looks like:
2 -> 1 -> NULL
Update Prev and Current:
Move prev to current:
prev = current (now prev points to 2).
Move current to nextNode:
current = nextNode (now current points to 3).
Iteration 3
Current Node: current points to 3.
Next Node: Save the next node:
nextNode = current->next (which is NULL).
Reverse the Link:
Set current->next = prev, which means 3->next = 2. Now the list looks like:
3 -> 2 -> 1 -> NULL
Update Prev and Current:
Move prev to current:
prev = current (now prev points to 3).
Move current to nextNode:
current = nextNode (now current points to NULL).
Final Step
Now that current is NULL, we exit the loop.
At this point, prev points to the new head of the reversed list, which is 3.
*/