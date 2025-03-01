#include <stdio.h>
#include <stdlib.h>
int compare(const void * a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), (*compare));
    int i = 0;

    while (i < numsSize)
    {
       if(i != nums[i])
       {
        return i;
       }
       i++;
    }
    return numsSize;
}
int main ()
{
    int nums[] = {0,1};
    int numsSize = 2;
    int numb = missingNumber(nums, numsSize);
   printf("%d\n", numb);
}