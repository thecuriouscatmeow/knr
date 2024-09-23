// Count digits, white spaces and others
//refer 3.4.c

#include <stdio.h>

int main(){
    int c, nwhite, nother;
    int ndigits[10];
    nwhite = nother = 0;
    for(int i = 0; i < 10; i++)
        ndigits[i] = 0;

    while((c = getchar()) != EOF) {
        if(c >= '0' && c <= '9')
            ++ndigits[c-'0'] ;
        if(c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
        }

        printf("digits : ");

        for(int i = 0; i < 10; i++)
            printf("%d ", ndigits[i]);

        printf("white space : %d, other : %d\n", nwhite, nother);
        return 0;
    }

    
