#include <stdio.h>
#include <math.h>

double computeRoot(int, int, int, char);

double computeRoot(int a, int b, int c, char type){
	double root, disc;
	
	//compute discriminant
	disc = pow((double)b, 2.0) -4*a*c;
	
	//for + use -b +
	if(type == '+'){
		root = (-b + sqrt(disc)) / (2*a);
	} else { //for - use -b -
		root = (-b - sqrt(disc)) / (2*a);
	}
	return root;
}

int main(void){
	
	int a, b, c;
	double root1, root2;
	
	//read in values
	printf("Enter the quadradic variables - a, b, c as ints: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("debug: a %d b %d c %d\n", a, b, c);
	
	//solve quad eq
	root1 = computeRoot(a, b, c, '+');
	root2 = computeRoot(a, b, c, '-');
	
	//print results
	printf("The roots for %dx2 + %dx + %d are %lf and %lf\n", a, b, c, root1, root2);
	
	return 0;
}
