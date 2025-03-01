#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    struct ListNode *next;
    int val;
} ListNode;
typedef struct Stack
{
    ListNode *top;
} Stack;
ListNode *ft_create_elem(int data)
{
    ListNode *new_node;

    new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node)
    {
        new_node->val = data;
        new_node->next = NULL;
    }
    return (new_node);
}
struct ListNode *sortList(struct ListNode *head)
{
    ListNode *temp1 = head;
    ListNode *temp = head;
    if (temp->next == NULL)
    {
        return 0;
    }
    while (temp1 != NULL)
    {
        head = temp;
        while (head != NULL && head->next != NULL) // make sure next pointer does not accsess boundaries
        {
            if (head->val > head->next->val)
            {
                ListNode *temp = malloc(sizeof(ListNode));
                temp->val = head->val;
                head->val = head->next->val;
                head->next->val = temp->val;
            }
            head = head->next;
        }
        temp1 = temp1->next;
    }
    return temp;
}
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{

    if (list1 == NULL && list2 != NULL)
    {
        return list2;
    }
    if (list1 != NULL && list2 == NULL)
    {
        return list1;
    }
    if (list1 == NULL || list2 == NULL)
    {
        return NULL;
    }
    ListNode *temp = list1;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;


            ListNode *next = malloc(sizeof(ListNode));
            next = list1->next;
            ListNode *next2 = malloc(sizeof(ListNode));
            next2 = list2->next;

            if (list1->next == NULL)
             {
                 list1->next = temp2;
                 temp2 = list1->next;
                 return sortList(temp);
             }
             else if (list2->next == NULL)
             {
                 list2->next = temp1;
                 temp1 = list2->next;
                 return sortList(temp2);
             }
             else{
            list1->next = list2;
            list2 = list1->next;
            list2->next = next;
            return sortList(temp);
             }
            

            /*if (list1->next == NULL)
             {
                 list1->next = temp2;
                 temp2 = list1->next;
             }*/
    
   
}
int main()
{

    int a = 2;
    int b = 3;
    int c = 5;

    ListNode *head = ft_create_elem(a);
     head->next = ft_create_elem(b);
     head->next->next = ft_create_elem(c);
    int d = 1;
    int e = 4;
    int f = 2;

    ListNode *head2 = ft_create_elem(d);
    head2->next = ft_create_elem(e);
   head2->next->next = ft_create_elem(f);

    ListNode *result = mergeTwoLists(head, head2);
    while (result != NULL)
    {
        printf("%d", result->val);
        result = result->next;
    }
    // printf("%d", sum);int sum =
    return 0;
}