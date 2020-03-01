#include <stdio.h>
#include <string.h>

typedef struct {
	char number[80];
	char name[80];
	char days[80];
	char time[80];
	int year;
} classes_t;

void parseLine(classes_t* class, char* line){
	char *result;
	char copyLine[81];
	strcpy(copyLine, line);
	result = strtok(copyLine, " ");
	sscanf(result, "%s", class->number);
	printf("%s", class->number);
	return;
}

void getClasses(){
	char ch;
	char line[81];
	int linecount;
	int i = 0;
	FILE* inputF = fopen("classes.txt", "r");
	
	while ((ch=getc(inputF)) != EOF) {
		if (ch == '\n') { 
			++linecount; 
		}
	}
	classes_t clsArray[linecount];
	printf("linecount: %d", linecount);
	while(fgets(line, 80, inputF) != NULL){
		parseLine(&clsArray[i], line);
		i++;
	}
	printf("%s", clsArray[0].number); 
	return;
}

int main(void){
	getClasses();
	return 0;
}