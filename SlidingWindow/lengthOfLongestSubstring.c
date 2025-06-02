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