#include <stdio.h>
#include <stdlib.h>
int *findWordsContaining(char **words, int wordsSize, char x, int *returnSize)
{
    int i = 0;
    int *arr = malloc(wordsSize * sizeof(int));
    int l = 0;
    int index = 0;
    while (i < wordsSize)
    {
        int j = 0;
        while (words[i][j] != '\0')
        {
            if (words[i][j] == x)
            {
                arr[l++] = i;
                index++;
                break;
            }
            j++;
        }
        i++;
    }
    *returnSize = index;
    return arr;
}
int main()
{
    char *words[] = {"leet", "code"};
    char x = 'e';
    int wordsize = 2;
    int returnSize = 0;
    int *array = findWordsContaining(words, wordsize, x, &returnSize);
    int i = 0;
    while(i < returnSize)
    {
        printf("%d\n", array[i]);
        i++;
    }
}