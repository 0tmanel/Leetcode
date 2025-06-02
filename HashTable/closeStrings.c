#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define Size 26
int key(char c)
{
    return (c - 'a');
}
void fill(char* word, int* set)
{
    int i = 0;
    while(word[i] != '\0')
    {
            set[key(word[i])]++;
        i++;
    }
}
void fill2(char* word, char* set2)
{
    int i = 0;
    while(word[i] != '\0')
    {
        if(set2[key(word[i])] == 0)
        {
            set2[key(word[i])] = true;
        }
        i++;
    }
}
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

bool closeStrings(char* word1, bool* word2) {
    if(strlen(word1) != strlen(word2))
    return 0;
    int set1[Size] = {0};
    int set2[Size] = {0};
    bool chars1 [Size] = {false};
    bool chars2 [Size] = {false};
   fill(word1, set1);
   fill(word2, set2);
    int i = 0;
    fill2(word1, chars1);
    fill2(word2, chars2);

    // Compare if both words have the same set of characters
    for (int i = 0; i < Size; i++) {
        if (chars1[i] != chars2[i]) {
            return false;  // If characters sets don't match, return false
        }
    }
    //sort the set
     qsort(set1, Size, sizeof(int), compare);
    qsort(set2, Size, sizeof(int), compare);
    
   while(i < Size)
   {
    if(set1[i] !=  set2[i])
    {
        return 0;
    }
    i++;
   }
   return 1;
}
int main ()
{
    char *word1 ="cabbba"; //"ssx";
    char *word2 = "abbccc";//"uau";
   int result =  closeStrings(word1, word2);
   printf("%d\n", result);
}