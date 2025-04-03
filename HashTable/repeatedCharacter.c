#include <stdio.h>
#include <string.h>
#define SIZE 100
/*
int hashkey(char c, int size)
{
    return c % size;
}
char repeatedCharacter(char* s) {
    int len = strlen(s);
    char bucket[SIZE];
    int j = 0;
    while(s[j] != '\0')
    {
        if(bucket[hashkey(s[j], SIZE)] == 0)
        {
            bucket[hashkey(s[j], SIZE)] = 1;
        }
        else if(bucket[hashkey(s[j], SIZE)] ==  1)
        {
            break;
        }
        j++;
    }
    return s[j];
}*/
int seen(char* bucket, char c)
{
    int i = 0;
    while(bucket[i] != '\0')
    {
        if(bucket[i] == c)
        return 1;
        i++;
    }
    return 0;
}
char repeatedCharacter(char* s) {
    char bucket[SIZE];
    int i = 0;
    int j = 0;
    while(s[i] != '\0')
    {
        if(!seen(bucket, s[i]))
        {
            bucket[j] = s[i];
            j++;
        }
        else if(seen(bucket, s[i]))
        {
            break;
        }
        i++;
    }
    return s[i];
}
int main ()
{
    char s[] = "nwcn";
    char chars = repeatedCharacter(s);
    printf("%c\n", chars);
}