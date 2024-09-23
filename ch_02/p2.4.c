// remove all instances of s2 that occur in s1

//hhtoi : convert hexadecimal to decimal my version

#include<stdio.h>

char * ssqueeze(char s1[], char s2[]);

int main()
{
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("\n%s\n", ssqueeze(s1, s2));
}



//function to squeeze out elements
//running s2 and deleting each charecter in s1
/*
char * ssqueeze(char s1[], char s2[])
{
    int i, j, k;

    for(k=0 ; s2[k] != '\0' ; k++) {
        for(i=j=0 ; s1[i] != '\0' ; i++)
            if(s1[i] != s2[k])
                s1[j++] = s1[i];
    }
    s1[j] = '\0' ;

    return s1;
} */


//Alternate Solution
//running s1 and writing only if not present in s2
char * ssqueeze(char s1[], char s2[])
{
    int i, j, k;

    for(i=k=0 ; s1[i] != '\0' ; i++) {
        for(j=0 ; s2[j] != '\0' && s2[j] != s1[i] ; j++)
            ;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0' ;

    return s1;
}