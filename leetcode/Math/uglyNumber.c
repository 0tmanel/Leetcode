#include <stdbool.h>
#include <stdio.h>
bool isUgly(int n) {
    if(n == 0)
    return 0;
    while (n % 2 == 0)
    {
        n /= 2;
    }
    while (n % 3 == 0)
    {
        n /= 3;
    }
    while (n % 5 == 0)
    {
        n /= 5;
    }
    /* we could use this 
    if(n == 1)
    {
        return 1;
    }
        return 0;
    */
   // but i will use this 
   return n == 1;//The statement return n == 1; is a boolean return expression, which means it evaluates whether n is equal to 1 and directly returns true or if n does not equal 1 it will evaluates to false.
}
int main ()
{
    int result = isUgly(8);
    printf("%d", result);
}

//Algorithm:
//While the number is divisible by 2, divide it by 2.
//While the number is divisible by 3, divide it by 3.
//While the number is divisible by 5, divide it by 5.
//If, after all these divisions, the remaining number is 1, it means the original number had only 2, 3, and 5 as its prime factors.
//Otherwise, the number contains other prime factors.