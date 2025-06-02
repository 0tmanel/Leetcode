#include <stdio.h>
#include <stdlib.h>
int** fill(int** grid, int gridSize)
{
    int i = 0;
    int **array = malloc(gridSize * sizeof(int*));
    while(i < gridSize)
    {
        int j = 0;
        
        int *array2 = malloc(gridSize * sizeof(int));
        int p = 0;
        while(j < gridSize)
        {
            array2[p] = grid[j][i];
            p++;
            j++;
        }
        array[i] = array2;
        i++;
    }
    return array;
}
int ft_calcu(int* grid, int* array, int size)
{
    int i = 0;
    while(i < size)
    {
        if(grid[i] != array[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int **array = fill(grid, gridSize);
    int i = 0;
    int index = 0;
    while( i < gridSize)
    {
        int j = 0;
        while(j < gridSize)
        {
            index += ft_calcu(grid[i], array[j], gridSize);
            j++;
        }
        i++;
    }
    *gridColSize = gridSize;
    return index;
}
int main ()
{
    //C doesn’t support initializing int ** directly like that. You’d need to allocate memory and assign values manually.
    int grid[4][4] = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    int *grid_ptrs[4];
    for (int i = 0; i < 4; i++) {
        grid_ptrs[i] = grid[i];
        /*This is done to convert a 2D array (int grid[3][3]) into an array of pointers (int *grid_ptrs[3]) that we can safely treat like an int**.
💡 Why is this necessary?
In C:
int grid[3][3] is not the same as int**.
grid is a contiguous block of 9 integers in memory.
But int** means: "a pointer to a pointer to int", which usually points to an array of pointers, where each pointer points to a row.
So if you just cast like this:
equalPairs((int**)grid, 3); // ❌ BAD
It doesn't work safely, because the memory layout is different. You’d be accessing memory the wrong way*/
    }
    printf("%d\n", equalPairs(grid_ptrs, 3, gridColSize));
}