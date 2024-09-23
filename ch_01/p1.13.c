// Horizontal Histogram of lengths of word in input
/*

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXHIST 15
#define MAXWORD 11

int main(){
    int c, state, len, nword;

    int wordlen[MAXWORD];
    for(int i = 0; i < MAXWORD; i++)
        wordlen[i] = 0;

    state = OUT;
    nword = 0;
    len = 0;
    int overflow = 0;
    while((c = getchar()) != EOF) {

        if(c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            ++nword;
            if(len >0 && len <= MAXWORD)
                ++wordlen[len-1];
            else 
                ++overflow;
            len = 0;

        }    
        else if(state == OUT) {
            state = IN;
            ++len;
        }
        else 
            ++len;     
    }


    
    //Print Histogram
    for(int i = 0; i < MAXWORD; i++) {
        printf("%5d : ", (i+1));
        for(int j = 0; j < wordlen[i]; j++)
            printf("#");
        printf("\n");
    }
    printf("\nHistogram of lengths of words in input\n");
    printf("Search Space : %d words \n ", nword);
    printf("Overflow : %d words \n ", overflow);

    return 0;
}

*/

// Vertical Histogram of lengths of word in input

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXHIST 15
#define MAXWORD 11

int main(){
    int c, state, len, nword;
    int maxvalue;           //Maximum value of wordlen[i];
    int normalconst;        //Normalization Constant
    int overflow;           //Number of overflow words
    int wordlen[MAXWORD];   //Word length counter 

    //Initialize variables
    for(int i = 0; i < MAXWORD; i++)
        wordlen[i] = 0;
    state = OUT;
    nword = 0;
    len = 0;
    overflow = 0;

    //Counting function
    while((c = getchar()) != EOF) {

        if(c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            ++nword;
            if(len >0 && len <= MAXWORD)
                ++wordlen[len-1];
            else 
                ++overflow;
            len = 0;
        }    
        else if(state == OUT) {
            state = IN;
            len = 1;    //New Word
        }
        else 
            ++len;     //Inside Word
    }


    //Normalization Constant Calculation
    maxvalue = 0;
    for(int i = 0; i < MAXWORD; i++)
        if(wordlen[i] > maxvalue)
            maxvalue = wordlen[i];
    normalconst = MAXHIST/maxvalue ;

    //Histogram Print
    for(int i = MAXHIST; i >0; i--){
        for(int j = 0; j < MAXWORD; j++)
            if(wordlen[j] * normalconst >= i)  //
                printf("  *  ");
            else 
                printf("     ");
        printf("\n");
    }  

    //Print Legend
    for(int i = 0; i < MAXWORD; i++)
        printf("%5d", (i+1));
    printf("\nHistogram of lengths of words in input\n");
    printf("Search Space : %d words \n ", nword);
    printf("Overflow : %d words \n ", overflow);
}