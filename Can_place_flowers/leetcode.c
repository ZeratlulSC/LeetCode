#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 1 && flowerbed[0] == 1 && n != 0) return false;
    if (flowerbedSize == 1 && n == 0) return true;
    if (flowerbedSize == 1 && flowerbed[0] == 0 && n == 1) return true;
    for (int i = 0; i < flowerbedSize;i++){
        if (flowerbed[i] == 1 && i!=0 && i!= flowerbedSize-1) {
            flowerbed[i-1] = 1;
            flowerbed[i+1] = 1;
            i = i + 1;
        }
        else if (flowerbed[i] == 1 && i==0) {
            flowerbed[i+1] = 1;
            i = i + 1;
        }
        else if (flowerbed[i] == 1 && i==flowerbedSize-1) {
            flowerbed[i-1] = 1;
            i = i + 1;
        }
    }
    int freeplaces = 0;
    for (int i = 0; i < flowerbedSize;i++){
        if (flowerbed[i] == 0 && i!= 0 && i !=flowerbedSize-1){
            flowerbed[i-1] = 1;
            flowerbed[i+1] = 1;
            i = i + 1;
        }
        else if (flowerbed[i] == 0 && i==0) {
            flowerbed[i+1] = 1;
            i = i + 1;
        }
        else if (flowerbed[i] == 0 && i==flowerbedSize-1) {
            flowerbed[i-1] = 1;
            i = i + 1;
        }
    }
    for (int i = 0; i < flowerbedSize; i++){
        if (flowerbed[i] == 0) freeplaces++;
    }
    if (freeplaces < n) return false;
    return true;
}

int main (){ 
    int flowerbed[] = {1,0,1,0,0,1,0};
    int flowerbedSize = sizeof(flowerbed)/sizeof(int);
    int n = 1;
    printf("%d\n", canPlaceFlowers(flowerbed,flowerbedSize, n));
    return 0;
}