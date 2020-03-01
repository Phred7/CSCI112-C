#include <stdio.h>

/**
* gets int values from the command line and passes to variable x and prints with index
*/
int main(int arcc, char* argv[]){
	
	int i, x;
	
	for(i = 1; i < arcc; i++){
		sscanf(argv[i], "%d", &x); //passes the value of argv at the specific index to the variable x
		printf("%d: %d\n", i, x);
	}

	return 0;
}
