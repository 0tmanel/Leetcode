#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*The qsort function internally handles the process of selecting the elements
 to be compared and passes them to your compare function. You don't need to worry
  about extracting a and b from the array — qsort does that for you.*/
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Sort in ascending order
}

bool containsDuplicate(int* nums, int numsSize) {
    // Sort the array first
    /*qsort() requires four arguments: the base of the array,
     the number of elements in the array, the size of each element, and a comparison function.
     For sorting an array of integers, you need to provide a comparison function 
     that tells qsort() how to compare two elements. This function should return:
     1: A negative number if the first element is smaller,
     2: Zero if the elements are equal,
     3: A positive number if the first element is greater.*/
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Check for adjacent duplicates
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;  // Found a duplicate
        }
    }
    
    return false;  // No duplicates
}

int main() {
    int nums[] = {1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = containsDuplicate(nums, numsSize);
    printf("%d\n", result);  // Expected output: 0 (No duplicates)
    
    return 0;
}
