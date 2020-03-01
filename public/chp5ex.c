#include <stdio.h>

int main(void) {

    int n = 5,
        i = 1,
        fact = 1;

    while (i <= n) {
        fact *= i;
        ++i;  // i++ same as
    }
    printf("%d factorial is %d\n", n, fact);
    return(0);
}
