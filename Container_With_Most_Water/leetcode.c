#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b){
    if (a<b) return a;
    return b;
}

int area_f(int a, int b, int c, int d){
    return (b-a)*min(d,c);
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize-1;
    int area = area_f(left, right, height[left], height[right]);
    int area_max = area;
    printf("area = %d\n", area);
    int moved = 0;
    while (heightSize > 2){
        if (height[left] <= height[right] && right!=(left+1)){// && (left+1, right, height[left+1], height[right]) > area){
            left++;
            area = area_f(left, right, height[left], height[right]);
            if (area > area_max) area_max = area;
            printf("left moved, area = %d, left = %d right = %d\n", area, height[left], height[right]);
            moved = 1;
        }
        else if (height[left] > height[right] && left!=(right - 1)){// && area_f(left, right-1, height[left], height[right-1]) > area){
            right--;
            area = area_f(left, right, height[left], height[right]);
            if (area > area_max) area_max = area;
            printf("right moved, area = %d left = %d right = %d\n", area, height[left] , height[right]);
            moved = 1;
        }
        if (moved == 0) break;
        moved = 0;
    }
    return area_max;
}

int main (){ 
    int heightSize = 7;
    int height[] = {1,3,2,5,25,24,5};
    printf("max area = %d\n", maxArea(height,heightSize));
    return 0;
}