#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int ft_strstr(char *str, char *to_find)
 {
    if(to_find[0] == '\0')
    {
        return 0;
    }
    int i = 0;
    int j;
   
    while (str[i] != '\0')
    {
        j = 0;
        
         while (to_find[j] == str[i + j] && to_find[j] != '\0')
         {
            j++;
         }
            if(to_find[j] == '\0')
            {
                return 1;
            }
         i++;
    }
    return 0;

 }
int repeatedSubstringPattern(char* s) {
   int len = strlen(s); 
   char* str = malloc((len * 2) + 1 * sizeof(char));
   strcpy(str, s);
   strcat(str, s);
   int len2 = strlen(str);
   int i = 0;
   int j = 1;
   char* str2 = malloc(((len * 2) - 2 + 1) * sizeof(char));
   while(j < len2 - 1)
   {
    str2[i++] = str[j++];
   }
  return ft_strstr(str2, s);
}
int main ()
{
    char* s = "abc";
   int num = repeatedSubstringPattern(s);
   printf("%d\n", num);
}