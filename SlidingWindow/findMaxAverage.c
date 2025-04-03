// Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data (arrays or strings) and then moving that window across the data to perform some operation within the window. This technique is commonly used in algorithms like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.
#include <stdio.h>
double findMaxAverage(int *nums, int numsSize, int k)
{
    int i = 0;
    double sum = 0;
     while (i < k)
    {
        sum += nums[i];
        i++;
    }
    double max = sum / k;
   
    int j = 0;
    while (i < numsSize)
    {
        sum += nums[i] - nums[j];
        double avg = sum / k;
        if (avg > max)
        {
            max = avg;
        }
        j++;
        i++;
    }
    

return max;
}
int main()
{
    int nums[] = {5};
    double sum = findMaxAverage(nums, 1, 1);
    printf("%f\n", sum);
}