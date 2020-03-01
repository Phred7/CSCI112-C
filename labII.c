#include <stdio.h>
#include <math.h>

void bmi(double weight, double height){ //method to calculate BMI and print result

	double mBMI;
	double underweight = 18.5, normal = 24.9, overweight = 29.9;
	
	mBMI = (703 * weight)/(pow(height, 2.0)); //bmi calculation
	
	printf("Your height is: %1.2lf. Your weight is: %1.2lf. ", height, weight); //prints entered height and weight
	
	if(mBMI <= underweight){ //determines weight status characterization based on the entered doubles and calculation
		printf("Your BMI is: %1.2lf: Underweight\n", mBMI);
	}else if(mBMI <= normal && mBMI > underweight){
		printf("Your BMI is: %1.2lf: Normal\n", mBMI);
	}else if(mBMI <= overweight && mBMI > normal){
		printf("Your BMI is: %1.2lf: Overweight\n", mBMI);
	}else if(mBMI > overweight){
		printf("Your BMI is: %1.2lf: Obese\n", mBMI);
	}
}

int main(int argc, char** argv){

	double weight_lbs, height_in; //user inputs
	int valid = 0; //used as a flag to check input validity
	
	while(valid == 0){ //ensures that the input is valid (weight)
		printf("Enter weight in pounds: ");
		scanf("%lf", &weight_lbs);
		if(weight_lbs <= 0){
			valid = 0;
			printf("Error. Please enter a valid number! ");
		}else{
			valid = 1;
		}
	}
	
	valid = 0; //resets flag
	
	while(valid == 0){ //ensures that the user input is valid before moving on (height)
		printf("Enter height in inches: ");
		scanf("%lf", &height_in);
		if(height_in <= 0){
			valid = 0;
			printf("Error. Please enter a valid number");
		}else{
			valid = 1;
		}
	}
	
	valid = 0; //resets flag

	bmi(weight_lbs, height_in); //function call (bmi) and passes variables for calculation

	return 0;
} 
