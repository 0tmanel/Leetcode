#include <stdio.h>
// int check(char *str, int limit)
// {
//     int i = 0;
//     while(i < limit && str[i])
//     {
//         int j = i + 1;
//         while(j < limit && str[j])
//         {
//             if(str[i] == str[j])
//             {
//                 return 1;
//             }
//             j++;
//         }
//         i++;
//     }
//     return 0;
// }
// int lengthOfLongestSubstring(char* s) {
//     int i = 0;
//     int sum = 0;
//     while(s[i])
//     {
//         int j = 1;
//         //"abcabcbb"
//         while(!check(s + i, j) && s[i + j - 1])
//         {
//             j++;
//         }
//         if(j - 1 > sum)
//         {
//             sum = j - 1;
//         }
//            i++;
//     }
//     return sum;
// }
int lengthOfLongestSubstring(char *s) {
    int seen[256] = {0}; // all ascii characters
    int left = 0, right = 0;
    int max_len = 0;

    while (s[right]) {
        //"abcabcbb";
        if (seen[(unsigned char)s[right]] == 0) {
            seen[(unsigned char)s[right]] = 1;
            int current_len = right - left + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
            right++;
        } else {
            seen[(unsigned char)s[left]] = 0;
            left++;
        }
    }
    return max_len;
}
int main ()
{
    char *str = "abcabcbb";
    int sum = lengthOfLongestSubstring(str);
    printf("%d\n", sum);
}