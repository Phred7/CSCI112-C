#include <stdio.h>
#include <string.h>
#include "student.h"   // local header file that defines student data structure

typedef enum {false, true} Bool;

Bool student_equal(student_t st1, student_t st2) {
	// compare each element of the structure
	return (strcmp(st1.name, st2.name) == 0 &&
		st1.id == st2.id &&
		st1.id == st2.id &&
                st1.credits == st2.credits);
}

int main() {

    Bool equals;

    // declaring a single student
    student_t mac = {"mary ann cummings", 1, 115, 'j'};
    student_t newst1,
	      newst2;

    newst1 = mac;
    newst2 = mac;
    newst2.id = 2;

    // cannot test for equality using the = operator
    equals = student_equal(mac,newst1);
    if (equals) {
	    printf("mac and newst1 match\n");
    }
    else {
	    printf("mac and newst1 do not match\n");
    }

    equals = student_equal(mac,newst2);
    if (equals) {
            printf("mac and newst2 match\n");
    }
    else {
            printf("mac and newst2 do not match\n");
    }
    return(0);
}


