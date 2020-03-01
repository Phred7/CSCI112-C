#include <stdio.h>
#include "student_arr.h"   // local header file that defines student data structure

// passing a structure to a function as input
void print_student(student_t student) {

    int j;

    // use the direct component selection operator to print each elment
    printf("\nstudent id: %d\nname: %s\ncredits: %d\nyear: ",
                 student.id, student.name, student.credits);
    switch (student.year) {
    case 'f':
        printf("freshman");
        break;
    case 's':
        printf("sophomore");
        break;
    case 'j':
        printf("junior");
        break;
    case 'r':
        printf("senior");
    }
    // to finish the printed line
    printf("\n");

    // print each class for this student
    for (j = 0; j < 5; ++j) {
            printf("Taking class: %d\n", student.cur_class_nos[j]);
    }
    return;
}

int main() {

    // declaring an array of students
    student_t c112[4] = {
	          {"jane doe", 2, {112, 338, 215, 429, 107}, 45, 's'},
		  {"john smith", 3, {112, 338, 215, 429, 107}, 15, 'f'},
		  {"josephine burdett", 4, {112, 338, 215, 429, 107}, 124, 'r'},
		    {"joe gray", 5, {112, 338, 215, 429, 107}, 110, 'j'}
    };

    int i; // counters

    // walk through the array to print each item
    for (i = 0; i < 4; i++) {
	// passing a structure to a function
        print_student(c112[i]);
    }

    return(0);
}
