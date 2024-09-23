//shellsort: sort in increasing order


#include <stdio.h>


void shellsort(int v[], int n);

int main()
{
    int n ;
    scanf("%d", &n) ;
    int v[n] ;  

    for(int i=0 ; i<n ; i++) {
        scanf("%d", &v[i]) ;
    }
    shellsort(v, n) ;

    for(int i=0 ; i<n ; i++) {
        printf("%d ", v[i]) ;
    }
    return 0;    
}

void shellsort(int v[], int n){
    int gap, i , j , temp;

    for(gap = n/2 ; gap >0 ; gap/=2)
        for(i = gap ; i<n ; i++)
            for(j=i-gap ; j>= 0 && v[j]>v[j+gap] ; j-=gap) {
                temp = v[j] ;
                v[j] = v[j+gap] ;
                v[j+gap] = temp ;
            }
}