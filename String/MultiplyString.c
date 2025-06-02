#include <stdio.h>
#include <stdlib.h>
unsigned long long ft_atoi(char* str)
{
    int i = 0;
    unsigned long long result = 0;
    while(str[i] != '\0')
    {
        result = result * 10 + str[i] - '0';
        // result = result * 10 ;
        // result += str[i] - '0'
        i++;
    }
    return result;
}
int calcu(unsigned long long nbr)
{
    int i = 0;
    while(nbr != 0){
        nbr /= 10;
        i++;
    }
    return i;
}
void putnbr(char * str, int n, unsigned long long sum)
{
    str[n] = '\0';
    int i = n - 1;
    while(sum != 0)
    {
        str[i--] = sum % 10 + '0';
        sum /= 10;
    }
}
char* multiply(char* num1, char* num2) {
   unsigned long long n1 = ft_atoi(num1);
    unsigned long long n2 = ft_atoi(num2);
    unsigned long long sum = n1 * n2;
   int len =  calcu(sum);
   char *string = malloc(len + 1 * sizeof(char));
   if(sum == 0)
   {
    string[0] = '0';
    string[1] = '\0';
    return string;
   }
   putnbr(string, len, sum);
   return string;
}
int main ()
{
    char *num1 = "6913259244";
    char *num2 = "71103343";
   char*string = multiply(num1, num2);
   printf("%s\n", string);
}