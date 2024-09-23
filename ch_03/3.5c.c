//reverse string s in place

#include <stdio.h>
#include <string.h>

void reverse(char s[]) ;

int main()
{
    char s[30];    

    scanf("%s", s) ;

    reverse(s);
    printf("\n%s\n", s);
    return 0;    
}

void reverse(char s[])
{
    int temp, i, j ;

    for(i=0, j= strlen(s)-1 ; i<j ; i++, j--)
        // temp = s[i] , s[i] = s[j], s[j] = temp ;
        s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j];
}