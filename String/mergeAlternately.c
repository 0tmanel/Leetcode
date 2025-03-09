#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * mergeAlternately(char * word1, char * word2){
    int sum = strlen(word1) + strlen(word2);
    char*word = malloc((sum + 1) * sizeof(char));
    if(!word)
    {
        return NULL;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (word1[i] != '\0' || word2[k] != '\0')
    {
        if(word1[i] == '\0' && word2[k] != '\0')
        {
            while(word2[k] != '\0')
            {
            word[j] = word2[k];
            k++;
            j++;

            }
            break;
           
        }
        else if(word2[k] == '\0' && word1[i] != '\0')
        {
            while(word1[i] != '\0')
            {
            word[j] = word1[i];
            i++;
            j++;
            }
            break;
        }
        else {

            word[j] = word1[i];
            j++;
            word[j] = word2[k];
            j++;
        }
        i++;
        k++;
    }
    word[j] = '\0';
    return word;
}
int main ()
{
    char* word1 = "ab";
    char* word2 = "pqrs";
    char* retu = mergeAlternately(word1, word2);
    printf("%s\n", retu);
}