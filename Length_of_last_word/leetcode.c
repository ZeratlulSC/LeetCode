#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    char *token;
    int len_last_w = 0;
    token = strtok(s, " ");
    while (token){
        len_last_w = strlen(token);
        token = strtok(NULL, " ");
    }
    return len_last_w;
}

int main (){
    char s[] = "luffy is still joyboy";
    printf("%d\n", lengthOfLastWord(s));
    return 0;
}