//replace tabs blanks and blackslash for symbols
// refer p3.2.c

#include <stdio.h>

int main(){

    int c;

    while((c = getchar()) != EOF){
        if(c == ' ')
            printf("\\b");
        else if(c == '\t')
            printf("\\t");
        else if(c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }           
    return 0;    
}
