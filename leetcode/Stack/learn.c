//The INSERT operation on a stack is often called PUSH, and the DELETE opera- tion, which does not take an element argument, is often called POP. These names are allusions to physical stacks, such as the spring-loaded stacks of plates used in cafeterias. The order in which plates are popped from the stack is the reverse of the order in which they were pushed onto the stack, since only the top plate is accessible.

//When top , the stack contains no elements and is empty. We can test whether the stack is empty with the query operation STACK-EMPTY. Upon an attempt to pop an empty stack, the stack underüows, which is normally an error. If
// The procedures STACK-EMPTY, PUSH, and POP implement each of the stack operations with just a few lines of code. Figure 10.2 shows the effects of the modifying operations PUSH and POP. Each of the three stack operations takes O(1)time.

/*
//STACK-EMPTY (S)
if (S.top == 0)
return TRUE
else return FALSE

//PUSH 
3
if S.top == S.size 
error <overflow>
else 
S.top = S.top + 1
S[S.top] = x;

// POP 
if (STACK_EMPTY)
{
    error(underflow)
}else S.top = S.top - 1{
    return S[S.top + 1];
}
*/
#include <stdio.h>
#define MAX 10
typedef struct {
    int data[MAX];
    int top;
    //In a stack, top is not the value of the last element, 
    //but rather the index of the last inserted element.
} Stack;
void push(Stack *s, int number)
{
    

    if (s->top == MAX - 1)
    {
        printf("overflow\n");
    return;
    }
    s->top = s->top + 1;
    s->data[s->top] = number;
}
int main ()
{
    Stack s;
    int array[] = {0, 1, 2, 3, 4};
    int size = sizeof(array) / sizeof(array[0]);
    int i = 0;
   while (i < size)
   {
   push(&s, array[i]);
    i++;
   }
    push(&s, 8);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    
   int j = 0;
   while (j < MAX)
   {
    printf("%d\n", s.data[j]);
    j++;
   }
   return 0;
}