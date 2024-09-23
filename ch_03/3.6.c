//itoa: convert integer to string
// reverse from p1.19.c

#include <stdio.h>
#include <ctype.h>


void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n ;
    char s[30];    

    scanf("%d", &n) ;

    itoa(n, s) ;
    printf("\n%s\n", s);
    return 0;    
}

void itoa(int n, char s[]){
    int i, sign ;

    if( (sign = n) < 0)
        n = -n ;
    i=0 ;
    do {
        s[i++] = n % 10 + '0' ;
    } while ((n/=10) > 0) ;
    if(sign < 0)
        s[i++] = '-' ;
    s[i] = '\0' ;
    reverse(s) ;
}

//reverse : copy "from" into "to"
void reverse(char s[])
{
    int i, j;
    int temp;

    for(i=0; s[i]!= '\0' ; i++)
        ;

    for(j = i-1, i=0 ; i<j ; i++, j--)
        temp = s[i] , s[i] = s[j] , s[j] = temp ;

}