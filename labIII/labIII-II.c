#include <stdio.h>
#include <math.h>

void calculatePayments(double principal, double aRate, double numPayments){

	int i = 1;
	double finalPayment, payment, mRate, interest;
	char* perc = "%";
	
	mRate = (aRate/12); //monthly intrest rate = annual interest rate divided by months per year
	
	payment = 0;
	
	finalPayment = (mRate*principal)/(1-(pow(1+mRate, -numPayments)));
	
	printf("Principal\t  $%1.2lf\t Payment\t $%1.2lf\nAnnual interest\t  %1.1lf%s Term\t %10d months\n", principal, finalPayment, aRate*100, perc, (int)numPayments);
	
	for(i = 1; i<=numPayments; i++){
		payment = (mRate*principal)/(1-(pow(1+mRate, -numPayments))); //how much to pay on a given term
		interest = mRate * principal;
		principal -= payment; //update the principal with the amount paid
		printf("%d | Interest: %1.2lf | mRate: %1.5lf | payment: %1.2lf |  bal: %1.2lf | finalPayment: %1.2lf |\n", i, interest, mRate, payment, principal, finalPayment);
	}	
	
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

	calculatePayments(principal, rate, numPayments); //calls the function to calculate and print statements
	
	return 0;
}