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
void isPalindrome(struct ListNode* head) {
    ListNode*temp = head;
    Stack* node = malloc(sizeof(Stack));
    node->top = NULL;
    /*while (temp != NULL)//PUSH INTO THE STACK
    {
        ListNode*nextNode = temp->next;
        temp->next = node->top;
        node->top = temp;
        temp = nextNode;
    }*/
   while (temp != NULL)//PUSH INTO THE STACK
    {
        ListNode*nextNode = malloc(sizeof(ListNode));
        nextNode->data = temp->data;//we set just the data , we do not have to set the reference;
        nextNode->next = node->top;
        node->top = nextNode;
        temp = temp->next;
    }
    ListNode*current = node->top;
    
    while(current != NULL && head != NULL)
    {
       if(current->val == head->val)
       {
       
       current = current->next;
        head = head->next;
       }
       else {
        return false;
       }
    }
    return true;

}


int main() 
{
  
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 1;
  
  
  ListNode* head = ft_create_elem(a);
  head->next = ft_create_elem(b);
  head->next->next = ft_create_elem(c);
  head->next->next->next = ft_create_elem(d);
  

   isPalindrome(head);
 
 //printf("%d", sum);int sum = 
 return 0;
}