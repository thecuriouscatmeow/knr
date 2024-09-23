//  print  Farenheit-Celsius conversion table for farh = 0, 20, ..., 300 using function

#include <stdio.h>

float fToC(int farh);
int main( ) 
{
    int farh ;
    int lower, upper, step ;

    lower = 0 ;
    upper = 300 ;
    step = 20 ;

    farh = lower;
    while(farh <= upper)
    {
        printf("%5d %5.1f\n", farh , fToC(farh));
        farh += step ;
    }
}

float fToC(int farh) 
{
   int celsius ;
   celsius = (farh - 32) /  9 ;
   return celsius;
}