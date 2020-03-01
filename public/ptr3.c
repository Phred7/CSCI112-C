#include <stdio.h>

void changenum(int* p, int* q) {
    *p += 5;
    *q -= 2;
    return;
}

int main(void) {

    int m = 10,
        n = 5;

    changenum(&m, &n);

    printf("%d %d\n", m,  n);
    return(0);

}
