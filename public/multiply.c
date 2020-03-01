#include <stdio.h>

int multiply(int m, int n) {
    int answer;
    printf("in multiply, m is %d, n is %d\n", m, n);
    if (n == 1) {
        answer = m;
    }
    else {
        answer = m + multiply(m, n-1);
    }
    return answer;
}

int main() {
    printf("The answer of 6 x 4 is %d\n", multiply(6,4));
    return(0);
}
