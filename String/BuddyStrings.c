#include <string.h> 
#include <stdio.h>
#include <stdbool.h>
void swap(char *c, char *c2)
{
    char t = *c;
    *c = *c2;
    *c2 = t;
}
bool buddyStrings(char* s, char* goal) {
    int i = 0;
    while(s[i] != '\0')
    {
        int j = i + 1;
        while(s[j] != '\0')
        {
            swap(&s[i], &s[j]);
            if(strcmp(s, goal) == 0)
            {
                return true;
            }
              swap(&s[i], &s[j]);
            j++;
        }
        i++;
    }
    return false;
}
int main ()
{
    char s[] = "aaaaaaabc";
    char goal[] = "aaaaaaacb";
    bool retr = buddyStrings(s, goal);
    printf("%d\n", retr);
}
