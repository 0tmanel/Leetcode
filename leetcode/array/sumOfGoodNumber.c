#include <stdio.h>
int sumOfGoodNumbers(int *nums, int numsSize, int k)
{
    int i = 0;
    int number = 0;
    
    while (i < numsSize)
    { 
       //check if i - k is out of bound, and  i + k in bound we check the one that is in bound if it is less that num[i]
            if(i - k < 0 && (i + k) < numsSize)
            {
                if(nums[i] > nums[i + k])
                {
                    number += nums[i];
                }
            }
            // the same as the first but the oposite
            else if ((i - k >= 0 && (i + k) >= numsSize))
            {

                if(nums[i] > nums[i - k])
                {
                    number += nums[i];
                }
            }
            //we check if i - k and i + k both in the bound
            else if (i - k >= 0 && (i + k) < numsSize)
            {
             if (nums[i] > nums[i + k] && nums[i] > nums[i - k])
            {
                number += nums[i];
            }
            }
            
        i++;
    }
    return number;
}
int main()
{
    int nums[] = {17, 20}; // = 20
    // 2, 1 == 2
    // 1,3,2,1,5,4], k = 2
    int numsSize = 2;
    int k = 1;
    int sum = sumOfGoodNumbers(nums, numsSize, k);
    printf("%d\n", sum);
}