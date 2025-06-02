#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
bool isIsomorphic(char* s, char* t) {
    char buffer[255]= {0};
    char buffer2[255]= {0};
    int i ,j = 0;
    if(strlen(s) != strlen(t))
    {
        return false;
    }
    while(s[i] != '\0')
    {
        buffer[s[i]]++;
        i++;
    }
     while(t[j] != '\0')
    {
        buffer2[t[j]]++;
        j++;
    }
    i = 0;
    j = 0;
    while(s[i] != '\0' && t[j] != '\0')
    {
        if(buffer[s[i]] != buffer2[t[j]])
        {
            return false;
        }
        i++;
        j++;
    }
    return true;

}
int main()
{
    char* s = "egg";
    char *t = "add";
    bool ret = isIsomorphic(s, t);
    printf("%d\n", ret);
}
/* i = 0;
    j = 0;
    int count = 0;
    int count2 =  0;
    while(s[i] != '\0')
    {
       count += buffer[s[i]];
        i++;
    }
     while(s[j] != '\0')
    {
        buffer[t[j]]++;
        j++;
    }
    return true;
*/