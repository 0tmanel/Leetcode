#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10000
typedef struct{
    char s[MAX];
    int top;
}Stack;
void push(Stack *t, char c)
{
    if(t->top == MAX - 1)
    {
        return;
    }
    t->top++;
    t->s[t->top] = c;
}
void pop(Stack *t)
{
    t->top = t->top - 1;

}
bool isValid(char* s) {
    Stack t;
    int i = 0;
    t.top = 0;
    int len = strlen(s);
    if (len % 2 != 0)
    return 0;
    while (s[i] != '\0')
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(&t, s[i]);
        }
        if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
           if(s[i]== ')')
           {
            if(t.s[t.top] == '(')
            {
                pop(&t);
            }else{
                return 0;
            }
           }
           if(s[i]== '}')
           {
            if(t.s[t.top] == '{')
            {
                pop(&t);
            }else{
                return 0;
            }
           }
           if(s[i]== ']')
           {
            if(t.s[t.top] == '[')
            {
                pop(&t);
            }else{
                return 0;
            }
           }
        }
        i++;
    }
    if(t.top == 0)
    {
        return 1;
    }
    return 0;
}
int main ()
{
    char s[] = "(){}[]";
    isValid(s);
}