#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* addStrings(char* num1, char* num2) {
   
     __int128  result1 = 0;
    __int128  result2 = 0;
    __int128 sum;
    int i  = 0;
    if(num1[i] == '0' && num2[i] == '0')
    {
        
        return num1;
    }
    while (num1[i] != '\0')
    {
        result1 *= 10;
        result1 += num1[i] - 48;
        i++;
    }
    int j = 0;
     while (num2[j] != '\0')
    {
        result2 *= 10;
        result2 += num2[j] - 48;
        j++;
    }
    sum = result1 + result2;
    char* arr;
    arr = malloc(10 * sizeof(char));
    int k = 0;
    while (sum > 0)
    { 
        arr[k] = sum % 10 + 48;
       sum /= 10;
        k++;
    }
   arr[k] = '\0';
   int l = 0;
   while (l < k / 2)
   {
   int tem = arr[l];
   arr[l] = arr[k - l - 1];
   arr[k - l - 1] = tem;
    l++;
   }
    return arr;
}
int main ()
{
    char num1[] = "401716832807512840963";
    char num2[] = "167141802233061013023557397451289113296441069";
  char* result = addStrings(num1, num2);
  printf("%s", result);
}