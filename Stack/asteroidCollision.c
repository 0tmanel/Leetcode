/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000
typedef struct
{
    int arr[MAX];
    int top;
} stack;
void push(stack *s, int item)
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
int* asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize)
{
    stack t;
    t.top = -1;
    int i = 0;
    int index = 0;
    while(i < asteroidsSize){
        int current = asteroids[i];
      while (t.top != -1 && current < 0 && t.arr[t.top] > 0) {
            if (t.arr[t.top] < -current) {
                pop(&t);
                continue;
            } else if (t.arr[t.top] == -current) {
                pop(&t);
            }
            current = 0;
            break;
        }

        if (current != 0) {
            push(&t, current);
        }
        i++;
    }
    *returnSize = t.top + 1;
    int *array = malloc(*returnSize * sizeof(int));
    int j = 0;
    while (j < *returnSize)
    {
       array[j] = t.arr[j];
        j++;
    }
   
   return array;
}
int main()
{
    int asteroids[] = {5, 10, -8};
    int asteroidsSize = 2;
    int returnSize = 0;
     int *array = asteroidCollision(asteroids, asteroidsSize, &returnSize);
       int i = 0;
       while(i < returnSize)
       {
        printf("%d", array[i]);
        i++;
       }
       printf("\n");
}