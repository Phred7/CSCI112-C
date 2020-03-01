#include <stdio.h>

int addArray(int a[], int n) {

    int i, sum = 0;
    for (i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}
        
int main(void) {
    int n = 5;
    int a[n], i;
    for (i = 0; i < n; ++i) {
        a[i] = i+1;
    }

    int sum = addArray(a, n);
    printf("sum is %d\n", sum);
    return(0);
}
