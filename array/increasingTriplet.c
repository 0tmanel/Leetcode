#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
/*
first keeps track of the smallest number seen so far.
second keeps track of the smallest number greater than first.
If we find a number greater than second, then we have first < second < nums[i] → triplet exists.

🔹 Complexity Analysis
Time Complexity: O(N) → Single loop through nums.
Space Complexity: O(1) → Only two extra variables (first and second).
*/
bool increasingTriplet(int *nums, int numsSize)
{
    int i = 0;
    int first = INT_MIN;
    int second = INT_MAX;
    while (i < numsSize)
    {
        if(nums[i] <= first)
        {
            first = nums[i];
        }
        else if (nums[i] <= second) {
            second = nums[i];
        }
        else
        {
            return 1;
        }
        i++;
    }

    return 0;
}
int main()
{
    int nums[] = {20, 100, 10, 12, 5, 13};
    int numsSize = 6;
    int sum = increasingTriplet(nums, numsSize);
    printf("%d\n", sum);
}