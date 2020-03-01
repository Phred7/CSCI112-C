#include <stdio.h>

int main(void) {

    int n = 5,
        i,
        fact;

    for (i = n, fact = 1; i > 0; --i) {
        fact *= i;
    }

    // equivalent loop for factorial
    i = n;
    while (1) {
        if (i <= 0) {
            break;
        }
        fact *= i;
        --i;
    }

    printf("%d factorial is %d\n", n, fact);
    return(0);
}
