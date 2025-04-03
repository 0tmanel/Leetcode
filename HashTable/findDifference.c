/*
We are given two integer arrays, nums1 and nums2, and need to return a list of two lists. The first list has the elements that are present only in nums1, while the second list has the elements that are present only in nums2.


Approach 1: Brute Force
Intuition

To find the elements in a list that are not present in another list, we can loop over every element in the first list and for each element we loop over the elements in the second list to check if it's present or not. If we find the element, we will not store it in the answer list; otherwise, we can store it.

This way, we will have to apply the above method twice once for the elements that are only in nums1 and then again for the elements that are only present in nums2.

Algorithm

getElementsOnlyInFirstList function:

Initialize an empty set onlyInNums1 to store elements that are only in nums1.

Iterate over each element num in nums1:

Set a boolean flag existInNums2 to false.
Iterate over each element x in nums2:
If num is found in nums2 (i.e., x == num), set existInNums2 to true and break the inner loop.
If existInNums2 is still false, add num to the set onlyInNums1 (i.e., num exists in nums1 but not in nums2).
Convert onlyInNums1 set to a list and return it.

findDifference function:

Call getElementsOnlyInFirstList(nums1, nums2) to get elements only in nums1 and store the result.
Call getElementsOnlyInFirstList(nums2, nums1) to get elements only in nums2 and store the result.
Return a list of both results as a list of lists).
The overall result contains two lists:

The first list contains elements in nums1 that are not in nums2.
The second list contains elements in nums2 that are not in nums1.
*/
#include  <stdlib.h>
#define Size 2001 
/*
   // Covers range [-1000, 1000]
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
  
    int* hash = (int*)calloc(Size, sizeof(int));
    int** ans = (int**)malloc(sizeof(int*) * 2);
    ans[0] = (int*)calloc(nums1Size, sizeof(int));
    ans[1] = (int*)calloc(nums2Size, sizeof(int));
    
    for(int i = 0; i < nums2Size; i++)
        hash[nums2[i]+1000] = 1;
    
    for(int i = 0; i < nums1Size; i++)
    {
        if(hash[nums1[i]+1000]>0)
            hash[nums1[i]+1000]++;
        else 
            hash[nums1[i]+1000] = -1;
    }
    int* col = (int*)calloc(2, sizeof(int));
    for(int i = -1000; i <= 1000; i++)
    {
        if(hash[i+1000] == -1)
            ans[0][col[0]++] = i;
        else if(hash[i+1000] == 1)
            ans[1][col[1]++] = i;
    }
    
    *returnSize = 2;
    *returnColumnSizes = col;
    return ans;
}*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int *getElementsOnlyInFirstList(int* nums1, int*nums2, int numSize1, int numSize2, int* column)
{
    int *onlyInNums1 = (int*)malloc(numSize1 * sizeof(int));
    int i = 0;
    int k = 0;
    while(i < numSize1)
    {
    
    bool existInNums2 = false;
        int j = 0;
        while(j < numSize2)
        {
            if(nums2[j] == nums1[i])
            {
                existInNums2 = true;
                break;
            }
            j++;
        }
   
        if(!existInNums2)
        {
            onlyInNums1[k++] = nums1[i];
        }
        i++;
    }
    *column = k;
    return onlyInNums1;
}
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes)
{
    int** answer = (int**)malloc(sizeof(int*) * 2);
     *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    answer[0] = getElementsOnlyInFirstList(nums1, nums2, nums1Size, nums2Size, &(*returnColumnSizes)[0]);
    answer[1] = getElementsOnlyInFirstList(nums2, nums1, nums2Size, nums1Size, &(*returnColumnSizes)[1]);

     *returnSize = 2;
     return answer;
}
int main() {
    int nums1[] = {1,2,3,3};
    int nums2[] = {1,1,2,2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = findDifference(nums1, nums1Size, nums2, nums2Size, &returnSize, &returnColumnSizes);

    // Print results
    int i = 0;
    while (i < returnSize){
        printf("Set %d: ", i + 1);
        int j = 0;
        while (j < returnColumnSizes[i]) {
            printf("%d ", result[i][j]);
            j++;
        }
        printf("\n");
        free(result[i]); // Free each row
        i++;
    }
    free(result); // Free main array
    free(returnColumnSizes); // Free column sizes

    return 0;
}
//Hashing numbers is a bit different from hashing characters. Here are several ways to hash numbers effectively:
/*
1️⃣ Modulo Hashing (Basic and Common)
Similar to hashing characters, you can use modulo to keep numbers within a fixed range:

c
Copy
Edit
int key(int num, int size) {
    return num % size;
}
✅ Simple and fast
🚨 Collisions happen when different numbers map to the same index.

Example:
For size = 10, numbers 25 and 35 both hash to 5 (25 % 10 == 5, 35 % 10 == 5).

2️⃣ Multiplicative Hashing (Better Distribution)
Uses a prime number multiplier to spread values more evenly:

c
Copy
Edit
int key(int num, int size) {
    return (num * 37) % size;  // 37 is a prime number
}
✅ Better distribution than modulo alone.
🚨 Still not perfect, but reduces clustering.
*/
