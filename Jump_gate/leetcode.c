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
            if (nums[j]>=nums[i] || nums[j-1] == 0 && nums[j] != 0 || j == i+nums[i]){
                i = j;
                advanced = 1;
                break;
            }
            printf("i=%d j=%d\n", i, j);
        }
        if (i + nums[i] >= numsSize-1) return true;
        if (advanced == 0) return false;
        advanced = 0;
    }
    return false;
}

int main (){
    int nums[] = {4,4,3,2,2,2,1,2};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n",canJump(nums, numsSize)); 
    return 0;
}
