#include <stdio.h>
#include <math.h>

void calculatePayments(double principal, double aRate, double numPayments){

	int i;
	double finalPayment, payment, mRate, interest;
	
	mRate = (aRate / 12); //monthly intrest rate = annual interest rate divided by months per year
	
	finalPayment = (mRate * principal) / (1 - (pow(1 + mRate, -numPayments))); //calculates the monthly payment
	
	printf("Principal: $%1.2lf\nAnnual Interest: %1.1lf percent\nTerm %1.0lf months\n\n", principal, aRate*100, numPayments);
	printf("Payment               Interest      Principal      Balance\n");
	printf("-------------------------------------------------------------\n");
	
	for(i = 1; i<=numPayments; i++){
		interest = mRate * principal; //calculates how much to subtract from the payment
		payment = finalPayment - interest; //calculates one months payment
		principal -= payment; //updates the principal balance
		
		printf("%3.1d %23.2lf %15.2lf %13.2lf\n", i, interest, payment, principal);
	}	
	
	printf("Final Payment %1.2lf\n", finalPayment);
	printf("-------------------------------------------------------------\n");
}

int main(int argc, char* argv[]){
	
	double principal, numPayments, rate; 
	//initial amount, how many payments to compute, intrest rate
	
	/**
	*gets inputs from the command line and converts them to doubles
	*/
	sscanf(argv[1], "%lf", &principal);
	sscanf(argv[2], "%lf", &rate);
	sscanf(argv[3], "%lf", &numPayments);
	
	rate = rate / 100; //converts the entered rate to decimal form
	
	//printf("%1.2lf | %1.2lf | %1.2lf\n", principal, rate, numPayments); //used for debugging

	calculatePayments(principal, rate, numPayments); //calls the function to calculate and print statements
	
	return 0;
}