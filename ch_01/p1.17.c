//Print Lines longer than 80 charecters

#include<stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int ggetline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;                //Length of current line
    char line[MAXLINE];     //current line

    while((len = ggetline(line, MAXLINE)) > 0)
        if(len > LONGLINE) {
            printf("\nOutput Line :\n%s\n\n", line);
        }
    return 0;
}

//ggetline : read a line into s, return length
//Think : Why is \n printed outside the for loop
int ggetline(char s[], int lim)
{
    int c, i;

    for(i = 0 ; i < lim-1 && (c = getchar()) != EOF && c != '\n' ; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

