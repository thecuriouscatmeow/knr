//Program to count frequency of charecters 
//Normalisation not included. Check p1.13.c for normalization 

#include <stdio.h>
#include<ctype.h>


#define MAXHIST 15
#define MAXCHAR 128

int main(){
    int c, len, nc, control;

    int ccounter[MAXCHAR];
    for(int i = 0; i < MAXCHAR; i++)
        ccounter[i] = 0;

    nc = 0;
    len = 0;
    control = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(isprint(c) && c < MAXCHAR)
            ++ccounter[c];
        else
            ++control;          
    }
    
    //Print Histogram 
    for(int i = 32; i < MAXCHAR-1; i++) {
        printf("%5d  - %c - %5d : ", i, i, ccounter[i]);
        for(int j = 0; j < ccounter[i]; j++)
            printf("*");
        printf("\n");
    }
    printf("\nHistogram of lengths of words in input\n");
    printf("Search Space : %d charecters \n ", nc);
    printf("Control Charecters : %d charecters \n ", control);

    return 0;
}