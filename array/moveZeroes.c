#include <stdio.h>
#include <string.h>
/* overwrite the array
void moveZeroes(int *nums, int numsSize)
{
    int nonzero = 0;
    int i = 0;
    while(i < numsSize)
    {
        if(nums[i] != 0)
        {
            nums[nonzero] = nums[i];
            nonzero++;
        }
        i++;
    }
    i = nonzero;
    while(i < numsSize)
    {
        nums[i] = 0;
        i++;
    }
}*/
void moveZeroes(int *nums, int numsSize)
{
    int i = 0;

    while (i < numsSize)
    {
    int j = i + 1;
        while (j < numsSize)
        {
       if(nums[i] == 0 && nums[j] != 0)
        {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;       
        }
        j++;
        }
        i++;
    }
    int l = 0;
    while (l < numsSize)
    {
        printf("%d", nums[l]);
        l++;
    }
    printf("\n");
}
int main()
{
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = 5;
    moveZeroes(nums, numsSize);
    return 0;
}
