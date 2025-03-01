#include <stdio.h>
 int ft_strlen(char *str)
 {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
 }
char* removeChar(char *str) {
    int i = 0;
    int len = ft_strlen(str);
    char string[len];
int l = 0;
   while (str[i] != '\0')
   {
        if(str[i] >= '0' && str[i] <= '9' || str[i--] >= 'a' && str[i--] <= 'z')
        {
            i++;
        }
        else{
            str[l] = str[i];
            l++;
        }
       
    i++;
   }
    str[l] = '\0';  // Null-terminate the new string
    return str;
}
char* clearDigits(char* s) {
    return removeChar(s);
}
int main ()
{
    char s[] = "cb34";
    char *string = clearDigits (s);
    printf("%s\n", string);
}