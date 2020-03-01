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
    int a[5] = {1,2,3,4,5};

    int sum = addArray(a, n);
    printf("sum is %d\n", sum);
    return(0);
}
