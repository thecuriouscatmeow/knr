//itoa: convert integer to string base b

#include <stdio.h>
#include <ctype.h>


void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int n ;
    char s[30];
    int b ;    

    scanf("%d %d", &n, &b) ;

    itob(n, s, b) ;
    printf("\n%s\n", s);
    return 0;    
}

void itob(int n, char s[], int b){
    int i, j, sign ;

    if( (sign = n) < 0)
        n = -n ;
    i=0 ;
    do {
        j = n%b ;
        s[i++] = j<9 ? j+'0' : j-10+'a' ;
    } while ((n/=b) > 0) ;
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