#include <stdio.h>
#include <stdlib.h>
// we did this by converting x into string
int sumOfTheDigitsOfHarshadNumber(int x)
{
    char str[3];
    snprintf(str, sizeof(str), "%d", x);
    int sum = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        sum += str[i] - '0';
        i++;
    }
    if (x % sum == 0)
    {
    return sum;
    }
    
    else 
    return -1;
    
}
int main()
{
     int result = sumOfTheDigitsOfHarshadNumber(18);
     printf("%d\n", result);
} 
//temp % 10 gets the last digit of temp.
//sum += temp % 10 adds this last digit to sum.
//temp /= 10 removes the last digit (integer division by 10).
//The loop continues until temp becomes 0.
//here we could do it just by dividing and storing 
/*

 int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int sum=0;
        while(temp>0){
            sum += temp%10;
            temp /= 10;
        }
        if(x%sum==0){
            return sum;
        }
        return -1;
    }
*/