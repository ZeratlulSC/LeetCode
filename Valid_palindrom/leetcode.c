#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    char *buf = (char*)malloc(strlen(s)+1);
    int buflen = 0;
    for (int i = 0; i < strlen(s); i++){
        if (isalnum(s[i])){
            if (isalpha(s[i])) buf[buflen++] = tolower(s[i]);
            else buf[buflen++] = s[i];
        }
    }
    buf[buflen] = '\0';
    for (int i = 0; i < strlen(buf)/2; i++){
        if (buf[i] != buf[strlen(buf)-i-1]) return false;
    }
    return true;
}

int main (){
    char s[] = " ";
    printf("%d\n",isPalindrome(s));
    return 0;
}