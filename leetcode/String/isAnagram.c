#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int compar(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}
bool isAnagram(char* s, char* t) {
    qsort(s, strlen(s), sizeof(char), compar);
     qsort(t, strlen(t), sizeof(char), compar);
     if(strcmp(s, t) == 0)
     {
        return 1;
     }
     return 0;
}
int main ()
{
    char* s  = "anagram";
    char *t = "margana";
    int ret =  isAnagram(s, t);
    printf("%d\n", ret);
}