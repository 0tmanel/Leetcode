#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}
bool isPalindrome(char* s) {
    int len = strlen(s);
    
    int i = 0;
    int j = len - 1;
     to_lowercase(s);
     
    while (i < j)
    {
         while (i < j && !isalnum((unsigned char)s[i])) {
            i++;
        }
        while (i < j && !isalnum((unsigned char)s[j])) {
            j--;
        }
         if(s[i] != s[j])
        {  
            return 0;
        }
        i++;
        j--;
    }
 
    return 1;
}
int main ()
{
    char s[]= "A man, a plan, a canal: Panama";

    int res = isPalindrome(s);
    printf("%d\n", res);
}
bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        while (left < right && !isalnum((unsigned char)s[left])) {
            left++;
        }
        while (left < right && !isalnum((unsigned char)s[right])) {
            right--;
        }
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
