#include <stdio.h>
#include <string.h>
int compare(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}
char findTheDifference(char* s, char* t) {
    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);
   int len = strlen(s);
   int i = 0;
   while(s[i] != '\0' && s[i] == t[i])
   {
    i++;
   }
   return t[i];
}
/*
char findTheDifference(char* s, char* t) {
    int a = 0, b = 0;
    for (int i = 0; i < strlen(s); i++){
        a = a + (int)s[i];
    }
    for (int j = 0; j < strlen(t); j++){
        b = b + (int)t[j];
    }

    char z = (b - a);
    return z;
    
}
*/
/*
char findTheDifference(char* s, char* t) {
    char result = 0;
    while (*s) {
        result ^= *s;
        s++;
    }
    while (*t) {
        result ^= *t;
        t++;
    }
    return result;
}*/
int main ()
{
    char s[] = "cdba";
    char t[]  = "cdbae";
   char c =  findTheDifference(s, t);
   printf("%c\n", c);
}
/*
s = "abcd";
t = "abcde";

ASCII values:
a=97, b=98, c=99, d=100, e=101

Sum of s = 97+98+99+100 = 394
Sum of t = 97+98+99+100+101 = 495

Difference = 495 - 394 = 101
char(101) = 'e'
*/