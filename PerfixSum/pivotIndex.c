#include <stdio.h>
/*
int left(int *nums, int numsSize)
{
 int i = 1;
    int sum = 0;
    while(i < numsSize)
    {
        sum += nums[i];
        i++;
    }
     if(sum == 0)
    {
        return 0;
    }
    return 0;

}
int right(int *nums, int numsSize)
{
    int i = 0;
    int sum = 0;
    while(i < numsSize)
    {
        sum += nums[i];
        i++;
    }
     if(sum == numsSize)
    {
        return 1;
    }
    else{
        return 0;
    }
}
*/
int pivotIndex(int* nums, int numsSize) {
  int rightsum = 0;
  int leftsum = 0;
  int i = 0;
  while(i < numsSize)
  {
    rightsum += nums[i];
    i++;
  }
  i = 0;
  while(i < numsSize)
  {
    rightsum -= nums[i];
    if(rightsum == leftsum)
    return i;
    leftsum += nums[i];
    i++;
  }
    return -1;
}
int main ()
{
    int nums[] = {1,1,1,1,1,-1};
    int numsSize = 6;
   int index = pivotIndex(nums, numsSize);
   printf("%d\n", index);
}
/*
       if(left(nums, numsSize))
   return 0;
    
    int sum = 0;
    int sum2 = 0;
     int i = 0;
    while (i < numsSize)
    {
        int j = 0;
        sum = 0;
        while (j < i)
        {
            sum += nums[j];
            j++;
        }
        int l = numsSize - 1;
        sum2 = 0;
        while (l > i)
        {
            sum2 += nums[l];
            l--;
        }
        if(sum == sum2)
        {
            return i;
        }
       i++; 
    }
    return -1;
}
    }*/
  //java code : 
  /*
  class Solution {
    public int pivotIndex(int[] nums) {
      if(nums.length == 0) return - 1;
      int leftSum = 0, rightSum = 0;
      for(int num : nums) 
          rightSum += num;

      for(int i = 0; i < nums.length; i ++) {
        rightSum -= nums[i];
        if(rightSum == leftSum) return i;
        leftSum += nums[i];
      }
      return - 1;
    }
}*/