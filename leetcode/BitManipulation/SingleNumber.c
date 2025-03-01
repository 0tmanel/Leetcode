
#include <stdio.h> 
#include <stdlib.h>
//XOR (exclusive OR) is a bitwise operation, meaning it works on the individual bits of the numbers.
//It operates on corresponding bits of two numbers:
//If the bits are the same, the result is 0.
//If the bits are different, the result is 1.
// 5   ^   8 = 13;
//0101 ^  1000 == 1101 = 13



int singleNumber(int* nums, int numsSize) {
   
    int i = 0;
    int result = 0;
    while (i < numsSize)
    {
       result = result ^ nums[i];
       i++;
    }
    return result;
}
//If you XOR all the numbers together:
//{4,1,2,1,2};
//Start with result = 0.
//result = 0 ^ 4 = 4
//result = 4 ^ 1 = 5
//result = 5 ^ 2 = 7 (the first 2 cancels out)
//result = 7 ^ 1 = 6
//result = 6 ^ 2 = 4 (the second 4 cancels out)
int main ()
{
    int nums[] = {4,1,2,1,2};
    int numsSize = 5;
    int retur = singleNumber(nums, numsSize);
    printf("%d\n", retur);
} 
//The key observation is that XORing pairs of identical numbers results in 0. In the array {4, 1, 2, 1, 2}, we have:

//1 appears twice, so 1 ^ 1 = 0.
//2 appears twice, so 2 ^ 2 = 0.
//The only number that doesn't get canceled out is 4, because it appears only once.
