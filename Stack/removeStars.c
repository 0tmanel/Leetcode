#include <stdio.h>
#include <stdlib.h>
#define MAX 50000
typedef struct
{
    char arr[MAX];
    int top;
}stack;
void push(stack *s, char item)
{
    if (s->top == MAX - 1)
    {
        return;
    }
    s->top++;
    s->arr[s->top] = item;
}
void pop(stack *s)
{
   s->top = s->top - 1;
}
char* removeStars(char* s) {
    stack t;
    int i = 0;
    t.top = -1;
    while(s[i] != '\0')
    {
       
        push(&t, s[i]);
        //"leet**cod*e"
        if(s[i] == '*')
        {
            pop(&t);
             pop(&t);
        }
        i++;
    }
   push(&t, '\0');
    int j = 0;
     while(t.arr[j])
    {
        s[j] = t.arr[j];
        j++;
    }
    s[j] = '\0';
    //printf("\n");
    return s;
}
// char* removeStars(char* s) {
//     int len = strlen(s);
//     char *str = malloc(len+1);
//     int ind = 0;
//     for(int i=0;i<len;i++)
//     {
//         if(s[i]!='*'){
//             str[ind++] = s[i];
//         }
//         else{
//             ind--;
//         }
//     }
//     str[ind]='\0';
//     return str;
// }
int main ()
{
    char s[] = "leet**cod*e";
     printf("%s\n", removeStars(s));
    
}