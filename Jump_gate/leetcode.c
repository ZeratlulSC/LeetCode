#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int advanced = 0;
    if (nums[0] == 0 && numsSize != 1) return false;
    if (nums[0] == 0 || numsSize == 1) return true;
    for (int i = 0; i < numsSize;){
        for (int j = i+1; j <= i+nums[i] && j < numsSize;j++){
            if (nums[j]>=nums[i] || j == i+nums[i] || nums[j] + j >= numsSize - 1){
                i = j;
                advanced = 1;
                break;
            }
        }
        if (i + nums[i] >= numsSize-1) return true;
        if (advanced == 0) return false;
        advanced = 0;
    }
    return false;
}

int main (){
    int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n",canJump(nums, numsSize)); 
    return 0;
}
