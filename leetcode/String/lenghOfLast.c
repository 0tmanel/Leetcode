#include <unistd.h>
#include <stdio.h>
int lengthOfLastWord(char *s)
{
    int i = 0;
    
   
    while (s[i] != '\0')
    {
        i++;
    }
    int j = 0;
    int k = i - 1;

    while (!(s[k] >= 'a' && s[k] <= 'z' || s[k] >= 'A' && s[k] <= 'Z'))
    {
        k--;
    }
    while (s[k] >= 'a' && s[k] <= 'z' || s[k] >= 'A' && s[k] <= 'Z')
    {
       
        
            j++;
            k--;
    }

    return j;
}
int main()
{
    char s[] = "a";
    int result = lengthOfLastWord(s);
    printf("%d", result);
}