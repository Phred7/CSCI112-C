#include <stdio.h>
#include <stdlib.h>

int main(void){

	char odomIstr[100];
	char odomFstr[100];

	double odomInit;
	double odomFinl;
	double distance;
	double reimb;
	double reimbParam;

	reimbParam = 0.35;

	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
	printf("Enter beginning odometer reading=>");
	fgets(odomIstr, sizeof(odomIstr), stdin);
	odomInit = atof(odomIstr);

	printf("Enter ending odometer reading=>");
	fgets(odomFstr, sizeof(odomFstr), stdin);
	odomFinl = atof(odomFstr);

	distance = odomFinl - odomInit;
	reimb = distance * reimbParam;

	printf("You traveled %2.1f miles.\t", distance);
	printf("At $%2.2f per mile,\n", reimbParam);
	printf("your reimbursment is $%2.2f.\n", reimb); 

	return 0;
}
