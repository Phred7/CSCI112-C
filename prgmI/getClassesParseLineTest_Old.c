#include <stdio.h>
#include <string.h>
#include "header.h"

void parseLine(classes_t cls[], char read[], int i);
void getClasses();
void sort(FILE *out, classes_t cls[], char* type, int length);
int printOptions();
int printOptionsDay();
void printClass(FILE *out, classes_t cls[], int index);
void printDayType(FILE *out, char* type);
void printDay(FILE *out);
void printName(FILE *out);
void printTime(FILE *out);
void printNumber(FILE *out);
void promptUser(classes_t cls[], int length);

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
	char dayMWF[] = "mwf";
	char dayTR[] = "tr";
	classes_t temp;
	
	for(i = 0; i < len; i++){
		for(j = i; j < len; j++){
			if(strcmp(type, number) == 0){ //sort by number
				swap = strcmp(cls[i].number, cls[j].number);
			} else if(strcmp(type, time) == 0){ //sort by time of day
				swap = strcmp(cls[i].time, cls[j].time);
			} else if(strcmp(type, dayMWF) == 0){ //sort by MWF
				swap = strcmp(cls[i].days, cls[j].days);
			} else if(strcmp(type, dayTR) == 0){ //sort by TR
				swap = strcmp(cls[i].days, cls[j].days);
			} else if(strcmp(type, year) == 0){ //sort by year
				swap = (cls[i].year > cls[j].year ? 1 : 0);
			}
			
			if(swap > 0){ //swaps locations if necessary to sort
				temp = cls[i];
				cls[i] = cls[j];
				cls[j] = temp;
			}
		}
	}
	/*
	if(strcmp(type, day) == 0){
		if(answer == 0){
			printf("Choose your day combo:\n1. MWF\n2. TR\n");
			scanf("%d", &answer);
			i = 0;
			if(answer == 1){
				while(strcmp(mwf, cls[i].days) == 0){
					i++;
				}
				printf("while 1 ran without error");
				classes_t tempD[i];
				while(strcmp(mwf, cls[i].days) == 0){
					tempD[i] = cls[i];
				}
				printf("while 2 ran without error");
				sort(out, tempD, number);
				printf("recursive sort ran without error");
			}else if(answer == 2){
				while(strcmp(tr, cls[i].days) == 0){
					i++;
				}
				classes_t tempD[i];
				while(strcmp(tr, cls[i].days) == 0){
					tempD[i] = cls[i];
				}
				sort(out, tempD, number);
			}else{
				printf("User Input Error:\n");
				fprintf(out, "User Input Error:\n");
			}
		}else{
			printClass(out, cls, i);
			answer = 0;
		}		
	}else{
		
	}*/
	/*
	if(strcmp(type, day) == 0){
		int answer = 0;
		i = 0;
		printf("Choose your day combo:\n1. MWF\n2. TR\n");
		scanf("%d", &answer);
		if(answer == 1){
			while(strcmp(mwf, cls[i].days) == 0){
				printClass(out, cls, i);
				i++;
			}
		}else if(answer == 2){
			for(i = 0; i < 15; i++){
				if(strcmp(tr, cls[i].days) == 0){
					printClass(out, cls, i);
				}
			}
		}else{
			printf("User Input Error:\n");
			fprintf(out, "User Input Error:\n");
		}*/
		
	/*if(strcmp(type, day) == 0){
		if(answer == 0){
			printf("Choose your day combo:\n1. MWF\n2. TR\n");
			scanf("%d", &answer);
			i = 0;
			if(answer == 1){
				while(strcmp(mwf, cls[i].days) == 0){
					i++;
				}
				classes_t temp[i];
				while(strcmp(mwf, cls[i].days) == 0){
					temp[i] = cls[i];
				}
				sort(out, temp, day);
			}else if(answer == 2){
				while(strcmp(tr, cls[i].days) == 0){
					i++;
				}
				classes_t temp[i];
				while(strcmp(tr, cls[i].days) == 0){
					temp[i] = cls[i];
				}
				sort(out, temp, day);
			}else{
				printf("User Input Error:\n");
				fprintf(out, "User Input Error:\n");
			}
		}else{
			printClass(out, cls, i);
			answer = 0;
		}		
	}else{
		
	}*/
	
	/*if((strcmp(type, dayMWF) == 0) || (strcmp(type, dayTR) == 0)){
		for(i = 0; i < len; i++){
			j = i + 1;
			if((strcmp(type, dayMWF) == 0) && (strcmp(dayMWF, cls[i].days) == 0)){
				if(strcmp(cls[i].time, cls[j].time) != 0){
					temp = cls[i];
					cls[i] = cls[j];
					cls[j] = temp;
				}
				printClass(out, cls, i);
			}else if((strcmp(type, dayTR) == 0) && (strcmp(dayTR, cls[i].days) == 0)){
				if(strcmp(cls[i].time, cls[j].time) != 0){
					temp = cls[i];
					cls[i] = cls[j];
					cls[j] = temp;
				}
				printClass(out, cls, i);
			}
		}
	} else{
		for(i = 0; i < len; i++){
			printClass(out, cls, i);
		}
	}*/
	
	for(i = 0; i < len; i++){
			printClass(out, cls, i);
		}
	fprintf(out, "\n");
}

//
// prints
//

int printOptions(){
	int answer = 0;
	Bool valid = false;
	//printf("\nxxxTESTxxx\n\n");
	
	while(!valid){
		printf("Options:\n1. Print all Classes\n2. Print classes by given day combo\n3. Print classes by time of day\n4. Print classes by class level\n5. Quit\n");
		scanf("%d", &answer);
		if(answer < 1 || answer >= 6){
			valid = true;
			answer = 5;
			printf("User Input Error:\n");
			//valid = false;
			//printf("Error: Please enter a valid integer\n");
		}else{
			valid = true;
		}
	}
	return answer;
}


int printOptionsDay(){
	int answer = 0;
	
	printf("Choose your day combo:\n1. MWF\n2. TR\nOther to Cancel");
	scanf("%d", &answer);
	if(answer < 1 || answer > 2){
		answer = 5;
	}
	
	return answer;
}

void printClass(FILE *out, classes_t cls[], int index){
	fprintf(out, "%-47s", cls[index].name);
	fprintf(out, "%s ", cls[index].number);
	if(cls[index].year == 1){
		fprintf(out, "Freshman ");
	} else if(cls[index].year == 2){
		fprintf(out, "Sophmore ");
	} else if(cls[index].year == 3){
		fprintf(out, "Junior\t");
	} else{
		fprintf(out, "Senior\t");
	}
	fprintf(out, "%s ", cls[index].days);
	fprintf(out, "%s\n", cls[index].time);
}

void printNumber(FILE *out){
	fprintf(out, "List of all classes:\n");
	return;
}

void printDay(FILE *out){
	fprintf(out, "Classes Sorted By Specific Day:\n");
	return;
}

void printTime(FILE *out){
	fprintf(out, "Classes Sorted By Time of Day:\n");
	return;
}

void printLevel(FILE *out){
	fprintf(out, "Classes Sorted By Class Level:\n");
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
	char dayMWF[] = "mwf";
	char dayTR[] = "tr";
	Bool boolean = true;
	
	while(boolean){
		switch(printOptions()){
		case 1: //by class number
			printNumber(outputF);
			sort(outputF, cls, number, length);
			break;
		case 2: //by day
			printDay(outputF);
			switch(printOptionsDay()){
				case 1: //MWF
					sort(outputF, cls, dayMWF, length);
					break;
				case 2: //TR
					sort(outputF, cls, dayTR, length);
					break;
				case 5: //Error + Cancel
					printf("<OpperationCancelled>\n");
					fprintf(outputF, "<OpperationCancelled>n");
					break;
			}
			break;
		case 3: //by time
			printTime(outputF);
			sort(outputF, cls, time, length);
			break;
		case 4: //by class level
			printLevel(outputF);
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