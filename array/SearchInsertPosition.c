#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 1;
    if(target == 0)
    {
        return 0;
    }
    while (i < numsSize)
    {
        if(nums[i] == target)
        {
            return i;
        }
        if(nums[i] > target)
        {
            return i;
        }
        i++;
    }

}
    
int main ()
{
    int nums[] = {1,3,5,6};
    int numsSize = 4;
    int target = 7;
   int result = searchInsert(nums, numsSize, target);
   printf("%d\n", result);
}