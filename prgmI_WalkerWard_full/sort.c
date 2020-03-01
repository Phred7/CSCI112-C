#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/**
* Sorts the classes_t array based on a given user type and prints the propper statements to the output file with help of print f(x)'s
*/
void sort(FILE *out, classes_t cls[], char* type, int length){
	int len = length;
	int i, j, swap = 0;
	char time[] = "time";
	char number[] = "number";
	char year[] = "year";
	char dayMWF[] = "MWF";
	char dayTR[] = "TR";
	classes_t temp;
	
	for(i = 0; i < len; i++){
		for(j = i; j < len; j++){
			if(strcmp(type, number) == 0){ //sort by number
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, time) == 0){ //sort by time of day
				swap = strcmp(cls[i].time, cls[j].time);
			} else if(strcmp(type, dayMWF) == 0){ //sort by MWF (this is deprecated)
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, dayTR) == 0){ //sort by TR (this is deprecated)
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, year) == 0){ //sort by  (this is deprecated)
				swap = strcmp(cls[i].number, cls[j].number);
			}
			if(swap > 0){ //swaps locations if necessary to sort
				temp = cls[i];
				cls[i] = cls[j];
				cls[j] = temp;
			}
		}
	}
	
	/**
	* This set of if statements is used to defferentiate between each given user input
	* They also are used to reprompt the user if neccessary
	* Used to print specific selected classes based on user input type
	*/
	if((strcmp(type, dayMWF) == 0) || (strcmp(type, dayTR) == 0)){
		printDayType(out, type);
		for(i = 0; i < len; i++){
			if((strcmp(type, dayMWF) == 0) && (strcmp(dayMWF, cls[i].days) == 0)){
				printClass(out, cls, i);
			} else if((strcmp(type, dayTR) == 0) && (strcmp(dayTR, cls[i].days) == 0)){
				printClass(out, cls, i);
			}
		}
	}else if(strcmp(type, year) == 0){
		int year = printOptionsYear();
		printLevel(out, year);
		for(i = 0; i < len; i++){
			if(year == cls[i].year){
				printClass(out, cls, i);
			}
		}	
		
	}else if(strcmp(type, time) == 0){
		char *result;
		char dsTempTime[80];
		char tempTime[20];
		char dayUser[20];
		char userTime[20];
		
		printf("Enter days and time (ex: MWF 0900):");
		scanf("%s", dayUser);
		scanf("%s", userTime);

		fprintf(out, "\nTime and Day combo for %s %s:\n", dayUser, userTime);
		printf("\nTime and Day combo for %s %s:\n", dayUser, userTime);
		
		for(i = 0; i < len; i++){
			strcpy(dsTempTime, cls[i].time);
			result = strtok(dsTempTime, "-");
			strcpy(tempTime, result); 
			if(strcmp(cls[i].days, dayUser) == 0){
				if(strcmp(tempTime, userTime) == 0){
					printClass(out, cls, i);
				}
			}else if(strcmp(cls[i].days, dayUser) == 0){
				//printf("%d: If TR\n", i);
				if(strcmp(tempTime, userTime) == 0){
					//printf("%d: If Time TR\n", i);
					printClass(out, cls, i);
				}
			}	
		}
	}else{ //prints all classes
		for(i = 0; i < len; i++){
			printClass(out, cls, i);
		}
	}
	
	fprintf(out, "\n");
}