/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 66. Plus One
//You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

//Increment the large integer by one and return the resulting array of digits.
#include <stdio.h>
#include <stdlib.h>
/*
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* arr ;
    int i = 0;
    while (i < digitsSize) {
        if (digits[digitsSize - 1] == 9) {
             *returnSize += 1;
            arr = malloc(digitsSize * sizeof(int));
            arr[0]= 1;
            arr[1] = 0;
            *returnSize = 2;
            return arr;
        }
        if (digits[i] == digits[digitsSize - 1]) {
            digits[i]++;
            arr[i] = digits[i];
            *returnSize = digitsSize;
            return arr;
        }
        arr[i] = digits[i];
        i++;
    }
    *returnSize = 0;
    return NULL;
}*/





int main (){
    int digits[] = {9};
    int digitsSize = 1;
    int returnsize;
    int *retu = plusOne(digits, digitsSize, &returnsize);
    int i = 0;
    while (i < digitsSize)
    {
        printf("%d", retu[i]);
        i++;
    }
    printf("\n");
}