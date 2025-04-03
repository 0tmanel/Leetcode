#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compress(char *chars, int charsSize)
{
    int i = 0;
    int index = 1;
    int l = 0;
    char temp[10];
    int k = 0;
    if (charsSize == 1)
        return 1;

    int j = 0;
    
    while (i < charsSize)
    {
        index = 1;
        char current = chars[i];
        //'a', 'a', 'b', 'b', 'c', 'c', 'c'
        while (i + 1 < charsSize && chars[i] == chars[i + 1])
        {
            index++;
            i++;
        }
        chars[j++] = current;
        //convert only when it is more than 1
        if (index > 1)
        {
            while (index > 0)
            {
                temp[k++] = (index % 10) + '0';
                index /= 10;
            }
            int in = k - 1;
            while (in >= 0)
            {
                chars[j++] = temp[in];
                in--;
            }
        }

        i++;
    }
    
    return j;
}

int main()
{
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int charsSize = 7;
    int sum = compress(chars, charsSize);
    printf("%d\n", sum);
}