#include <stdio.h>
#include <string.h>
#include "header.h"

/**
* Prompts the user, writes to file, calls function to read file, switches based on user input and exits on user input error or quit
* Responsible for code running in propper order
*/
void promptUser(classes_t cls[], int length){
	FILE *outputF;
	outputF = fopen("classOut.txt", "w");
	fprintf(outputF, "CSCI Courses\n\n");
	printf("CSCI Courses\n");
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