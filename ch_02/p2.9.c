//count 1 bits in x
#include<stdio.h>

int bitcount(unsigned x);


int main()
{
    unsigned x ; 

    scanf("%u", &x);
    printf("\n%u\n", bitcount(x));
}


//counting bits
/*
int bitcount(unsigned x)
{
    int b;

    for(b=0 ; x!=0 ; x>>=1)
        if(x & 01)
            b++ ;

    return b ;
}
*/

//Alternate Solution
// in two's complement x &= x-1 removes rightmost 1 in x
int bitcount(unsigned x)
{
    int b ;

    for(b=0 ; x!=0 ; x &= x-1)
        ++b ;

    return b;
}

