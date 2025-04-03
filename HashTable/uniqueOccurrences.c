#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int key(int key, int size)
{
    return key % size;
}
int compar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void fill(int *arr, int arrSize)
{
    int i = 0;
    while (i < arrSize)
    {
        arr[i] = -1;
        i++;
    }
}
bool uniqueOccurrences(int *arr, int arrSize)
{
    long long count[2001] = {0};
    long long uniq[2001] = {0};
    int i = 0;
    while (i < arrSize)
    {
        count[arr[i] + 100] += 1;
        i++;
    }
    int j = 0;
    while (j < arrSize)
    {
        int index = arr[i] + 1000;

        if (count[index])
        {
            if(uniq[count[index]])
            {
                return 0;
            }
            else{
                uniq[count[index]] = 1;
            }
        }
        j++;
    }
    return 1;
}
int main()
{
    int array[] = {1, 2};
    int arrSize = 2;
    int res = uniqueOccurrences(array, arrSize);
    printf("%d\n", res);
}