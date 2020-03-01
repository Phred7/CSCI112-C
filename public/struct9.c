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

void student_scan(student_t *stdnt) {
    char first[50], last[50];

    printf("Read in information for student (first, last, id, credits, yr): "); 
    // have to use the ()s because both & and * are of same precedence
    // we need * to be handled before &
    // . is a higher precedence than & and *
    scanf("%s %s %d %d %c", 
	       first, last, &(*stdnt).id, &(*stdnt).credits,
	       &(*stdnt).year);
    strcpy((*stdnt).name, first);
    strcat((*stdnt).name, " ");
    strcat((*stdnt).name, last);
    printf("student name is %s\n", (*stdnt).name);
    return;
}

int main() {

    Bool equals;

    // Have to declare these before we cann student_scan
    student_t st1, st2;

    student_scan(&st1);
    student_scan(&st2);

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


