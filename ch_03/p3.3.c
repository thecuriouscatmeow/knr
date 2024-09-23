//expand shorthand notations from s1 in s2 like a-z -> abcd....xyz
//handle cases like a-b-c, a-z0-9, -a-z

#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[30] ;
    char s2[300] ;
    scanf("%s", s1) ;

    expand(s1, s2) ;
    printf("\n%s\n", s2) ;
    return 0 ;
}

void expand(char s1[], char s2[])
{
    char c ;
    int i, j ;

    i=j=0 ;
    while( (c = s1[i++]) != '\0') {
        if(s1[i] == '-' && s1[i+1] >= c) {
            i++ ;
            while(c < s1[i])
                s2[j++] = c++ ;
        }
        else
            s2[j++] = c ;
    }
    s2[j++] = '\0' ;
}