#include <stdio.h>
#include <string.h>
#include "header.h"

/**
* Prints the options to the user
* Grabs the int input from the user and returns
* Sets user input to 5 if error
*/
int printOptions(){
	int answer = 0;
	Bool valid = false;
	
	while(!valid){
		printf("\nOptions:\n1. Print all Classes\n2. Print classes by given day combo\n3. Print classes by time and day\n4. Print classes by given level\n5. Quit\n");
		scanf("%d", &answer);
		if(answer < 1 || answer >= 6){
			valid = true;
			answer = 5;
			printf("User Input Error:\n");
		}else{
			valid = true;
		}
	}
	return answer;
}

/**
* Prints the options to the user
* Grabs the int input from the user and returns
* Sets user input to 5 if error
*/
int printOptionsDay(){
	int answer = 0;
	
	printf("\nChoose your day combo:\n1. MWF\n2. TR\n3. To cancel\n");
	scanf("%d", &answer);
	if(answer < 1 || answer > 2){
		answer = 5;
	}
	return answer;
}

/**
* Prints the options to the user
* Grabs the int input from the user and returns
* Sets user input to 5 if error
*/
int printOptionsYear(){
	int answer = 0;
	
	printf("\nChoose your day combo:\n1. Freshman\n2. Sophmore\n3. Junior\n4. Senior\n5. To cancel\n");
	scanf("%d", &answer);
	if(answer < 1 || answer > 5){
		answer = 5;
	}
	return answer;
}

/**
* Prints one full class properly formatted
*/
void printClass(FILE *out, classes_t cls[], int index){
	fprintf(out, "%-47s", cls[index].name);
	fprintf(out, "%s ", cls[index].number);
	//printf("%-47s", cls[index].name);
	//printf("%s ", cls[index].number);
	if(cls[index].year == 1){
		fprintf(out, "Freshman ");
		//printf("Freshman ");
	} else if(cls[index].year == 2){
		fprintf(out, "Sophmore ");
		//printf("Sophmore ");
	} else if(cls[index].year == 3){
		fprintf(out, "Junior\t");
		//printf("Junior\t");
	} else{
		fprintf(out, "Senior\t");
		//printf("Senior\t");
	}
	fprintf(out, "%s ", cls[index].days);
	fprintf(out, "%s\n", cls[index].time);
	//printf("%s ", cls[index].days);
	//printf("%s\n", cls[index].time);
}

/**
* Prints dthe correct header for user option 2: "Print classes by given day"
*/
void printDayType(FILE *out, char* type){
	char mwf[] = "MWF";
	
	if(strcmp(type, mwf) == 0){
		fprintf(out, "List of classes for MWF:\n");
		//printf("List of classes for MWF:\n");
	}else{
		fprintf(out, "List of classes for TR:\n");
		//printf("List of classes for TR:\n");
		
	}
}

/**
* Prints header for user option 1. "Print all Classes"
*/
void printNumber(FILE *out){
	fprintf(out, "List of all classes:\n");
	//printf("List of all classes:\n");
	return;
}

/**
* Prints header for user option 4. "Print classes by given level"
*/
void printLevel(FILE *out, int year){
	fprintf(out, "Classes for ");
	printf("Classes for ");
	if(year == 1){
		fprintf(out, "Freshman:\n");
		//printf("Freshman:\n");
	} else if(year == 2){
		fprintf(out, "Sophmores:\n");
		//printf("Sophmores:\n");
	} else if(year == 3){
		fprintf(out, "Juniors:\n");
		//printf("Juniors:\n");
	} else{
		fprintf(out, "Seniors:\n");
		//printf("Seniors:\n");
	}

	return;
}