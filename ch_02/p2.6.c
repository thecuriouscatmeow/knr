//convert n bits of x starting at p to the rightmost n bits of y

#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x, y ; 
    int p, n ;

    scanf("%u %d %d %u", &x, &p, &n, &y);
    printf("\n%u\n", setbits(x, p, n, y));
}



//Bit conversion
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ( ~(~(~0 << n) << (p+1-n)) ) | (((y >> (p+1-n)) & ~( ~0 << n)) << (p+1-n)) ;
}