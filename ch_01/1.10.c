//Print Longest Line using "EXTERNAL" variables

#include<stdio.h>
#define MAXLINE 1000

int max;                //Length of longest line
char line[MAXLINE];     //current line
char longest[MAXLINE];  //longest line

int ggetline(void);
void copy(void);

int main()
{
    int len;                //Length of current line
    extern int max;                
    extern char longest[];  
    

    max = 0;
    while((len = ggetline()) > 0)
        if(len > max) {
            max = len;
            copy();
        }

    if(max >0)          //If there exists a line
        printf("\n\n\n\n%s", longest);

    return 0;
}

//ggetline : read a line into s, return length
//Think : Why is \n printed outside the for loop
int ggetline()
{
    int c, i;
    extern char line[];  

    for(i = 0 ; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n' ; ++i)
        line[i] = c;
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

//copy : copy "from" into "to"
void copy()
{
    int i;
    extern char line[], longest[]; 

    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}