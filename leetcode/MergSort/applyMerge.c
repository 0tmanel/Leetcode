#include <stdio.h>
#include <stdlib.h>
/*void ft_merge(int arr[], int low, int mid, int high)
{
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    int i = 0;
    int j = 0;
    int leftArray[leftSize];
    int rightArray[rightSize];
    while (i < leftSize)
    {
        leftArray[i] = arr[low + i];
        i++;
    }
    while (j < rightSize)
    {
        rightArray[j] = arr[mid + 1 + j];
        j++;
    }
    int l = 0;
    int r = 0;
    int k = low;
    while (l < leftSize && r < rightSize)
    {
        if(leftArray[l] <= rightArray[r])
        {
            arr[k] = leftArray[l];
            l++;
        }
        else{
            arr[k] = rightArray[r];
            r++;
        }
            k++;
    }
    while (l < leftSize)
    {
        arr[k] = leftArray[l];
        l++;
        k++;
    }
    while (r < leftSize)
    {
        arr[k] = rightArray[r];
        r++;
        k++;
    }


}
void mergeSort(int arr[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    else
    {
        int mid =(low + high) / 2; //i doubt this 
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        ft_merge(arr, low, mid, high);

    }
}
int main ()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int len  = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, len);
    int i = 0;
    while (i < len)
    {
        printf("%d", arr[i]);
        i++;
    }
}*/





void ft_merge(int arr[], int low, int mid, int high)
{
    int leftSize = mid - low + 1;
    int rightSize =  high - mid;
    int i = 0;
    int j = 0;
    int leftARR[leftSize];
    int rightARR[rightSize];
    while (i < leftSize)
    {
        leftARR[i] = arr[low + i];
        i++;
    }
     while (j < rightSize)
    {
        rightARR[j] = arr[mid + 1 + j];
       
        j++;
    }
    int l = 0;
    int r = 0;
    int k = low;
    while (l < leftSize && r < rightSize)
    {
        if(leftARR[l] <= rightARR[r])
        {
            arr[k] = leftARR[l];
            l++;
        }
        else{
            arr[k] = rightARR[r];
            r++;
        }
        k++;
    }
    while (l < leftSize)
    {
        arr[k] = leftARR[l];
        l++;
        k++;
    }
    while (r < rightSize)
    {
        arr[k] = rightARR[r];
        r++;
        k++;
    }

}
void sortList(int arr[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        sortList(arr, low, mid);
        sortList(arr, mid + 1, high);
        ft_merge(arr, low, mid, high);
    }

}
int main ()
{
    int arr[] = {5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    sortList(arr, 0, len);
    int i = 0;
    while (i < len)
    {
        printf("%d", arr[i]);
        i++;
    }
}