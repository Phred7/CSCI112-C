#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int len(int num); //f(x) declaration
void printAstrix(int num); //f(x) declaration
	
char* fact_calc(int n){
	int i, digits, stringLen, fact = 1;
	
	for(i = 0; i < n; i++){ //calculates the factorial
		fact = fact * (i+1);
	}
	
	digits = len(fact); //calculates the length of the factorial ie. 24, 720 would be 2, 3 respectively
	stringLen = 13 + (4*(n-1)) + digits; // 13 + 4(n-l) + len(n!) = len of string
	
	//char* factorial = (char*)malloc(sizeof(char) * (stringLen)); //creates a string with the proper size this will be the full string
	char* total = (char*)malloc(sizeof(char) * (stringLen)); //creates a string with the proper size to be used for the "1 x 2 x 3..." part of the string and concatonated to factorial
	char* end = (char*)malloc(sizeof(char) * (stringLen)); //creastes a string with the proper size to hold the total of the factorial ie. "= 720 *\n"

	if(n == 0){
		strcat(factorial, "* 0! = 1 *\n");
	}else{
		sprintf(factorial, "* %d! =", n); //adds the first part to the string factorial ie. "* 6! ="	
		sprintf(end, "= %d *\n", fact); //adds the total to the string end ie. "= 720 *\n"
		for(i = 0; i < n; i++){ //adds each multiplier to the string factorial
			sprintf(total, " %d ", i+1);
			strcat(factorial, total);
			if(i + 1 < n){ //adds each x to the string factorial (the last multiplier does not need an x after it)
				sprintf(total, "x");
				strcat(factorial, total);
			}
		}
		strcat(factorial, end); //adds the string end to the stirng factorial
	}
	return factorial;
}

int numAstrix(int n){
	int i, fact, digits, astrixLen;
	for(i = 0; i < n; i++){ //calculates the factorial
		fact = fact * (i+1);
	}
	
	digits = len(fact);
	
	astrixLen = 15 + (4*(n-1)) + digits; // 15 + 4(n-1) + len(n!) = num of astrix
	return astrixLen;
}

int len(int num){ //this f(x) calculates the number of digits for any interger
	int digits = 0;
	
	while(num != 0){
		num = num/10;
		digits++;
	}
	return digits;
}

void printAstrix(int num){ //this f(x) prints a given integer of astrixs
	int i;
	for(i = 0; i < num; i++){
		printf("*");
	}
	printf("\n");
}

int main(int argc, char* arcv[]){ //main
	int n, astrixLen,
	boolean = 1; //true
	
	do{
		printf("Enter an integer between 0 and 9 or -1 to quit => ");
		scanf("%d", &n);
		if(n >= 0 && n <= 9){ //bounds for factorial calculation
			//printf("n = %d\n", n);
			astrixLen = numAstrix(n); //this is a f(x) call that calculates the propper number of astrics based on the factorial
			char* factorial = (char*)malloc(sizeof(char) * (astrixLen-2)); //creates a string with the proper size this will be the full string
			printAstrix(astrixLen); //this is a f(x) call to print the propper number of astrics
			factorial = fact_calc(n);
			printf("%s", factorial); //prints the string
			printAstrix(astrixLen); //this is a f(x) call to print the propper number of astrics
		}else if(n == -1){ //to end loop
			break;
		}else{ //invalid entry
			printf("Invalid entry\n"); 
		}
	}while(boolean); //never false (could have just set this to false instead of breaking)
		
	return 0;
}