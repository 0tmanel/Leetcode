//https://medium.com/javarevisited/expand-from-center-algorithm-dp-pattern-palindrome-306b542ae916
#include <stdio.h>
#include <string.h>
int expandAroundCenter(char* s, int right, int left, int len)
{
    int L = left;
    int R = right;
    while(L >= 0  && R < len && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}
void longestPalindrom(char* s)
{
    int slen = strlen(s);
    if(!s || slen < 1)
    {
        return ;
    }
    int start = 0;
    int end = 0;
    int i = 0;
    while(s[i] != '\0')
    {
       int len1 =  expandAroundCenter(s, i, i, slen);
       int len2 = expandAroundCenter(s, i, i + 1, slen);
       int len = (len1 > len2) ? len1 : len2;

       if(len >= end - start)
       {
        start = i - (len - 1) / 2;
        end = i + len / 2;
       }
       i++;
    }
       while(start <= end)
       {
        printf("%c", s[start]);
        start++;
       }
       printf("\n");
}
int main ()
{
    char *s = "babad";
    //char* str =
     longestPalindrom(s);
}