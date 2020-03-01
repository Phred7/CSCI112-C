#include <stdio.h>

int addArray(int a[]) {

    int i, sum = 0;
    for (i = 0; a[i] != -1; ++i) {
        sum += a[i];
    }
    return sum;
}
        
int main(void) {
    int a[6] = {1,2,3,4,5,-1};

    int sum = addArray(a);
    printf("sum is %d\n", sum);
    return(0);
}
