#include <stdio.h>

int main(void) {

    int n = 5,
        i,
        fact;

    for (i = 1, fact = 1; i <= n; ++i) {
        fact *= i;
    }

    printf("%d factorial is %d\n", n, fact);
    return(0);
}
