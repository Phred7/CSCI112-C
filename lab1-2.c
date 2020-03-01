#include <stdio.h> //printf and scanf descriptions

#define KMS_PER_MILE 1.609 //conversion constant

int main(int argc, char** argv){

	double miles,
	       kms;

	printf("Enter the distance in miles: ");
	scanf("%lf", &miles);

	//conversion
	kms = KMS_PER_MILE * miles;

	return 0;
}
