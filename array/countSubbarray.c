#include <stdio.h>
int countSubarrays(int *nums, int numsSize)
{
    int i = 0;
    int sub = 0;
    while (i <= numsSize - 3)
    {
        int first = nums[i];
        int mid = nums[i + 1];
        int last = nums[i + 2];
    if (mid % 2 == 0 && first + last == mid / 2)
    {
        //if (mid % 2 == 0) You're ensuring that: mid / 2 will be an exact integer
        //The comparison won't be affected by rounding or truncation
       //Only even mid values are valid to satisfy the condition exactly.
        sub++;
    }
        i++;
    }
    return sub;
}
//we could use this : 
// Instead of:
// first + last == mid / 2
// We use multiplication to keep it exact:
// (first + last) * 2 == mid
// Same math, but no decimal problems!
int main()
{
    int array[] = {0, -4, 0};
    int numsSize = 3;
    int num = countSubarrays(array, numsSize);
    printf("%d\n", num);
}

