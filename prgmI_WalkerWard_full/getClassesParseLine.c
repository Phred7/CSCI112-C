#include <stdio.h>
#include <string.h>
#include "header.h"

/**
* Take in a line from a given file and cuts it up into pieces
* Send to the classes_t array at a given index
*/
void parseLine(classes_t cls[], char read[], int i){
	char *result;

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

/**
* Opens files (in and out)
* Sends each line to parseLine f(x)
* Writes header to output file, closes and reopens to append 
* Removes previous contents and reopens to make it easier to write more data to the file
* Calls prompUser f(x)
*/
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