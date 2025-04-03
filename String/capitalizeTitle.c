#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int count(char* title) {
    int count = 0;
    int in_word = 0;
    while (*title) {
        if (*title != ' ' && !in_word) {
            in_word = 1;
            count++;
        } else if (*title == ' ') {
            in_word = 0;
        }
        title++;
    }
    return count;
}
void word(char* title, int *array)
{
     int i = 0;
    int j = 0;
    int index = 0;
    while(title[i] != '\0')
    {
        if(isalpha(title[i]))
        {
            index++;
        }
        if((title[i]) == ' ')
        {
            array[j] = index;
            index = 0;
           j++;
        }
        i++;
    }
     array[j] = index;

}
char* capitalizeTitle(char* title) {
    int len = count(title);
   int *array = malloc(len * sizeof(int));
   word(title, array);
   int l = 0;
   while(l < len)
   {
    printf("%d ", array[l]);
    l++;
   }
           int i = 0;
           int j = 0;
         
        while (title[i] != '\0' && j < len)
        {
           if(array[j] <= 2)
           {
            if(title[i] >= 'A' && title[i] <= 'Z')
            {
                title[i] += 32;
            }
           }
           else if(array[j] > 2)
           {
            if(i == 0 || title[i - 1] == ' ')
            {
                if(title[i] >= 'a' && title[i] <= 'z')
                {
                    title[i] -= 32;
                }
            }
            else if(title[i] >= 'A' && title[i] <= 'Z')
            {
                title[i] += 32;
            }
           }
            if(title[i] == ' ')
           {
            j++;
           }
           i++;
        }
        return title;
}
/*
//hahhaha the easy one 
char* capitalizeTitle(char* title) {
    int len = strlen(title);
  for (int i = 0, j = 0; i <= len; ++i) {
        if (i == len || title[i] == ' ') {
            if (i - j > 2)
                title[j] = toupper(title[j]);
            j = i + 1;
        }
        else
            title[i] = tolower(title[i]);
    }
    return title;
}*/
int main (){
    char title[] = "First leTTeR of EACH Word";
    char* string =  capitalizeTitle(title);
    printf("%s\n", string);
}