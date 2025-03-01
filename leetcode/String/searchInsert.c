#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int i = 0 ;
    while (i < numsSize)
    {
        if(nums[i] == target)
        {
            break;
        }
        i++;
    }
    return i;
}
int main (void)
{
    int nums[] = {2, 4, 6};
    int numsSize = 3;
    int target = 4;
    int index = searchInsert(nums, numsSize, target);
    printf("%d", index);

}