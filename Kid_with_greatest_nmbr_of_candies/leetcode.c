#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    int max_candies = candies[0];
    for (int i = 0; i < candiesSize; i++){
        if (candies[i] > max_candies) max_candies = candies[i];
    }
    printf("%d\n", max_candies);
    bool *ret = (bool*)malloc(candiesSize*sizeof(bool));
    for (int i = 0; i < candiesSize; i++){
        if (candies[i] + extraCandies >= max_candies) ret[i] = true;
        else ret[i] = false;
    }
    for (int i = 0; i < *returnSize; i++) printf("%d ", ret[i]);
    printf("\n");
    return ret;
}

int main (){
    int candies[] = {2,3,5,1,3};
    int candiesSize = sizeof(candies)/sizeof(int);
    int extraCandies = 3;
    int *returnsize = malloc(4);
    kidsWithCandies(candies, candiesSize, extraCandies, returnsize);
    return 0;
}