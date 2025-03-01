#include <stdio.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    int array[MAX];
    int top;
}Stack;
void push(Stack *s, int num)
{
    s->top = s->top + 1;
    s->array[s->top] = num;
}
void pop(Stack *s, int num)
{
    s->top = s->top - 1;
}
bool isArraySpecial(int* nums, int numsSize) {
    Stack s;
    s.top = 0;
    int i = 0;
    while(nums[i] != '\0')
    {
        if(nums[i] % 2 == 0)
        {
            push(&s, nums[i]);
        }
        else if(nums[i] % 2 != 0)
        {
            pop(&s, nums[i]);
        }
        i++;
    }
    if(s.top == 0)
    {
        return 1;
    }
    return 0;
}
int main ()
{
    int nums [] = {1, 2, 3, 4};
    int numsSize = 4;
   int len = isArraySpecial(nums, numsSize);
   printf("%d\n", len);

}