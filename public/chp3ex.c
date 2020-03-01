#include <stdio.h>
#include <math.h>

double computeRoot(int, int, int,  char);

double computeRoot(int a, int b, int c, char type) {

	double root, disc;

	// compute discriminant
	disc = pow((double)b, 2.0) -4 * a * c;

	// for + use -b +
	if (type == '+') {
		root = (-b + sqrt(disc)) / (2 * a);
        }
	// for - use -b -
	else {
             root = (-b - sqrt(disc)) / (2 * a);
	}
        return root;
}

int main(void) {

	int a, b, c;
	double root1, root2;

	//read in the variables for the quadratic equation - a, b, c
	printf("Enter the quadratic variables - a, b, c as ints: ");
	scanf("%d %d %d", &a, &b, &c);
        // printf("debug: a %d b %d c %d\n", a, b, c);
		
	// solve the quadratic equation for the roots
        root1 = computeRoot(a, b, c, '+');	
	root2 = computeRoot(a, b, c, '-');

	// print out the result
	printf("The roots for %dx2 + %dx + %d are %.1lf and %.1lf\n",
			a, b, c, root1, root2);

	return(0);
}
