//hhtoi : convert hexadecimal to decimal my version

#include<stdio.h>

enum boolean{NO, YES};
int hhtoi(char s[]);

int main()
{
    char s[100];
    scanf("%s", s);
    printf("%d", hhtoi(s));
}



//function to convert
int hhtoi(char s[])
{
    int hexdigit;
    int i = 0;
    int inhex = YES;
    int n = 0; 

    if( s[i] == '0') {
        ++i;
        if( s[i] == 'x' || s[i] == 'X')
            ++i;
    }

    for( ; inhex == YES ; ++i){
        if(s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0' ;
        else if(s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10 ;
        else if(s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10 ;
        else 
            inhex = NO ;
        if( inhex == YES )
            n = 16 * n + hexdigit ;
    }
    return n;
}