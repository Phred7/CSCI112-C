#include <stdio.h>

int main(int argc, char** argv){

	double x = 2.5, y = 1.75, z, zz, zzz;
	int a = 2, b = 3, c, d;

	c = b/a; //rounded of b/a
	d = b%a; //remainder of b and a 

	z = (double)b/(double)a; //returns b/a in double format (with dec.)
	zz = x/b;
	zzz = y*b;

	printf("c: %2d, d: %2d, z: %2f, zz: %4f, zzz: %4f. ", c, d, z, zz, zzz );



	return 0;
}
