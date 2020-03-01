#include <stdio.h>

int main(void) {
    int x = 1, y = 2;

    int *ip;

    ip = &x;

    printf("x is %d, y is %d, *ip is %d\n", x, y, *ip);

    y = *ip;

    printf("x is %d, y is %d, *ip is %d\n", x, y, *ip);

    x = ip;

    printf("x is %d, y is %d, *ip is %d\n", x, y, *ip);

    *ip = 3;

    printf("x is %d, y is %d, *ip is %d\n", x, y, *ip);

    return(0);
}
