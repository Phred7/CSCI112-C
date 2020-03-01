#include <stdio.h>
#define N 5

int addArray(int a[], int n) {

    int i, sum = 0;
    for (i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}
        
int main(void) {
    int a[N] = {1,2,3,4,5};

    int sum = addArray(a, N);
    printf("sum is %d\n", sum);
    return(0);
}
