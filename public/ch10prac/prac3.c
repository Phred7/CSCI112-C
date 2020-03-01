#include <stdio.h>

int gcd(int m, int n) {
    int ans;

    if (m%n == 0) {
	ans = n;
    }
    else {
        ans = gcd (n, m%n);
    }
    return ans;
}

double convert(int *n, int *d) {
    int div = gcd(*d, *n);
    *n /= div;
    *d /= div;
    return (double)(*n)/(double)(*d);
}

int main() {
    int n, d;
    double value;
 
    printf("Enter numberator and denominator: ");
    scanf("%d %d", &n, &d); 

    value = convert(&n, &d);
    printf("value is %lf\n", value);
    printf("fraction is now %d/%d\n", n, d);

    return(0);
}

