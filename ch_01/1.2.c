#include <stdio.h>

/*  print  Farenheit-Celsius table for farh = 0, 20, ..., 300 */

main( ) 
{
        int farh, celsius ;
        int lower, upper, step ;
        printf("hello world\n");

        lower = 0 ;
        upper = 300 ;
        step = 20 ;

        farh = lower;
        while(farh <= upper)
        {
                celsius = (farh - 32) /  9 ;
                printf("%d\t%d\n", farh , celsius);
                farh += step ;
        }
}