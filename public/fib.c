#include <stdio.h>

int fib(int n) {
    printf("in function with n = %d\n", n);
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    printf("answer for the 6th element in the fibonacci seq is %d\n", 
                  fib(10));
    return(0);
}
 
