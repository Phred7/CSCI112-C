#include <stdio.h>
#include "fraction.h"

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

void convert(fraction_t* frac) {

    int div = gcd(frac->denom, frac->numer);
    frac->numer /= div;
    frac->denom /= div;
    frac->value = (double)frac->numer/(double)frac->denom;
    return;
}

int main() {
    fraction_t frac;

    printf("Enter numerator and denominator: ");
    scanf("%d %d", &frac.numer, &frac.denom);
 
    convert(&frac);
    printf("value is %lf\n", frac.value);
    printf("fraction is now %d/%d\n", frac.numer, frac.denom);

    return(0);
}

