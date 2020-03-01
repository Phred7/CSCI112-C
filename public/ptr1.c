#include <stdio.h>

int main(void) {
    int n, *p;

    n = 151;

    p = &n;

    printf("n is %d, p is %p\n", n, p);

    printf("the value p is pointing to is %d\n", *p);

    printf("n's address is %p\n", &n);

    printf("p's address is %p\n", &p);

    printf("p+4 address is %p, value is %d\n", p+4, *(p+4));
    return(0);
}
