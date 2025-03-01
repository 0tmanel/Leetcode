/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int count(char word, char sep) {
    return (word == sep) ? 0 : 1;
}
int ft_strlen(char **words, char sep, int size)
{
    int i = 0;
    int j;
    int index = 0;
    while (i < size)
    {
        j = 0;
        while (words[i][j] != '\0')
        {
            if (count(words[i][j], sep))
            {
                index++;
            }
          j++;
        }
        i++;
    }
    return index;
}
int count_str(char*str, int sep, int *j)
{
    int i = *j;
    while (str[i] == sep)
    i++;
    int end = i;
    while (str[end] != '\0' && count(str[end], sep))
    {
        end++;
    }
    *j = end;
    int len = end - i;
    return len;

}
char* word(char*str, char sep, int size, int* j)
{
    int len = count_str(str, sep, j);
   
    char *string = malloc((len + 1) * sizeof(char));
    int i = 0;
    while (i < len)
    {
        string[i] = str[*j - len + i];
       
        i++;
    }
    
    string[i] = '\0';
return string;
}
char** splitWordsBySeparator(char **words, int wordsSize, char separator, int *returnSize)
{
    int len = ft_strlen(words, separator, wordsSize);
    char **string = malloc((len + 1) * sizeof(char *));
    int l = 0;
    int i = 0;
    while (i < wordsSize)
    {
        int j = 0;
        while (words[i][j] != '\0')
        {
            while (words[i][j] != '\0' && !count(words[i][j], separator))
            {
                j++;
            }
            if (words[i][j] != '\0')
            {
                string[l] = word(words[i], separator, wordsSize, &j);
                l++;
            }
            while (words[i][j] != '\0' && count(words[i][j], separator))
                j++;
        }
        i++;
    }
    string[l] = 0;
    *returnSize = l;
    return string;
}
int main()
{
    char *words[] = {"hello how are", "my name is otman"};
    int wordSize = 2;
    char separator = ' ';
    int returnSize = 0;
     char **string = splitWordsBySeparator(words, wordSize, separator, &returnSize);
     int i = 0 ;
     while (string[i] != 0)
     {
        printf("%s\n", string[i]);
        i++;
     }
}