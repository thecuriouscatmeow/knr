//Binary search : 

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    int v[n];
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &v[i] );
    }
    for(int i=0 ; i<n ; i++) {
        printf("%d ", v[i] );
    }
    putchar('\n');

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    printf("\n%d\n", binsearch(x, v, n));
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid ;
    low = 0;
    high = n-1 ;
    while(low <= high) {
        mid = (low + high)/2 ;
        if (x < v[mid])
            high = mid-1 ;
        else if (x > v[mid])
            low = mid+1 ;
        else 
            return mid;
        printf("%d %d %d\n", low, mid, high );
    }
    return -1;
}
