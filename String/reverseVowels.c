#include <stdio.h>
#include <string.h>
int isvowel(char c)
{
    if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
    {
        return 1;
    }
     if((c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
     {
        return 1;
     }
    else
    return 0;
}
char* reverseVowels(char* s) {
    int i = 0;
    int j = strlen(s);
    while (i <= j)
    {
        if(isvowel(s[i]) && isvowel(s[j]))
        {
            char t;
            t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
        else if(!isvowel(s[i]) && isvowel(s[j]))
        {
            i++;
            continue;
        }
         else if(isvowel(s[i]) && !isvowel(s[j]))
        {
            j--;
            continue;
        }
            i++,
            j--;
    }
    return s;
}
int main ()
{
    char str[] = "IceCreAm";
    char *string = reverseVowels(str);
    printf("%s\n", string);
}