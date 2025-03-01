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
void ft_str(char* str)
{
    StackNode *top;
    
    StackNode* current;
    int i = 0;
    while (str[i] != '\0')
    {
        current = ft_create_elem((void*)(long) str[i]);
        current->next = top;
        top = current;
        i++;
    }
    StackNode* temp;
    while (top!= NULL)
    {
        printf("%c", (char) (long)top->data);
         temp = top;
         top = top->next;  
    }
   
}
int main ()
{
    char  str[] = "hello";
    ft_str(str);

}