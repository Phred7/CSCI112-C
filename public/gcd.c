#include <stdio.h>

int gcd(int m, int n) {
    int answer;

    if (n == 0) {
        answer = m;
    }
    else {
        answer = gcd(n, m%n);
    }
    return answer;
}

int main(void) {
    int num1, num2;
    printf("Enter 2 positive ints: ");
    scanf("%d %d", &num1, &num2);

    printf("Their Greatest Common Denominator is %d\n", gcd(num1, num2));
    return(0);
}
