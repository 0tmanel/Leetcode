#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000
#define STACK_SIZE 1000

char* decodeString(const char* s) {
    int countStack[STACK_SIZE]; 
char stringStack[STACK_SIZE][MAX_LEN];
int countTop = -1;
int stringTop = -1;

char current[MAX_LEN] = "";

    int i = 0;
    int num = 0;
    current[0] = '\0';  // Reset the current working string

    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            countStack[++countTop] = num;
            stringTop++;
            strcpy(stringStack[stringTop], current);
            current[0] = '\0';  // Reset current
            num = 0;
        } else if (s[i] == ']') {
            int repeat = countStack[countTop--];
            char temp[MAX_LEN] = "";
            for (int j = 0; j < repeat; j++) {
                strcat(temp, current);
            }
            strcat(stringStack[stringTop], temp);
            strcpy(current, stringStack[stringTop]);
            stringTop--;
        } else {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
        i++;
    }

    return strdup(current);  // Duplicate so it survives after function returns
}
int main()
{
    char *str = "3[c]";
    printf("%s\n", decodeString(str));
}