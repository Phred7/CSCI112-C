#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* arcv[]){
		
	char input[25];// = //(char*)malloc(sizeof(char) * 27);
	printf("Enter a string less than 25 chardacters long:");
	scanf("%s", input); //dont need the '&' because input is already a pointer
	
	printf("%s starts with the letter %c\n", input, input[0]);
	
	return 0;
}