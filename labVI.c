#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* This f(x) takes in a string and the starting number (should be 0).
* Then it recursively prints One Element permutations for a 4 character string
*/
void sub1(char str[], int n){
	if(n == 0){
		printf("OneElemSubs\n(\"%s\")\n{%c}\n", str, str[n]);
		sub1(str, n+1);
	}else if(n <= 3){
		printf("{%c}\n", str[n]);
		sub1(str, n+1);
	}else{
		printf("\n");
	}
}

/**
* This f(x) takes in a string and two starting numbers (should both be 0).
* Then it recursively prints Two Element permutations for a 4 character string updating the intial conditions as it runs
*/
void sub2(char str[], int n, int m){
	if(n == 0 && m == 0){
		m++;
		printf("TwoElemSubs\n(\"%s\")\n{%c, %c}\n", str, str[n], str[m]);
		m++;
		sub2(str, n, m);
	}else if(m == 3){
		printf("{%c, %c}\n", str[n], str[m]);
		n++;
		m = n+1;
		sub2(str, n, m); 
	}else if(m > 3){
		printf("\n");
	}else{
		printf("{%c, %c}\n", str[n], str[m]);
		m++;
		sub2(str, n, m);
	}
}

/**
* This f(x) takes in a string and three starting numbers (should all be 0).
* Then it recursively prints Three Element permutations for a 4 character string updating the intial conditions as it runs
*/
void sub3(char str[], int n, int m, int p){
	if(n == 0 && m == 0){
		m++;
		p+=2;
		printf("ThreeElemSubs\n(\"%s\")\n{%c, %c, %c}\n", str, str[n], str[m], str[p]);
		p++;
		sub3(str, n, m, p);
	}else if(p == 3 && m == 2){
		printf("{%c, %c, %c}\n", str[n], str[m], str[p]);
		n++;
		m = n + 1;
		p = n + 2;
		sub3(str, n, m, p);
	}else if(p == 3){
		printf("{%c, %c, %c}\n", str[n], str[m], str[p]);
		m++;
		p = m + 1;
		sub3(str, n, m, p);
	}else if(p > 3){
		printf("\n");
	}
}

/**
* Main: Calls each respective f(x) and passes 4 char string from the command line as well as respective initial conditions
* Calls and error and ends the program if:
* no string is passed from the command line
* string is not 4 char long (shorter or longer)
*/
int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Error: Missing arg\n");
		return 22;
	}else if(strlen(argv[1]) == 4){
		sub1(argv[1], 0);
		sub2(argv[1], 0, 0);
		sub3(argv[1], 0, 0, 0);
		return 0;
	}else{
		printf("Error: String length\n");
		return 22;
	}
}