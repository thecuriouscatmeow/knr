//lower : convert uppercase letter to lower case

#include<stdio.h>

enum boolean{NO, YES};
int lower(char c);

int main()
{
    char c = getchar() ;
    putchar(lower(c)) ;
    putchar('\n');
}



//function to convert
int lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c ;
}