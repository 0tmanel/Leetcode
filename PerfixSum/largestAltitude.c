//A prefix sum array, also known as a cumulative sum array, is a derived array that stores the cumulative sum of elements in a given array. Each element in the prefix sum array represents the sum of all elements up to that index in the original array. It acts as a precursor to answering queries related to cumulative sums, allowing for fast and efficient computations. It also reduces time complexity giving us a way out of TLE.

#include <stdio.h>
int largestAltitude(int* gain, int gainSize) {
    int sum = 0;
    int alt = 0;
    int i = 0;
    while (i < gainSize)
    {
        sum += gain[i];
        if(sum > alt)
        {
            alt = sum;
        }
        i++;
    }
    return alt;
}
int main (){
    int gain[] = {-4,-3,-2,-1,4,3,2};
    int gainSize = 7;
    int sum = largestAltitude (gain, gainSize);
    printf("%d\n", sum);
}