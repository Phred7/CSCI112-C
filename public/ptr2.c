#include <stdio.h>

int main(void) {

    int m = 10,
        n = 5;

    int *mp = NULL, 
        *np;

    printf("mp is %d\n", *mp);
    mp = &m;
    np = &n;

    *mp = *mp + *np;
    // same as m = m + n;
    *np = *mp - *np;
    // same as n = m - n;

    printf("%d %d\n%d %d\n", m, *mp, n, *np);
    printf("%p %p\n", mp, &m);
    printf("%p %p\n", np, &n);
    return(0);

}
