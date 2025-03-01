#include <stdio.h>
void reverseString(char* s, int sSize) {
    int i = 0;
    while (i < sSize)
    {
        int tem = s[i];
        s[i] = s[sSize - 1];
        s[sSize - 1] = tem;
        sSize--;
        i++;
    }
}
int main ()
{
    char s[] = "hello";
    int size = 5;
    reverseString(s, size);
    printf("%s", s);
}