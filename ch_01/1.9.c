//Print Longest Line

#include<stdio.h>
#define MAXLINE 1000

int ggetline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;                //Length of current line
    int max;                //Length of longest line
    char line[MAXLINE];     //current line
    char longest[MAXLINE];  //longest line

    max = 0;
    while((len = ggetline(line, MAXLINE)) > 0)
        if(len > max) {
            max = len;
            copy(longest, line);
        }

    if(max >0)          //If there exists a line
        printf("\n\n\n\n%s", longest);

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

//copy : copy "from" into "to"
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}