#include <stdio.h>

int main(void) {

    double num, num1;

    printf("read in num: ");
    scanf("%f", &num);
    printf("read in num1: ");
    scanf("%lf", &num1);
    printf("num is %f\n", num);
    printf("num is %lf\n", num);
    printf("num1 is %f\n", num1);
    printf("num1 is %lf\n", num1);

    return(0);
}
