#include <stdio.h>
#include <stdlib.h>
typedef struct Element
{
    int value;
    int index;
}Element;
/*int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr = malloc(2 * sizeof(int));
    if (arr == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < numsSize)
    {
        int j = i + 1;
        while ( j < numsSize)
        {
            if(nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
            j++;
        }
        i++;
    }
    *returnSize = 0;
    return NULL;
}*/
int compare(const void* a, const void* b)
{
   return ((Element*)a)->value - ((Element*)b)->value;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr = malloc(2 * sizeof(int));
    if (arr == NULL)
    {
        return NULL;
    }
    Element *element = malloc(numsSize * sizeof(Element));
    if(element == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (i < numsSize)
    {
        element[i].value = nums[i];
        element[i].index = i;
        i++;
    }
    qsort(element, numsSize, sizeof(Element), compare);
    int first = 0;
    int last = numsSize - 1;
   
    while (first < last)
    {
        int sum = element[first].value + element[last].value;
        if (sum == target)
        {
            arr[0] = element[first].index;
            arr[1] = element[last].index;
            *returnSize = 2;
            free(element);
            return arr;
        }
        else if (sum < target)
        {
            first++;
        }
        else 
        {
            last--;
        }   
        
    }
    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[] = {3, 2, 4};
    int target = 6;
    int numsSize = 3;
    int returnSize = 0;
    int *sum = twoSum(nums, numsSize, target, &returnSize);
    printf("%d , %d", sum[0], sum[1]);
}