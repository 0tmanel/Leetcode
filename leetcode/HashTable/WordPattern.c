#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int key(char c) {
    return c - 'a'; // Ensure unique keys for 'a' to 'z'
}

bool wordPattern(char *pattern, char *s) {
    int len = strlen(pattern);
    
    int table[26]; // Store mapping of pattern chars
    char *strs[26]; // Store mapped words
    for (int i = 0; i < 26; i++) {
        table[i] = -1;
        strs[i] = NULL;
    }

    char *currentWord = strtok(s, " ");
    for (int i = 0; i < len; i++) {
        if (currentWord == NULL) return false; // Too few words

        int index = key(pattern[i]);
        
        if (table[index] == -1) {
            // First time seeing this pattern character
            table[index] = 1;
            strs[index] = currentWord;
        } else if (strcmp(strs[index], currentWord) != 0) {
            return false; // Mismatch in mapping
        }

        currentWord = strtok(NULL, " ");
    }

    // **New validation: Check if two different letters map to the same word**
    for (int i = 0; i < 26; i++) {
        if (strs[i] == NULL) continue; // Skip unused slots
        for (int j = i + 1; j < 26; j++) {
            if (strs[j] != NULL && strcmp(strs[i], strs[j]) == 0) {
                return false; // Two different letters mapped to the same word
            }
        }
    }

    return currentWord == NULL; // Ensure no extra words exist
}
int main()
{
    char pattern[] = "abba";
    char str[] = "dog dog dog dog"; // The input string
    int result = wordPattern(pattern, str);
   printf("%d\n", result);

    return 0;
}
/* IMPORTANT
How strtok() Remembers Its Position:
The strtok() function doesn't require you to pass the string on subsequent calls. Instead, it uses internal static state to keep track of the position in the string.

When you call strtok(str, " ") for the first time, it:

Takes the string str and starts looking for tokens based on the delimiter (" ").
Finds the first token (before the first space), replaces the space with \0 (end of string for that token), and returns a pointer to the start of the token.
Internally, strtok() remembers the position of the next character in the string, where the last token ended.
Subsequent Calls to strtok(NULL, " "):
When you call strtok(NULL, " ") in subsequent iterations, you do not pass the string again. Instead, strtok():
Uses its internal memory (from the first call) to continue searching for the next token starting from the last position.
It keeps searching the string, looking for the next delimiter (" "), and returns the next token.
If no more tokens are found, it returns NULL, and the loop stops.
Key Points:
First call: strtok(str, " ") takes the entire string and begins tokenizing it.
Subsequent calls: strtok(NULL, " ") continues from the last position and doesn't need the original string again.
Internal Mechanics:
strtok() uses a static internal pointer to remember where it left off in the string.
This static pointer is not visible to the user. You don't have to manage it manually—strtok() does it automatically.
*/
