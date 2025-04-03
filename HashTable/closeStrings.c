#include <stdbool.h>
int compare(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}

bool closeStrings(char* word1, char* word2) {
   qsort(word1, strlen(word1), sizeof(char), compare);
    qsort(word2, strlen(word2), sizeof(char), compare);
    return ft_strstr(word1, word2);
}
int main ()
{
    char *word1 = "abc";
    char *word2 = "acb";
   int result =  closeStrings(word1, word2);
   printf("%d\n", result);
}