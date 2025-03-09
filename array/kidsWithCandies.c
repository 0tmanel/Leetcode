//Create an integer variable called biggest to store the greatest number of candies in candies. We initialize it with 0.
//We iterate over candies and for each kid who has candy candies, we perform maxCandies = max(maxCandies, candy) to get the greatest number of candies in candies.
//Create a boolean list answer.
//We iterate over candies once more, and for each kid who has candy candies, we add candy + extraCandies >= maxCandies to answer.
//Return answer.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int biggest = 0;
    int i = 0;
    while(i < candiesSize)
    {
        if(candies[i] > biggest)
        {
            biggest = candies[i];
        }
        i++;
    }
    bool* string = malloc((candiesSize + 1) * sizeof(bool));
    int j = 0;
    while(j < candiesSize)
    {
        if((candies[j] + extraCandies) >= biggest)
        {
            string[j] = true;
        }
        else if ((candies[j] + extraCandies) < biggest)
        {
            string[j] = false;
        }
        j++;
    }
   *returnSize = candiesSize;
    return string;
    
}
int main ()
{
    int candies [] = {2, 3, 1, 5};
    int candiesSize = 4;
    int extraCandies = 3;
    int returnSize = 0;
   bool *string = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
   int i = 0;
   while(i < candiesSize)
   {
    printf("%d", string[i]);
    i++;
   }
   printf("\n");
}
