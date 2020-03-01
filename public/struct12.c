#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc
#include "student.h"   // local header file that defines student data structure

typedef enum {false, true} Bool;

student_t student_scan() {
    char first[50], last[50];

    student_t stdnt;

    printf("Read in information for student: "); 
    // have to use the ()s because both & and * are of same precedence
    // we need * to be handled before &
    // . is a higher precedence than & and *
    scanf("%s %s %d %d %c", 
	       first, last, &stdnt.id, &stdnt.credits,
	       &stdnt.year);
    strcpy(stdnt.name, first);
    strcat(stdnt.name, " ");
    strcat(stdnt.name, last);
    printf("student's name is %s\n", stdnt.name);

    return(stdnt);
}

student_t student_update_credits(student_t st) {
    st.credits += 15;
    return st;
}

int main() {

    // able to return a data structure 
    student_t st1 = student_scan();

    student_t str = student_update_credits(st1);

    printf("address of st1 is %p; address of str is %p\n",
		    &st1, &str);
    printf("address of st1 name is %p; address of str name is %p\n",
		    st1.name, str.name);
    printf("st1 credits are %d; str credits are %d\n",
		    st1.credits, str.credits);

    return(0);
}


