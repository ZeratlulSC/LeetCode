#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
char* gcdOfStrings(char* str1, char* str2) 
{
    
    int slen1=strlen(str1);
    int slen2=strlen(str2);
    int k = gcd(slen1,slen2);
    for(int i=0;i<k;++i) if(str1[i]!=str2[i]) return "";
    for(int i=0;i<=slen1-k;i+=k)
    {
        for(int j=0;j<k;++j) if(str1[j]!=str1[i+j]) return "";
    }
    for(int i=0;i<=slen2-k;i+=k)
    {
        for(int j=0;j<k;++j) if(str2[j]!=str2[i+j]) return "";
    }
    char* res = (char*)malloc(sizeof(char)*(k+1));
    for(int i=0;i<k;++i) res[i]=str1[i];
    res[k]=0;
    return res;
}

int main (){
    char str1[] = "ABCABC";
    char str2[] = "ABC";
    printf("%s\n", gcdOfStrings(str1, str2));
    return 0;
}