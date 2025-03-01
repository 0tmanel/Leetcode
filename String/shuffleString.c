#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* restoreString(char* s, int* indices, int indicesSize) {
    int j = 0;
    int len = strlen(s);
    char * arr = malloc(len + 1 ); 
        while (j < indicesSize )
        {
           
            arr[indices[j]] = s[j];
            j++;
        }
       arr[len] = '\0';
    return arr;
}
int main ()
{ 
    char s[] = "codeleet";
    int indices[] = {4, 5, 6, 7, 0, 2, 1, 3};
    int sizeI = 8;
   char* result = restoreString(s, indices, sizeI);
   printf("%s", result);
}