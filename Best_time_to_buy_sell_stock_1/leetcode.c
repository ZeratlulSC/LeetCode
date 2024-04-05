#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1) return 0;
    if (pricesSize == 2 && prices[0] >= prices[1]) return 0;
    int buy = 0;
    int sell = pricesSize - 1;
    int profit = prices[sell] - prices[buy];
    while (sell-buy != 1){
        if (prices[buy+1]<prices[buy]) buy++;
        else sell = sell - 1;
        if (prices[sell] - prices[buy] > profit) profit = prices[sell] - prices[buy];
    }
    return profit;
}

//int maxProfit(int* prices, int pricesSize) {
//    if (pricesSize == 1) return 0;
//    if (pricesSize == 2 && prices[0] >= prices[1]) return 0;
//    int buy = 0;
//    int sell = pricesSize - 1;
//    int profit = prices[sell] - prices[buy];
//    while (sell-buy != 1){
//        if (prices[buy+1]<prices[buy]) buy++;
//        else sell = sell - 1;
//        if (prices[sell] - prices[buy] > profit) profit = prices[sell] - prices[buy];
//    }
//    if (profit<0) return 0;
//    return profit;
//}

int main (){
    int nums[] = {7,1,5,3,6,4};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n",maxProfit(nums, numsSize)); 
    return 0;
}