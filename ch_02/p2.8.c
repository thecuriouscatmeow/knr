//right rotate by n bits of x 
#include<stdio.h>

unsigned rightrot(unsigned x, int n);
int wordlength(void);

int main()
{
    unsigned x ; 
    int n ;
    // int wordlength(void);

    scanf("%u %d", &x, &n);
    // printf("%d\n" ,wordlength());
    printf("\n%u\n", rightrot(x, n));
}


//Right Rotation
/*
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;

    n = n % wordlength() ;
    while(n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1) ;
        x = x >> 1 ;
        x = x | rbit ;
    }

    return x ;
}
*/

//Alternate Solution
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void) ;
    int rbits ;

    if( (n % wordlength()) > 0 ) {
        rbits = x & ~(~0 << n) ;
        rbits <<= (wordlength() - n);

        x >>= n;
        x |= rbits ;
    }
    return x;
}


//computes wordlength of machine... remember wordlength is machine dependent
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0 ;

    for(i=0 ; (v >>= 1) > 0 ; i++)
        ;
    return i;
}
