#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool isSubsequence(char* s, char* t) {
    int flag = 0;
    int i = 0;
        int j = 0;
    while(s[i] != '\0')
    {
        while(t[j] != '\0')
        {
            if(s[i]== t[j])
            {
                flag++;
                j++;
                break;
            }
            j++;
        }
        i++;
    }
    if(strlen(s) == flag)
    {
        return 1;
    }
   
    return 0;
}
int main ()
{
    char s[] = "abc";
    char t[] = "ahbgdc";
    int retu = isSubsequence(s, t);
    printf("%d\n", retu);
}