#include <stdio.h>

int main(void) {

    int n = 5,
        i = 1,
        fact = 1;
    do {
        fact *= i;
        ++i;  // i++ same as
    }while (i <= n);

    printf("%d factorial is %d\n", n, fact);
    return(0);
}
