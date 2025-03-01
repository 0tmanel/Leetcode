/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
 int ft_count(int number)
 {
    int lenght = 0;
   
    unsigned int nb;
    if(number < 0)
    {
       
        nb = (unsigned int)(-number);
        lenght++;
    }
    else
        nb = (unsigned int) number;
        while (nb >= 10)
        {
            nb /= 10;
            lenght++;
        }
        lenght++;
        
        return lenght;
 }
 char *ft_putnbr(int result, char*finalNumber, int len)
{
    
    long nb = result;
    finalNumber[len] = '\0'; 
    int i = 0;
    if(nb < 0)
    {
        finalNumber[0] = '-';
        nb *= -1;
        i = 1;
        //here we printf the sign because the number is negative , then we turn it to a positive by * = 1
    }
    len--;
    while(nb >= 10)
    {
        finalNumber[len] = nb % 10 + '0';
        nb /= 10;
       len--;
    }
    if(nb < 10)
    {
       finalNumber[i] = nb + '0';  
    }
     
    return finalNumber;
}

 char *word(int num)
 {
    int len = ft_count(num);
    char *str = malloc((len + 1) * sizeof(char));
    return ft_putnbr(num, str, len);
 }
char** fizzBuzz(int n, int* returnSize) {
    char **string = malloc((n + 1) * sizeof(char*));
    char* s1 = "FizzBuzz";
    char* s2 = "Fizz";
    char* s3 = "Buzz";
    int i = 1;
    int l = 0;
    while (i <= n)
    {
         if (i % 3 == 0 && i % 5 == 0)
        {
            string[l] = s1;
            l++;
        }
        else if(i % 3 == 0)
        {
            string[l] = s2;
            l++;
        }else if(i % 5 == 0)
        {
            string[l] = s3;
            l++;
        }else{
           string[l] = word(i);
           l++;
        }
        i++;
    }
    *returnSize = n;
    return string;
}
int main ()
{
    int n = 15;
    int returnSize = 0;
    char **string = fizzBuzz(n, &returnSize);
    while (*string)
    {
        printf("%s\n", *string);
        string++;
    }
}