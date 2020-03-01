#include <stdio.h>
#include <string.h>
#include "header.h"

//
// reads
//

void parseLine(classes_t cls[], char read[], int i){
	char *result;
	char copyLine();

	result = strtok(read, " ");
	strcpy(cls[i].number, result);
	result = strtok(NULL, "$");
	strcpy(cls[i].name, result);
	result = strtok(NULL, " ");
	strcpy(cls[i].days, result);
	result = strtok(NULL, " ");
	strcpy(cls[i].time, result);
	result = strtok(NULL, " ");
	sscanf(result, "%d", &cls[i].year);
	return;
}

void getClasses(){
	int i = 0;
	int linecount = 0;
	char ch;
	char line[81];
	FILE *inputF;
	
	inputF = fopen("classes.txt", "r");
	
	while ((ch=getc(inputF)) != EOF) { //this is used to calculate the number of lines in the file
		if (ch == '\n') { 
			++linecount; 
		}
	}

	classes_t classArray[linecount]; //constructs array of classes based on numLines in the file
	
	fclose(inputF);
	inputF = fopen("classes.txt", "r"); //file was already run through once so we must reopen it to use it agian
	
	while(fgets(line, 80, inputF) != NULL){
		parseLine(classArray, line, i);
		i++;
	}
	
	fclose(inputF);
	promptUser(classArray, linecount);
	
	return;
}

//
// sorting
//

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
			} else if(strcmp(type, dayMWF) == 0){ //sort by MWF
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, dayTR) == 0){ //sort by TR
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, year) == 0){ //sort by year
				swap = strcmp(cls[i].number, cls[j].number);
				// = (cls[i].year > cls[j].year ? 1 : 0);
			}
			
			if(swap > 0){ //swaps locations if necessary to sort
				temp = cls[i];
				cls[i] = cls[j];
				cls[j] = temp;
			}
		}
	}
	
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
		char *dsTempTime;
		char tempTime[20];
		char dayUser[20];
		char userTime[20];
		
		printf("Enter days and time (ex: MWF 0900):");
		scanf("%s %s", &dayUser, &userTime);
		
		//handle lowercase characters
		
		fprintf(out, "\nTime and Day combo for %s %s:\n", dayUser, userTime);
		printf("\nTime and Day combo for %s, %s:\n", dayUser, userTime);
		
		for(i = 0; i < len; i++){
			stpcpy(dsTempTime, cls[i].time);
			result = strtok(dsTempTime, "-");
			strcpy(tempTime, result); 
			printf("%d: For loop ", i);
			printf("userTime: %s ", userTime);
			printf("tempTime: %s ", tempTime);
			printf("dsTempTime: %s ", dsTempTime);
			printf("dsTime: %s\n", cls[i].time);
			if(strcmp(cls[i].days, dayUser) == 0){
				//printf("%d: If MWF\n", i);
				if(strcmp(tempTime, userTime) == 0){
					//printf("%d: If Time MWF\n", i);
					printClass(out, cls, i);
				}
			}else if(strcmp(cls[i].days, dayUser) == 0){
				//printf("%d: If TR\n", i);
				if(strcmp(tempTime, userTime) == 0){
					//printf("%d: If Time TR\n", i);
					printClass(out, cls, i);
				}
			}else{
				//printf("%d: failed 1st if statement\n", i);
			}
		}
	}else{
		for(i = 0; i < len; i++){
			printClass(out, cls, i);
		}
	}
	
	fprintf(out, "\n");
}

//
// prints
//

int printOptions(){
	int answer = 0;
	Bool valid = false;
	
	while(!valid){
		printf("\nOptions:\n1. Print all Classes\n2. Print classes by given day combo\n3. Print classes by time and day combo\n4. Print classes by given level\n5. Quit\n");
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

int printOptionsDay(){
	int answer = 0;
	
	printf("\nChoose your day combo:\n1. MWF\n2. TR\n3. To cancel\n");
	scanf("%d", &answer);
	if(answer < 1 || answer > 2){
		answer = 5;
	}
	return answer;
}

int printOptionsYear(){
	int answer = 0;
	
	printf("\nChoose your day combo:\n1. Freshman\n2. Sophmore\n3. Junior\n4. Senior\n5. To cancel\n");
	scanf("%d", &answer);
	if(answer < 1 || answer > 5){
		answer = 5;
	}
	return answer;
}

void printClass(FILE *out, classes_t cls[], int index){
	fprintf(out, "%-47s", cls[index].name);
	fprintf(out, "%s ", cls[index].number);
	printf("%-47s", cls[index].name);
	printf("%s ", cls[index].number);
	if(cls[index].year == 1){
		fprintf(out, "Freshman ");
		printf("Freshman ");
	} else if(cls[index].year == 2){
		fprintf(out, "Sophmore ");
		printf("Sophmore ");
	} else if(cls[index].year == 3){
		fprintf(out, "Junior\t");
		printf("Junior\t");
	} else{
		fprintf(out, "Senior\t");
		printf("Senior\t");
	}
	fprintf(out, "%s ", cls[index].days);
	fprintf(out, "%s\n", cls[index].time);
	printf("%s ", cls[index].days);
	printf("%s\n", cls[index].time);
}

void printDayType(FILE *out, char* type){
	char mwf[] = "MWF";
	char tr[] = "TR";
	
	if(strcmp(type, mwf) == 0){
		fprintf(out, "List of classes for MWF combo:\n");
		printf("List of classes for MWF combo:\n");
	}else{
		fprintf(out, "List of classes for TR combo:\n");
		printf("List of classes for TR combo:\n");
		
	}
}

void printNumber(FILE *out){
	fprintf(out, "List of all classes:\n");
	printf("List of all classes:\n");
	return;
}

void printTime(FILE *out){
	//fprintf(out, "Classes Sorted By Time of Day:\n");
	return;
}

void printLevel(FILE *out, int year){
	fprintf(out, "Classes for ");
	printf("Classes for ");
	if(year == 1){
		fprintf(out, "Freshman:\n");
		printf("Freshman:\n");
	} else if(year == 2){
		fprintf(out, "Sophmore:\n");
		printf("Sophmore:\n");
	} else if(year == 3){
		fprintf(out, "Junior:\n");
		printf("Junior:\n");
	} else{
		fprintf(out, "Senior:\n");
		printf("Senior:\n");
	}

	return;
}

void promptUser(classes_t cls[], int length){
	FILE *outputF;
	outputF = fopen("classOut.txt", "w");
	fprintf(outputF, "CSCI Courses Offered\n\n");
	fclose(outputF);
	
	outputF = fopen("classOut.txt", "a");
	
	char time[] = "time";
	char number[] = "number";
	char year[] = "year";
	char dayMWF[] = "MWF";
	char dayTR[] = "TR";
	Bool boolean = true;
	
	while(boolean){
		switch(printOptions()){
		case 1: //by class number
			printNumber(outputF);
			sort(outputF, cls, number, length);
			break;
		case 2: //by day
			//printDay(outputF);
			switch(printOptionsDay()){
				case 1: //MWF
					sort(outputF, cls, dayMWF, length);
					break;
				case 2: //TR
					sort(outputF, cls, dayTR, length);
					break;
				case 5: //Error + Cancel
					printf("<OpperationCancelled>\n");
					fprintf(outputF, "<OpperationCancelled>\n");
					break;
			}
			break;
		case 3: //by time
			printTime(outputF);
			sort(outputF, cls, time, length);
			break;
		case 4: //by class level
			sort(outputF, cls, year, length);
			break;
		case 5: //quit
			printf("---Quit---Quit---Quit---\n");
			boolean = false;
			break;
		}
	}
	
	fprintf(outputF, "<end>");
	fclose(outputF);
}

//
// main
//

int main(void){
	getClasses();
	return 0;
}