#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//this function implements the Euclidean Algorithm to compute the Greatest Common Divisor (GCD) of two numbers.
//The Euclidean Algorithm is an efficient way to compute the GCD of two integers. The basic idea is based on the principle that:

//The GCD of two numbers a and b is the same as the GCD of b and a % b.

//Where % is the modulus operator, which gives the remainder of the division of a by b. This process continues until one of the numbers becomes 0. The last non-zero number will be the GCD.
/*
Example: GCD(48, 18)
Let’s walk through an example to see how it works.

Initial values: a = 48, b = 18

48 % 18 = 12 (remainder)
Set a = 18, b = 12
Next iteration: a = 18, b = 12

18 % 12 = 6 (remainder)
Set a = 12, b = 6
Next iteration: a = 12, b = 6

12 % 6 = 0 (remainder)
Set a = 6, b = 0
Now b = 0, so the function exits the loop and returns the last non-zero value of a, which is 6.

So, GCD(48, 18) = 6.
*/
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
char* gcdOfStrings(char* str1, char* str2) {
    int num1 = strlen(str1);
    int num2 = strlen(str2);

    char* temp1 = malloc((num1 + num2 + 1) * sizeof(char));
    char* temp2 = malloc((num1 + num2 + 1) * sizeof(char));

     strcpy(temp1, str1);
    strcat(temp1, str2);
    
    strcpy(temp2, str2);
    strcat(temp2, str1);

    if (strcmp(temp1, temp2)== 0)
    {
        int len = gcd(num1, num2);
        char *string = malloc((len + 1) * sizeof(char));
        int i = 0;
        while(i < len)
        {
            string[i] = str1[i];
            i++;
        }
        string[i]= '\0';
        return string;
    }
    
    return "";
}
int main ()
{
    char str1[100] = "ABABAB";
    char str2[] = "ABAB";
    char* string = gcdOfStrings(str1, str2);
    printf("%s\n", string);
}