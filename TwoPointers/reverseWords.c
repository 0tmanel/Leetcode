#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char* reverse(char*s, int start, int end)
{
    while(start < end)
    {
            char t;
            t = s[start];
            s[start] = s[end];
            s[end] = t;
            start++;
            end--;
    }
    return s;
}
char *leadingspaces(char *s, int start, int end)
{
    while(s[start] &&  isspace(s[start]))
        start++;
     while(start <= end &&  isspace(s[end]))
     end--;
     int i = 0; int j = 0;
     int flag = 0;
     while(j <= end)
     {
        if(isspace(s[j]))
        {
            if(!flag)
            {
                s[i++] = ' ';
                flag = 1;
                
            }
        }
        else {
        s[i] = s[j];
        flag = 0;
        i++;
        }
        j++;
     }
     s[i] = '\0';
     return s;

}
char* reverseWords(char* s) {
    int len = strlen(s) - 1;
    s = leadingspaces(s, 0, len);
    reverse(s, 0, strlen(s) - 1);
    int start = 0; int end = 0;
    while ( end < len) {
        if (s[end] == ' ' || s[end] == '\0') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
        end++;
    }
    return s;
}
int main()
{
    char s[] = "  the sky is blue  ";
     char *string = reverseWords(s);
     printf("%s\n", string);
    
}