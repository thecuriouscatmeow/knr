//replace tabs newlines for symbols and copy string t to string s
//and the reverse
// refer p1.10.c

#include <stdio.h>

void escape (char s[] , char t[]);
void unescape(char s[] , char t[]);

char s[30];
char t[30];    

int main()
{
    // extern char s[30];
    // extern char t[30];      

    scanf("%s", t) ;
    unescape(s, t);
    printf("\n%s\n", s);
    return 0;    
}

//escape: replace escape for appropiate symbols
void escape (char s[] , char t[])
{
    int i,j;
    // extern char s[30];
    // extern char t[30];  

    for(i=j=0 ; t[i] != '\0' ; i++){
        switch(t[i]) {
            case '\n':
                s[j++] = '\\' ;
                s[j++] = 'n' ;
                break;
            case '\t':
                s[j++] = '\\' ;
                s[j++] = 't' ;
                break ;
            default :
                s[j] = t[i] ;
                break ;
        }
        s[j] = '\0' ;
    }     
}

//unescape : replace symbols for actual
/*
void unescape (char s[] , char t[])
{
    int i,j;
    // extern char s[30];
    // extern char t[30];  

    for(i=j=0 ; t[i] != '\0' ; i++){
        if (t[i] == '\\') {
            switch(t[++i]) {
            case 'n':
                s[j++] = '\n' ;
                break;
            case 't':
                s[j++] = '\t' ;
                break ;
            default :
                s[j++] = '\\' ;
                s[j++] = t[i] ;
                break ;
            }
        }
        else 
            s[j++] = t[i] ;
    }     
    s[j] = '\0' ;
}
*/

//unescape : alternate solution
void unescape (char s[] , char t[])
{
    int i,j;
    // extern char s[30];
    // extern char t[30];  

    for(i=j=0 ; t[i] != '\0' ; i++){
        switch (t[i]) {
        case '\\':
            switch(t[++i]) {
            case 'n':
                s[j++] = '\n' ;
                break;
            case 't':
                s[j++] = '\t' ;
                break ;
            default :
                s[j++] = '\\' ;
                s[j++] = t[i] ;
                break ;
            }
            break;
        default : 
            s[j++] = t[i] ;
        }    
    }     
    s[j] = '\0' ;
}