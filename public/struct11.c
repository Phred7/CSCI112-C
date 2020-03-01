#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc
#include "student.h"   // local header file that defines student data structure

typedef enum {false, true} Bool;

Bool student_equal(student_t st1, student_t st2) {
	// compare each element of the structure
	return (strcmp(st1.name, st2.name) == 0 &&
		st1.id == st2.id &&
                st1.credits == st2.credits);
}

student_t student_scan() {
    char first[50], last[50];

    student_t stdnt;

    printf("Read in information for student (first, last, id, credits, year): \n"); 
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

int main() {

    Bool equals;

    // able to return a data structure 
    student_t st1 = student_scan();
    student_t st2 = student_scan();

    // cannot test for equality using the = operator
    equals = student_equal(st1, st2);
    if (equals) {
	    printf("student1 and student2 match\n");
    }
    else {
	    printf("student1 and student2 do not match\n");
    }

    return(0);
}


