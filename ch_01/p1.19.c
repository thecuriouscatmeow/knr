//Reverse input string one line at a time

#include<stdio.h>
#define MAXLINE 100

int ggetline(char s[], int lim);
void reverse(char s[]);

int main()
{
    int len;                //Length of current line
    char line[MAXLINE];     //current line

    while((len = ggetline(line, MAXLINE)) > 0)
        if(len > 0) {
            reverse(line);
            printf("\n\n\n\n %d \n%s", len, line);
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

//reverse : copy "from" into "to"
void reverse(char s[])
{
    int i, j;
    int temp;

    for(i=0; s[i]!= '\0' ; i++)
        ;

    for(j = i-2, i=0 ; i<j ; i++, j--){
        temp = s[i] ;
        s[i] = s[j] ;
        s[j] = temp ;
    }
}