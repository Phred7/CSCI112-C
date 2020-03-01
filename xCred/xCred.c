#include <stdio.h>
#include <string.h>
#include "header.h"

/**
* Prints the addresses to the terminal and an output file
* If one of the addresses == 0.0.0.0 it will not print it and will terminate printing the rest of the ip's
*/
void printAddresses(FILE *out, address_t ip[], int length){
	int i;
	
	for(i = 0; i < length; i++){
		
		if((ip[i].ipA == 0) && (ip[i].ipB == 0) && (ip[i].ipB == 0) && (ip[i].ipB == 0)){
			break;
		}else{
			fprintf(out, "%d.%d.%d.%-8d%s\n", ip[i].ipA, ip[i].ipB, ip[i].ipC, ip[i].ipD, ip[i].name); 
			printf("%d.%d.%d.%-8d%s\n", ip[i].ipA, ip[i].ipB, ip[i].ipC, ip[i].ipD, ip[i].name); 
		}
	}
	fprintf(out, "\n");
	printf("\n");
	
	return;
}


/**
* Compares IP addresses in array to see if they are on the same local network
* If they are it prints a string to the terminal and output file with the names of machines on the same network
* If an IP == 0.0.0.0 the f(x) will halt regardless of the length of the input file
*/
void compare(FILE *out, address_t ip[], int length){
	int i, j;
	
	for(i = 0; i < length; i++){
		if((ip[i].ipA == 0) && (ip[i].ipB == 0) && (ip[i].ipB == 0) && (ip[i].ipB == 0)){
			break;
		}
		for(j = i; j < length; j++){
			if((ip[j].ipA == 0) && (ip[j].ipB == 0) && (ip[j].ipB == 0) && (ip[j].ipB == 0)){
				break;
			}
			if((i != j) && (ip[i].ipA == ip[j].ipA) && (ip[i].ipB == ip[j].ipB)){
				fprintf(out, "Machines %s and %s are on the same local network: %d.%d\n", ip[i].name, ip[j].name, ip[i].ipA, ip[i].ipB);
				printf("Machines %s and %s are on the same local network: %d.%d\n", ip[i].name, ip[j].name, ip[i].ipA, ip[i].ipB);
			}else{
				
			}
		}
	}
	return;
}

/**
* Takes in a line from an input file, an array of ip addresses and an index
* Cuts the file line up with strtok and put necessary data into a specific index on the ip array
*/
void parseLine(address_t ip[], char line[], int i){
	char *result;
	
	result = strtok(line, ".");
	sscanf(result, "%d", &ip[i].ipA);
	result = strtok(NULL, ".");
	sscanf(result, "%d", &ip[i].ipB);
	result = strtok(NULL, ".");
	sscanf(result, "%d", &ip[i].ipC);
	result = strtok(NULL, " ");
	sscanf(result, "%d", &ip[i].ipD);	
	result = strtok(NULL, "\n");
	strcpy(ip[i].name, result);
	
	return;	
}

/**
* Reads in ip Adresses at cwd 'ipaddresses.txt'
* Calls other f(x)'s in propper order and opens/closes files as necessary
* Gets input file length and creates array of ipAddresses based on that length
*/
void readFile(){
	int i = 0;
	int linecount = 0;
	char ch;
	char line[81];
	FILE *inputF;
	FILE *outputF;
	inputF = fopen("ipaddresses.txt", "r"); //opens file from defined server directory
	
	while ((ch=getc(inputF)) != EOF) { //this is used to calculate the number of lines in the file
		if (ch == '\n') { 
			++linecount; 
		}
	}
	
	address_t ip[linecount];
	
	fclose(inputF);
	inputF = fopen("ipaddresses.txt", "r");
	
	while(fgets(line, 80, inputF) != NULL){
		parseLine(ip, line, i);
		i++;
	}
	
	fclose(inputF);
	
	outputF = fopen("ipAddressesOut.txt", "w");
	
	fprintf(outputF, "IP Addresses:\n\n");
	printf("IP Addresses:\n\n");
	
	fclose(outputF);
	outputF = fopen("ipAddressesOut.txt", "a");
	
	printAddresses(outputF, ip, linecount);
	compare(outputF, ip, linecount);
	
	fclose(outputF);
	
	return;
}

/**
* This is main... it calls the readFile f(x)... yep thats about it
*/
int main(void){	
	readFile();
	return 0;
}