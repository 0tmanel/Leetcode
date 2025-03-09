#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int vowel(char*word)
{
    int i= 0;
    while (word[i] != '\0')
    {
        if((word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') || (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'))
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int digit(char*word)
{
    int i= 0;
    while (word[i] != '\0')
    {
        if(word[i] >= '0' && word[i] <= '9')
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int alpha(char*word)
{
    int i= 0;
    while (word[i] != '\0')
    {
        if(isalpha(word[i]))
        {
            return 1;
        }
        i++;
    }
    return 0;
}
bool isValid(char* word) {
    int i  = 0;
    if(strlen(word) <= 3)
    {
        return 0;
    }
   if(alpha(word) && vowel(word) && digit(word))
   {
    return 1;
   }
    else
    {
    return 1;
    }   
}
int main ()
{
    char word[] = "any";
    int result = isValid(word);
    printf("%d\n", result);
}