#include <stdio.h>
/*int identical_right(int snow1[], int snow2[], int start)
{ // bugged!
    int offset;
    for (offset = 0; offset < 6; offset++)
    {
        if (snow1[offset] != snow2[start + offset])
            return 0;
    }
    return 1;
}*/
/*int identical_right(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;
    for (offset = 0; offset < 6; offset++)
    {
        snow2_index = start + offset;
        if (snow2_index >= 6)
            snow2_index = snow2_index - 6;
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}*/
int identical_right(int snow1[], int snow2[], int start)
{
    int offset = 0;
    while (offset < 6)
    {
        if (snow1[offset] != snow2[(start + offset) % 6])
        {
            return 0;
        }
        offset++;
    }
    return 1;
}
int identical_left(int snow1[], int snow2[], int start)
{
    int offset = 0;
    int snow2_index;
    snow2_index = offset - start;
    while (offset < 6)
    {
        if (snow2_index < 0)
        {
            snow2_index = snow2_index + 6;
        }
        if (snow1[offset] != snow2[snow2_index]) // we can not use the reminder here
        {
            return 0;
        }
        offset++;
    }
    return 1;
}
int are_identical(int snow1[], int snow2[])
{
    int start = 0;
    while (start < 6)
    {
        if (identical_right(snow1, snow2, start))
        {
            return 1;
        }
        if (identical_left(snow1, snow2, start))
        {
            return 1;
        }
        start++;
    }
    return 0;
}
void identify_identical(int snowflakes[][6], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (are_identical(snowflakes[i], snowflakes[j]))
            {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }
    printf("No two snowflakes are alike.\n");
}
#define SIZE 100000
int main()
{
    /*In the case of a two-dimensional array, you are passing a pointer to an array of arrays.
     This means you need to explicitly define the size of at least the second dimension when
      passing it to a function. The compiler needs to know how to
      calculate the memory offsets when accessing array elements.*/

        static int snowflakes[SIZE][6];
        int n, i, j;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 6; j++)
                scanf("%d", &snowflakes[i][j]);
        identify_identical(snowflakes, n);

        }
        return 0;
    
}