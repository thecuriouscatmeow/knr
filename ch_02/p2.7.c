//invert n bits of x starting at p 

#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned x ; 
    int p, n ;

    scanf("%u %d %d", &x, &p, &n);
    printf("\n%u\n", setbits(x, p, n));
}



//Bit conversion
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n))   ;
}