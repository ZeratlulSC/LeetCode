#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    int saved_two_elements = 0;
    int nmbr_to_skip = 0;
    int pos_to_save = 0;
    int k = 0;
    for (int i = 0; i < numsSize; i++){
        if (saved_two_elements == 2){
            saved_two_elements = 0;
            while (nums[i] == nmbr_to_skip){
                if (i == numsSize ) break;
                i++;
                if (i == numsSize ) break;
                //printf("число %d, скипаем %d ", nums[i], nmbr_to_skip);
            }
        }
        if (i >= numsSize) break; 
        if (saved_two_elements != 2){
            nums[pos_to_save] = nums[i];
            nmbr_to_skip = nums[i];
            pos_to_save++;
            k++;
            if (i != numsSize - 1){
                if (nums[i+1] == nums[i]) saved_two_elements++;
                else saved_two_elements = 2;
            }
            if (i == numsSize -1 ) saved_two_elements = 2;
        }
    //printf("i = %d, k = %d, saved_two_elements = %d, nmbr_to_skip = %d, pos_to_save = %d\n",i,k,saved_two_elements, nmbr_to_skip, pos_to_save);
    }
    //printf("k = %d\n", k);
    return k;
}

int main (){
    int nums[] = {1,1,1};
    int numsSize = 3;
    removeDuplicates(nums, numsSize); 
    return 0;
}