#include <stdio.h>
#include <string.h>
#define Size 128
int key(char key)
{
    return (int) key;
}

int firstUniqChar(char *s)
{
    char bucket[Size] = {0};
    int i = 0;
    while(s[i] != '\0')
    {
        if(bucket[key(s[i])] == 0)
        {
            bucket[key(s[i])] = 1;
        }
        else if(bucket[key(s[i])] > 0)
        {
            bucket[key(s[i])]++;
        }
        i++;
    }
    int j = 0;
    while(s[j] != '\0')
    {
        if(bucket[key(s[j])] == 1)
        {
            break;
        }
        j++;
    }
    if (s[j] == '\0') return -1;
    return j;
}
int main()
{
    char s[] = "aabb";
    int index = firstUniqChar(s);
    printf("%d\n", index);
}