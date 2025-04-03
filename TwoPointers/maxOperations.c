
#include <stdio.h>
int compar(const void *a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int maxOperations(int* nums, int numsSize, int k){
    int index = 0;
    int  i = 0;
    int last = numsSize - 1;
    
    qsort(nums, numsSize, sizeof(int), compar);
    while(i < last)
    {
        printf("%d,  ", nums[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while( i < last)
    {
       if(nums[i] + nums[last] == k)
       {
         index++;
        last--;
        i++;
       }
      else if(nums[i] + nums[last] < k)
       {
         i++;
       }
       if(nums[i] + nums[last] > k)
       {
        last--;
       }
      
    }
    return index;
}
int main ()
{
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    int sum = maxOperations(nums, numsSize, k);
    printf("%d\n", sum);
}