#include <stdio.h>

#include <stdlib.h>  // For qsort

// Comparison function for qsort to sort integers in ascending order
int compar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compar);
   if(numsSize == 1)
   {
    return nums[0];
   }
   int len = numsSize / 2;
   int currentElement = nums[0];
   int count = 1;
   int i = 1;
   while (i < numsSize)
   {
    if(nums[i] == currentElement)
    {
        count++;
    }
    else{
        currentElement = nums[i];
        count = 1;
    }
    if(count > len)
    {
        return currentElement;
    }
    i++;
   }
   return 0;
}
/*
The algorithm you've written can be described as a "Sorting-based Majority Element Algorithm" (or simply a "Sorting Approach"). It's a solution to the Majority Element problem where you are looking for the element that appears more than half of the times in an array.

Key Points:
Sorting: You first sort the array using qsort(). Once the array is sorted, all identical elements will be adjacent to each other.
Linear Scan for Majority: After sorting, you perform a single pass through the array to count the occurrences of consecutive elements. The majority element (if one exists) will appear in the middle of the array and will be counted as the most frequent element.
Time Complexity: Sorting the array takes 

O(nlogn) and the linear scan takes 
O(n), so the overall time complexity is 

O(nlogn).
Space Complexity: The space complexity is 
𝑂(1)
O(1) (in-place sorting), since qsort() works in-place.
What to call it:

Sorting-Based Majority Element Algorithm: This is because sorting helps group the majority element together.
Sorting + Linear Scan Approach: You first sort, then scan to count occurrences.

Naive Majority Element Algorithm (with sorting): This is a more general name if you want to emphasize the "naive" nature of the algorithm, as there are faster algorithms available (like Boyer-Moore Voting) for the same problem.

Why It's Not Optimized:

While this works fine, it's not the most optimal solution for the majority element problem. The Boyer-Moore Voting Algorithm, which can solve the problem in O(n) time and O(1) space, is a more efficient alternative.
*/
int main ()
{
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int n = 7;
   int element = majorityElement(nums, n);
   printf("%d\n", element);
}
//the beter way to solve thid exercise is by The Boyer-Moore Voting Algorithm, HERE IT IS

/*
int majorityElement(int* nums, int numsSize) {
    // Phase 1: Find a candidate
    [2, 2, 1, 1, 2, 2];
    int candidate = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    int occurrences = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            occurrences++;
        }
    }

    if (occurrences > numsSize / 2) {
        return candidate;
    }

    return -1;  // In case there's no majority element
}


The Boyer-Moore Voting Algorithm is a clever way to find the majority element in an array, if it exists. In this case, the algorithm is implemented in two phases:

Phase 1: Find a Candidate for the Majority Element
This is where the actual "voting" process happens. The algorithm works by maintaining a candidate and a count, which helps track how frequently that candidate occurs.

Initialize:

candidate: The element we’re considering as the potential majority element.
count: Keeps track of how many times the candidate is "winning" (or how many votes it has).
Iterate through the array:

If count is zero, it means no one has been winning, so we set candidate to the current element (nums[i]), and reset count to 1.
If the current element is the same as the candidate, increment count because the candidate is still winning.
If the current element is different from the candidate, decrement count because the candidate just lost a "vote."
The key observation here is that the candidate is effectively being "voted on" by the elements in the array. When the count is zero, we switch to a new candidate, but by the end of the array, the remaining candidate is the most likely majority element (if one exists).

Phase 2: Verify the Candidate
After finding a candidate, we need to check whether it really is the majority element, i.e., it appears more than numsSize / 2 times.

Count occurrences:
We go through the array again and count how many times the candidate appears.
Check if it’s the majority:
If the occurrences of the candidate are greater than half the size of the array (numsSize / 2), then the candidate is indeed the majority element, and we return it.
If not, we return -1 to indicate there is no majority element.
Why does this work?
The Boyer-Moore Voting Algorithm works under the assumption that if there is a majority element, it will always "survive" the voting process, even as we switch candidates when the count hits zero. The majority element will have enough "votes" to overpower any other elements in the array.
Example Walkthrough
Consider this array: [3, 3, 4, 2, 4, 4, 2, 4, 4]

Phase 1: Finding the candidate

Start with candidate = 3, count = 1.
Next element is 3, so we increment the count: count = 2.
Next element is 4, so we decrement the count: count = 1.
Next element is 2, so we decrement the count: count = 0. We switch the candidate to 2, count = 1.
Continue through the array; after processing all elements, the candidate is 4.
*/