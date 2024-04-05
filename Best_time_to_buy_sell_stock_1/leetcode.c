#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1) return 0;
    if (pricesSize == 2 && prices[0] >= prices[1]) return 0;
    int sell = 0;
    for (int i = 0; i < pricesSize-1; i++){
        for (int j = i+1; j < pricesSize; j++){
            if (prices[j]-prices[i] > sell) sell = prices[j]-prices[i];
        }
    }
    return sell;
}

int main (){
    int nums[] = {7,1,5,3,6,4};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n",maxProfit(nums, numsSize)); 
    return 0;
}