//itoa: convert integer to string
//3.6.c modified to handle boundary case of largest negative number in 2's complement -(2^(wordsize-1))
// reverse from p1.19.c

#include <stdio.h>
#include <ctype.h>


void itoa(int n, char s[]);
void reverse(char s[]);

#define abs(x) (x<0 ? -x : x)

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

    sign = n ;
    i=0 ;

    do {
        s[i++] = abs(n % 10) + '0' ;
    } while ((n/=10) != 0) ;
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