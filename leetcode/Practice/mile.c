
#include <stdbool.h>
#include <stdio.h>
#define SIZE 10 
int main ()
{
    int arr[SIZE] = {10, 20, 40, 50, 60};
    int i = 0;
   
    while (arr[i] > i)
    {
    i++;
    }
    int j = i - 1;
    int pos = 3;
    while (j >= pos)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    int f = 0;
    while (arr[f] > f)
    {
        f++;
    }
    arr[pos] = 56;
    for(int k = 0; k < f ; k++)
    {
        printf("%d, ", arr[k]);
    }
    int main (int argc, char* argv [])
{
  if(argc > 1)
  {
    int i = 1;
    while (argc >= i)
    {
      write(1, &argv[i], 1);
      i++;
    }
  }
}
}
