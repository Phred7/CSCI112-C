//practice and notes for Exam I

#include <stdio.h>

int main(void){
	
	int x = 10; //some var
	int condition  = 0; //used as a boolean
	//int *p = &condition; //pointer
	
	do{
		//insert stuff and things
		if((x = 30)){ //will always be true because it is setting x = to 30 then checking to see if they are the same
			condition = 1;
			printf("x = 30\n");
		}else{ //yeah this should never happen
			condition = 0;
			printf("x != 30\n");
		}
	}while(condition != 1); //checks condition after running through the loop atleast once
		
		printf("condition is %s\n", (condition != 1? "false" : "true"));
		
	return 0;
}