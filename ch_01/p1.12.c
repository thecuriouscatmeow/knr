//Print input one word per line

#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
    int c, state;
    state = OUT;

    while((c = getchar()) != EOF) {

        if(c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            putchar('\n');
        }
            
        else if(state == OUT) {
            state = IN;
            putchar(c);
        }
        else
            putchar(c);
    }
    
    return 0;
}