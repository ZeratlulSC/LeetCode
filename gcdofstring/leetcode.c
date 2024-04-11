#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* gcdOfStrings(char* str1, char* str2) {
    int lens1 = strlen(str1);
    int lens2 = strlen(str2);
    int maxstr = (lens1>lens2)?1:2;
    char *ret = (char*)malloc((lens1>lens2)?lens1:lens2 + 1);
    if (maxstr == 1){
        if (strstr(str1,str2) == NULL){
            ret[0] = '\0';
            return ret;
        }
    }
    else if (maxstr == 2){
        if (strstr(str2, str1) == NULL){
            ret[0] = '\0';
            return ret;
        }
    }
    return ret;
}

int main (){
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    printf("%s\n", strstr(str1, str2));
    printf("%s\n", gcdOfStrings(str1, str2));
    return 0;
}