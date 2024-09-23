//loop equivalent without && or ||
// for(i = 0 ; i < lim-1 && (c = getchar()) != EOF && c != '\n' ; ++i)

#include <stdio.h>

int main()
{
    enum loop{ NO, YES};
    enum loop okloop = YES;

    int i = 0;
    int c;
    int lim = 30;
    char s[lim];
    while (okloop == YES)
    {
        if(i >= lim-1)
            okloop = NO;
        else if((c = getchar()) != EOF)
            okloop = NO;
        else if(c == '\n')
            okloop = NO;
        else 
            s[i++] = c;  
    }
    return 0;
}