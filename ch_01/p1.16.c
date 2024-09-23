//Print Longest Line   "BUT" main()_ prints length of arbitarily long lines and as much as possible of the text.

#include<stdio.h>
#define MAXLINE 10

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
        printf("\n\n\n\n %d   %s", max, longest);

    return 0;
}

//ggetline : read a line into s, return length
//Think : Why is \n printed outside the for loop
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

//copy : copy "from" into "to"
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}