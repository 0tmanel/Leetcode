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
int *fill(struct ListNode* head, int* array)
{
    struct ListNode* temp = head;
    int i = 0;
    while(temp)
    {
        array[i++] = temp->val;
        temp = temp->next;
    }
    return array;
}
struct ListNode* oddEvenList(struct ListNode* head) {
    int length = calcu(head);
    int *array = malloc(length * sizeof(int));
    fill(head, array);
    int *array2 = malloc(length * sizeof(int));
    int i = 1;
    int j = 0;
    //fill the array with odd
    while(i <= length)
    {
        if(i % 2 != 0)
        {
            array2[j++] = array[i - 1];
        }
        i++;
    }
    i = 1;
    //fill the array with even
    while(i <= length)
    {
        if(i % 2 == 0)
        {
            array2[j++] = array[i - 1];
        }
        i++;
    }
    int k = 0;
     struct ListNode* head2 = NULL;
     struct ListNode* cur = NULL;
    while(k < length)
    {
        struct ListNode* new_node = ft_create_elem(array2[k]);
        if(k == 0)
        {
            head2 = new_node;
            cur = new_node;
        }
        else{
            cur->next = new_node;
            cur = new_node;
        }
        k++;
    }
    // while(head2)
    // {
    //     printf("%d\n", head2->val);
    //     head2 = head2->next;
    // }
    return head2;
}
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
   
  struct ListNode *head = ft_create_elem(a);
    head->next = ft_create_elem(b);
    head->next->next = ft_create_elem(c);
    head->next->next->next = ft_create_elem(d);
    head->next->next->next->next = ft_create_elem(e);
   struct ListNode *head2 = oddEvenList(head);
   while(head2)
    {
        printf("%d\n", head2->val);
        head2 = head2->next;
    }
   
}

// int main ()
// {
//     int i = 1;
//     struct ListNode* head = NULL;
//     struct ListNode* cur = NULL;
//     while(i <= 3)
//     {
//         struct ListNode* node = ft_create_elem(i);
//         if(i == 1)
//         {
//             head = node;
//             cur = node;
//         }
//         else{
//             cur->next = node;
//             cur = node;
//         }
//         i++;
//     }
//     while(head)
//     {
//         printf("%d\n", head->val);
//         head = head->next;
//     }
// }