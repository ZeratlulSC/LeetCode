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
            printf("nums[%d]=%d nums[%d]=%d\n", i, nums[i], j, nums[j]);
        }
        if (i + nums[i] >= numsSize-1) return true;
        if (advanced == 0) return false;
        advanced = 0;
    }
    return false;
}

int main (){
    int nums[] = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n",canJump(nums, numsSize)); 
    return 0;
}
