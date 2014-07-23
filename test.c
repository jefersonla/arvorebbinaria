#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pot(int x){
    int res;
    for(res = 1; x > 0 ; x--)
        res *= 10;
    return res;
}

void stringParaInt(char *str, int *x){
    int i, n;
    for(i = strlen(str) - 1, n = 0; i >= 2; i--, n++)
        *x += (((int) str[i]) - 48) * pot(n);
}

int main(){    
    int x = 0;
    char s[10];
    scanf(" %[^\n]s", s);
    stringParaInt(s, &x);
    printf(" %d...", x);
    return 0;
}