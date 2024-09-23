/*
//Reduce blanks to single blank
#include <stdio.h>

int main(){

    int c;
    int blank = 0;
    
    while((c = getchar()) != EOF)
        if(blank == 0 & c == ' ') {
            blank = 1;
            putchar(c);
        }
        else if(blank == 1 & c == ' ')
            ;
        else {
            blank = 0;
            putchar(c);
        }    
    return 0;    
}
*/

//Alternate Solution
/*
#include <stdio.h>

# define NONBLANK 'a'

int main(){

    int c;
    int lastc = NONBLANK;
    
    while((c = getchar()) != EOF) {
        if(c != ' ') 
            putchar(c);

        else if(lastc != c)
            putchar(c);

        lastc = c;
    }    
    return 0;    
}
*/

//Alternate Solution
#include <stdio.h>

# define NONBLANK 'a'

int main(){

    int c;
    int lastc = NONBLANK;
    
    while((c = getchar()) != EOF) {
        if(c != ' ' || lastc != ' ') 
            putchar(c);

        lastc = c;
    }    
    return 0;    
}