// return location of first location of s1 of tie with s2
// the alternate version of p2.4 will work better here

// remove all instances of s2 that occur in s1

//hhtoi : convert hexadecimal to decimal my version

#include<stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("\n%d\n", any(s1, s2));
}



//Alternate Solution
//running s1 and writing only if not present in s2
int any(char s1[], char s2[])
{
    int i, j, k;

    for(i=k=0 ; s1[i] != '\0' ; i++) 
        for(j=0 ; s2[j] != '\0' ; j++)
            if(s2[j] == s1[i])
                return i;
    return -1;
}