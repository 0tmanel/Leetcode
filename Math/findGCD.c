#include <stdio.h>
#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int findGCD(int* nums, int numsSize) {
    int biggest = nums[0];
    int smallest = nums[0];
    int i = 0;
    if(numsSize > 2)
    {
        while (i < numsSize)
    {
        if(nums[i] > biggest)
        {
            biggest = nums[i];
        }
        if(nums[i] < smallest)
        {
            smallest = nums[i];
        }
        i++;
    }
    }
    else {
        if(nums[0] > nums[1])
        {
            biggest = nums[1];
            smallest = nums[0];
        }
        else {
             biggest = nums[0];
            smallest = nums[1];
        }
    }
   return gcd(biggest, smallest);
}
int main ()
{
    int nums[] = {6,9,10};
    int numsSize = 3;
 int gcd =  findGCD(nums, numsSize);
    printf("%d\n", gcd);
}