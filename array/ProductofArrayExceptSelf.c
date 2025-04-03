/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
#include <stdlib.h>
#include <stdio.h>

void rightarray(int *nums, int numsSize, int* right)
{
    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
}

void leftarray(int *nums, int numsSize, int* left)
{
    left[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
}
int* productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *right = malloc(numsSize * sizeof(int));
    int *left = malloc(numsSize * sizeof(int));
     int *answer = malloc(numsSize * sizeof(int));
    leftarray(nums, numsSize, left);
    rightarray(nums, numsSize, right);
    int i = 0;
    while(i < numsSize)
    {
        answer[i] = left[i] * right[i];
        i++;
    }
    int j = 0;
    
    *returnSize = numsSize;
    return answer;
}
int main()
{
    int nums[] = {-1,1,0,-3,3};
    int numsSize = 5;
    int returnSize = 0;
    int *array = productExceptSelf(nums, numsSize, &returnSize);
    int j = 0;
    while(j < numsSize)
    {
        printf("%d", array[j]);
        j++;
    }
    printf("\n");
}