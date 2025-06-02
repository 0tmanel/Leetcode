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
void fill(struct ListNode* list, int *array, int *ptr)
{
    int i = *ptr;
    while(list)
    {
        array[i++] = list->val;
        list = list->next;
    }
    *ptr = i;
}
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
void mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int length = calcu(list1) + calcu(list2);
   // printf("%d\n", length);
    int *array = malloc(length * sizeof(int));
    int i = 0;
    fill(list1, array, &i);
    fill(list2, array, &i);
    qsort(array, length, sizeof(int), compare);
    int j = 0; 
    while(j < length)
    {
        printf("%d\n", array[j]);
        j++;
    }

    
}int main ()
{
    int a  = 1;
    int b = 2;
    int c = 4;
    int d = 1;
     int e = 3;
    int f = 4;
     struct ListNode*head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
     struct ListNode*head2 = ft_create_elem(d);
    head2->next = ft_create_elem(e);
    head2->next->next = ft_create_elem(f);
    mergeTwoLists(head, head2);
}