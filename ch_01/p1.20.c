//detab: Replace tabs with proper number of blanks "to next tab stop"

#include <stdio.h>

#define TABINC 4

int main(){
    int c;
    int nb = 0;     //Number of blank necessary
    int pos = 1;    //position of charecter in line

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            nb = TABINC - (pos-1)%TABINC ;
            while(nb>0){
                printf(" ");
                ++pos;
                --nb;
            }
        }     
        else if(c == '\n') {
            pos = 1;
            putchar(c);
        }
        else {
            putchar(c);
            pos++ ;
        }       
    }
    return 0;
}