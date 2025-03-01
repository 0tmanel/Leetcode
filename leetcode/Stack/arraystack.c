#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode
{
     void* data;
    struct StackNode * next;
}StackNode;
StackNode *ft_create_elem(void *data)
{
    StackNode *new_node;
    new_node = malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void ft_stack(int *arr, int size)
{
    StackNode* top = NULL;
    StackNode* new_node;
    int i = 0;
    while (i < size)
    {
       new_node =  ft_create_elem((void*)(long)arr[i]);
       new_node->next = top;
       top = new_node;
       i++;
    }
    while (top != NULL)
    {
        printf("%d\n", (int)(long)top->data);
        top = top->next;
    }
}
int main ()
{
    int array [] = {6, 5, 4, 3, 2, 1};
    int size = 6;
    ft_stack(array, size);
}