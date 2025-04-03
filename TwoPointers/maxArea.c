/*
The problem requires finding the maximum area that can be formed between two vertical lines on a coordinate plane, representing heights. The key observation is that the area is determined by the minimum of the two heights and the width between them. We use the two-pointer technique to efficiently find the maximum possible area.

Approach
Initialize Two Pointers: Start with two pointers, one at the beginning (i = 0) and one at the end (j = heightSize - 1) of the height array.
Calculate the Current Area: The water that can be held between height[i] and height[j] is calculated as:

Area=(j−i)×min(height[i],height[j])
If this value is greater than max_water, update max_water.
Move the Pointer with the Smaller Height:
Since the height of the container is determined by the shorter line, to potentially increase the area, move the pointer that points to the smaller height.
This is based on the fact that decreasing the width (j - i) can only result in a larger area if a taller height is encountered.
Repeat Until Pointers Meet: Continue this process until i and j meet.

Complexity
Time complexity: O(n), where 𝑛 is the number of elements in the height array. Each element is processed at most once, as we either increment i or decrement j in each step.
Space complexity:O(1), since we use only a few integer variables for storing values.

*/
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int maxArea(int *height, int heightSize)
{
    int first = 0;
    int last = heightSize - 1;
    //int width = last - first;
    //int high = min(height[first], height[last]);
    int max = 0;
    while (first < last)
    {
        int area = (last - first) * min(height[first], height[last]);
        if(max < area)
        {
            max = area;
        }
       
        if(height[first] < height[last])
        {
            first++;
        }
        else 
        {
            last--;
        }
    }

    return max;
}
int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = 9;
    printf("%d\n", maxArea(height, heightSize));
}