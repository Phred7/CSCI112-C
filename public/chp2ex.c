/* This program does what?
 */
#include <stdio.h>  // printf and scanf descriptions

#define KMS_PER_MILE 1.609  // conversion constant

int main(int argc, char** argv) {
// int main(void) {

	double miles,
	       kms;

	int m = 3, n = 4, p;

	double a = 2.0;

        int abc = 123;

	p = (double)m/(double)n;
	printf("p is %d\n", p);

	printf("Enter the distance in miles: ");
	scanf("%lf", &miles);

	//convert
	kms = KMS_PER_MILE * miles;

	printf("That equals %.1lf kilometers and add abc %1dxxx\n", kms, abc);
	return(0);
}
