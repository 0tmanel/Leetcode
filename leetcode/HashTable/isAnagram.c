#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int ft_len(char* s)
{
    int i = 0;
    while (*s)
    {
        i++;
        s++;
    }
    return i;
}
/*int compare(const void* s, const void* t)
{
   
    return (*(char*)s - *(char*)t);
}
int ft_strcmp(char* s, char* t)
{
    int i = 0;
    while (s[i] == t[i] && s[i] != '\0' && t[i] != '\0')
    {
        i++;
    }
    return s[i] - t[i];
}
bool isAnagram(char* s, char* t) {
    int len = ft_len(s);
    int len2 = ft_len(t);
    qsort(s, len, sizeof(char), compare);
    qsort(t, len2, sizeof(char), compare);

    if(ft_strcmp(s, t) == 0)
    {
        return true;
    }
    return false;
    
}*/




typedef struct HashNode {
    char *key;           // Key (string)
    int value = 0;         // Value (integer)
    struct HashNode *next = NULL;  
} HashNode;

int hashfunction(char key, int size)
{
    return (int)key % size;
}
bool isAnagram(char* s, char* t)
{
    int len = ft_len(s);
typedef struct HashTable {
    HashNode *buckets[len];  // Array of buckets
} HashTable;
int i = 0;
while (s[i] != '\0')
{
    HashNode* new_node[i] = malloc(sizeof(HashNode));
    


}
}
int main ()
{
    char s[] = "anagram";
    char t[] = "marganf";
   int result =  isAnagram(s, t);
   printf("%d", result);
}
/*(unsigned char)s[i]: Casts the character s[i] to an unsigned char. 
In C, characters are typically stored as signed char values, which might 
cause issues for characters with values above 127 (in extended ASCII), 
so the cast to unsigned char ensures that the index is always positive.*/