

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *ret = malloc((digitsSize)*sizeof(int));
    int all_nine = 1;
    int over = 1;
    for (int i = 0; i < digitsSize; i++){
        if (digits[i] != 9) {
            all_nine = 0;
            i = digitsSize;
        }
    }
    printf("nines - %d\n", all_nine);
    if (all_nine){
        int *ret2 = malloc((digitsSize+1)*sizeof(int));
        if (digits[0] + 1 == 10) ret2[0] = 1;
        else ret2[0] = digits[0] + 1;
        for (int i = 1; i < digitsSize+1; i++) ret2[i] = 0;
        *returnSize = digitsSize + 1;
        return ret2;
    }
    for (int i = digitsSize - 1; i > -1; i--){
        if (digits[i] + over == 10){
            over = 1;
            ret[i] = 0;
        }
        else {
            if (i == digitsSize - 1) ret[i] = digits[i] + (over--);
            else {
                ret[i] = digits[i]+over;
                over = 0;
            }
        }
    }
    *returnSize = digitsSize;
    for (int i = 0; i < *returnSize; i++) printf("%d ", ret[i]);
    return ret;
}
