#include <stdio.h>
#include <string.h>
#include <ctype.h>
int scoreOfString(char* s) {
    int i = 0;
    int sum = 0; 
    int len = strlen(s);
   while (i < len - 1 )
   {
      int diff = s[i] - s[i + 1];
     sum += (diff < 0) ? -diff : diff;    
      i++;
   }
    return sum;
}
int main ()
{
    char s[] = "hello";
    int score = scoreOfString(s);
    printf("%d", score);
}