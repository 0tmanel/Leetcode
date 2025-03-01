#include <stdio.h>
#include <stdlib.h>

/*void ft_merg(int leftArr[], int rightArr[], int arr[], int len)
{
   
    int leftsize = len / 2;
    int rightsize = len - leftsize;
    int i = 0; int l = 0; int r = 0;
    while (l < leftsize && r < rightsize)
    {
        if(leftArr[l] < rightArr[r])
        {
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        else{
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }
    while (l < leftsize)
        {
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        while (r < rightsize)
        {
            arr[i] = rightArr[r];
            i++;
            r++;
        }

}
void ft_merge_sort(int arr[], int len)
{
   
    if(len <= 1)
    {
        return;
    }
    int mid = len / 2;
    int rightArr[len - mid];
    int leftArr[mid];
    int i = 0;
    int j = 0;
    while (i < len )
    {
        if(i < mid)
        {
            leftArr[i] = arr[i];
        }
        else{
            rightArr[j] = arr[i];
            j++;
        }
            i++;
    }
    ft_merge_sort(leftArr, mid - 1);
    ft_merge_sort(rightArr, len - mid - 1);
    ft_merg(leftArr, rightArr, arr, len);

}*/
void merge(int arr[], int low, int mid, int high)
{
    /*Once the array is split into individual elements, the merging starts.
    In the merge sort algorithm, 
    the first call to merge will not directly handle the full
     halves of the array like 54 and 321 at the very beginning. 
     Instead, it will start merging much smaller subarrays, such as individual elements, 
     and then gradually work its way up to larger subarrays.*/
    int lefts = mid - low + 1;
    int rights = high - mid;
    int leftarr[lefts];
    int rightarr[rights];
    int i = 0;
    int j = 0;
    while (i < lefts) // COPY ELEMNTS IN TEMP ARRAY BEFORE WE MERGE THEM
    {
        leftarr[i] = arr[low + i];
        i++;
    }
    while (j < rights)
    {
        rightarr[j] = arr[mid + 1 + j];
        j++;
    }
    int l = 0;
    int r = 0;
    int k = low;

    while (l  < lefts && r < rights )
    {
        if(leftarr[l] <= rightarr[r])
        {
            arr[k] = leftarr[l];
            l++;
        }
        else{
            arr[k] = rightarr[r];
            r++;

        }
        k++;*/
        /*Each iteration of the inner loop of merge performs 
        one element comparison and moves one element to the output.*/
    }
    /*After the main comparison loop, 
    one of the arrays might still have remaining elements. 
    The next two while loops handle this:*/
    while (l < lefts)
    {
       arr[k] = leftarr[l];
        l++;
        k++;
    }
    while (r < rights)
    {
       arr[k] = rightarr[r];
        r++;
        k++;
    }

}
void ft_merge_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2 ;
      ft_merge_Sort(arr, low, mid);//for the left array
       ft_merge_Sort(arr, mid + 1, high);//for the right one 
        merge(arr, low, mid, high);
    }
}
int main ()
{
    int array[] = {5, 4, 3, 2, 1};
   int len = sizeof(array) / sizeof(array[0]);

    ft_merge_Sort(array, 0, len - 1);
    int i = 0;
    while (i <  len)
    {
        printf("%d", array[i]);
        i++;
    }
}*/