/*Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
You can return the answer in any order.*/
#include <stdio.h>
#include <stdlib.h>
  /*  int *hashTable = malloc(numsSize * sizeof(int));

    int i = 0;
    while (i < numsSize) // initilize an empty table
    {
        hashTable[i] = -1;
        i++;
    }*/

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = malloc(2 * sizeof(int));
  

    int j = 0;

    while (j < numsSize)
    {
        int complement = target - nums[j];
        //int index = complement % numsSize;
        int k = 0;
       while (k < j)
       {
            if (nums[k] == complement)
            {
                result[0] = k;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
            k++;
       }
            
        
        j++;
    }
     *returnSize = 0;
   free (result);
    return NULL;
}
int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 0;
    int *result1 = twoSum(nums, numsSize, target, &returnSize);
    int i = 0;
    if(result1 != NULL)
    {
        printf("%d and %d", result1[0], result1[1]);
        
    }
    free(result1);
      
}
