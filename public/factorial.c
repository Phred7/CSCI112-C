#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {

    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main(int argc, char** argv) {
    int fact, num;

    num = atoi(argv[1]);

    fact = factorial(num);

    printf("factorial of %d is %d\n", num, fact);

    return(0);

}
    
