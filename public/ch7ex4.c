#include <stdio.h>

int addArray(int a[], int n) {

    int i, sum = 0;
    for (i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}
        
int main(void) {
    int a[6], n, i;
    printf("Number of items to sum: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int sum = addArray(a, n);
    printf("sum is %d\n", sum);
    return(0);
}
