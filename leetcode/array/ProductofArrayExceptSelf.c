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
    int len = numsSize - 1;
    int i = len;
    int j = len - 1;
    right[len] = 1;
    right[j] = nums[len];
    int l = len - 2;
    while (l >= 0)
    {
        right[l] = nums[i] * nums[j];
        l--;
        i--;
        j--;
       
    }
    int o = 0;
    while (o < numsSize)
    {
        printf("%d", right[o]);
        o++;
    }
}
void leftarray(int *nums, int numsSize, int* left)
{
    int i = 0;
    int j = i + 1;
    left[0] = 1;
    left[1] = nums[0];
    int l = 2;
    while (l < numsSize)
    {
        left[l] = nums[i] * nums[j];
        l++;
        i++;
        j++;
       
    }
    
}
void productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *left = malloc(numsSize * sizeof(int));
     int *right = malloc(numsSize * sizeof(int));
    leftarray(nums, numsSize, left);
    rightarray(nums, numsSize, right);

}
int main ()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = 4;
    int returnSize = 0;
   //int *array = 
   productExceptSelf(nums, numsSize, &returnSize);
    printf("\n");
}