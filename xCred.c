#include <stdio.h>

void scanAddress(FILE *file, int addresses){
	
}

void printAddress(void){
	
}

int localAddress(int address[], int compare[]){
	int boolean = 0; //false
	return 0;
}

void main(int argc, char* argv[]){
	int size = 20;
	int addresses[size];
	
	FILE *file;
	file = fopen("/public/csci112sp19/lab6/ipaddresses.txt", "r"); //opens file from defined server directory
	
	scanAddress(file, addresses, size); //f(x) call
	fclose(file); //closes the file
	
	//easiest way is probably to use a for loop for that populates an array unlit the end of the loop but then causes issues during the comparison.
	//other way is to generate a certain number of arrays based on the length of the file but that seems too complicated and stupid
	//MAKE the first four indecies of the addresses array = to the respective four digits of the ip. Then have a string array responsible for the local names of the devices!
}