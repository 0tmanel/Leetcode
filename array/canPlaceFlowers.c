#include <stdbool.h>
#include <stdio.h>
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int trueValue = 0;
   
    int j = 0;
    while (j < flowerbedSize)
    {
        if (flowerbed[j] == 0)
        {
            int emptyPrev = (j == 0 || flowerbed[j - 1] == 0);
            int emptyNext = (j == flowerbedSize - 1 || flowerbed[j + 1] == 0);

            if (emptyPrev && emptyNext)
            {
                flowerbed[j] = 1; // Place a flower
                trueValue++;
                 if (trueValue >= n) return true;
            }
        }
            j++;
    }
     return trueValue >= n;
}
    int main()
    {
        int flowerbed[] = {1, 0, 0, 0, 1};
        int flowerbedSize = 5;
        int n = 2;
        int num = canPlaceFlowers(flowerbed, flowerbedSize, n);
        printf("%d\n", num);
    }