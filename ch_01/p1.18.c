//Remove trailing blanks & tabs + delete entirely blank space lines

#include<stdio.h>
#define MAXLINE 100

int ggetline(char s[], int lim);
int rremove(char s[]);

int main()
{
    int len;                //Length of current line
    char line[MAXLINE];     //current line

    while((len = ggetline(line, MAXLINE)) > 0){
        printf("\n\n\n\n %d  \n %s", len, line);
        if((len = rremove(line)) > 0) {
            printf("\n\n\n\n %d  \n %s", len, line);
        }
    }

        
    return 0;
}

//ggetline : read a line into s, return length
int ggetline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for(i = 0 ; (c = getchar()) != EOF && c != '\n' ; ++i)
        if(i < lim-2){
            s[j] = c;
            ++j;
        }
        
    if(c == '\n') {        //Dont know why replacing if(c == '\n') with s[j] = '\n'; is causing issue with code termination
        s[j] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';
    return i;
}

//rremove : remove trailing blanks & tabs
int rremove(char s[])
{
    int i ;
    int temp;

    for(i=0; s[i]!= '\0' ; i++)
        ;

    for(i=i-2 ; s[i] == ' ' || s[i] == '\t' ; i--)
        ;
    if(i>0){
        s[++i] = '\n' ;
        s[++i] = '\0' ;
    }
    
    
    return i;
}