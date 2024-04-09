#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2){
    int ret_length = strlen(word1) + strlen(word2) + 1;
    char *ret = (char*)malloc(ret_length);
    int min_len = strlen(word1);
    int min_word = 1;
    if (min_len > strlen(word2)) {
        min_len = strlen(word2);
        min_word = 2;
    }
    else if (strlen(word1) == strlen(word2)) min_word = 0;
    int ret_iter = 0;
    for (int i = 0; i < min_len; i++){
        ret[ret_iter++] = word1[i];
        ret[ret_iter++] = word2[i];
    }
    if (min_word == 0) {
        ret[ret_length-1] = '\0';
        return ret;
    }
    ret[min_len*2] = '\0';
    if (min_word == 1) strcat(ret, (word2+min_len));
    else if (min_word == 2) strcat(ret, (word1+min_len));
    return ret;
}

int main (){
    char note[] = "abc";
    char mag[] = "pqr";
    printf("%s\n", mergeAlternately(note, mag));
    return 0;
}