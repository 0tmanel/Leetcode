/*Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
We keep doing this until we get all elements moved to correct position.*/
#include <stdio.h>
#include <stdlib.h>
int find_smallest(int *arr, int size)
{
    int smallest = arr[0];
    int smallest_index = 0;
    int i = 0;
    while(i < size)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            smallest_index = i;
        }
        i++;
    }
    return smallest_index;
}
void swap(int *c, int *c2)
{
    int t = *c;
    *c = *c2;
    *c2 = t;
}
int *array(int *array, int size)
{
   int i = 0;
   
   while(i < size)
   {
   int smallest =  find_smallest(array + i, size - i) + i;
   //we are working only with sub array here so we need to add one because we alwyse add one pointer when we call the function
   swap(&array[i], &array[smallest]);
   i++;
   }
   return array;
}
int main()
{
    int arr[] = {4, 99, 2, 64, 50};
    int size = 5;
    int *smallest = array(arr, size);
    int i = 0;
    while(i < size)
    {
    printf("%d\n", smallest[i]);
    i++;
    }
}