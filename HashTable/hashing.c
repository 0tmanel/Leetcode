#include <stdio.h>
#include  <stdlib.h>
#define Hsize 10
int hashFunction(int key)
{
    return key % Hsize;
}
void insert(int arr[], int hashTable[])
{
    int j = 0;
    while (j < Hsize)// it is good to make an empty table
    {
        hashTable[j] = -1;
        j++;
    }
    int i = 0;
    while (i < Hsize)
    {
        int index = hashFunction(arr[i]);
       
        while (hashTable[index] != -1)
        {
            index = (index + 1) % Hsize;
        }
        hashTable[index] = arr[i];
        i++;
    }
   
}
void search(int key, int hashTable[])
{
    int index = hashFunction(key);
    if(hashTable[index] == key)
    {
        printf("the element is found");
    }
    else{
        printf("the element is not in the table");
    }

}
int main ()
{
    int arr[] = {2, 4, 5, 7, 90, 23, 67, 83, 44, 22};
    int hashTable[Hsize];
    insert(arr, hashTable);
    search(91, hashTable);
}