#include <stdio.h>

int main(void) {
    int m = 10,
        n = 10,
        p;

    p = ++m + 5;
    printf("p is %d, m is %d\n", p, m);

    p = n++ + 5;
    printf("p is %d, n is %d\n", p, n);
    return 0;
}
 
