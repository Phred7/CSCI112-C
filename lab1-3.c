#include <stdio.h> //library
#define KMS_PER_MILE 1.60934  //conversion constant

int main(int argc, char** argv){
	double miles, kms; //distance in miles, equivilant distance in km

	printf("Enter the distance in miles: ");
	scanf("%lf", &miles);

	kms = KMS_PER_MILE * miles;

	printf("That equals %1f kilometers. \n", kms);
	return 0;
}

