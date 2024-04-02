#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int hash_note [26] = {0};
    int hash_magz [26] = {0};
    for (int i = 0; i < strlen(ransomNote); i++){
        hash_note[ransomNote[i]-'a']++;
    }
    for (int i = 0; i < strlen(magazine); i++){
        hash_magz[magazine[i]-'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (hash_magz[i] < hash_note[i]) return false;
    }
    return true;
}

int main (){
    char note[] = "aab";
    char mag[] = "aaaaaa";
    printf("%d\n", canConstruct(note, mag));
    return 0;
}